#include <stdio.h>
#include <string.h>
#include "common.h"
#include "db.h"

enum BOOL db_append_record(const RECORD *in_record)
{
    FILE *fp;

    fp = fopen(DBFILE, "ab");
    if (fp == NULL) return FALSE;
    fwrite(in_record, sizeof(RECORD), 1, fp);
    if (ferror(fp)) { fclose(fp); return FALSE; }
    fclose(fp);

    return TRUE;
}

enum BOOL db_find_record_by_id(const unsigned int id, RECORD *out_record)
{
    int i, total;
    enum BOOL found;
    RECORD rec;
    FILE *fp;

    found = FALSE;
    if (db_file_size() == 0 || db_file_size() == DBERROR) return FALSE;
    total = db_total_number_of_records();

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;
    for (i = 0; i < total; i++)
    {
        fread(&rec, sizeof(RECORD), 1, fp);
        if (ferror(fp)) break;
        if (rec.id == id) { found = TRUE; break; }
    }
    fclose(fp);

    if (found == TRUE) memcpy(out_record, &rec, sizeof(RECORD));

    return found;
}

enum BOOL db_read_record_by_index(const int index_in_file, RECORD *out_record)
{
    FILE *fp;

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;
    fseek(fp, index_in_file * sizeof(RECORD), SEEK_SET);
    if (ferror(fp)) { fclose(fp); return FALSE; }
    fread(out_record, sizeof(RECORD), 1, fp);
    if (ferror(fp)) { fclose(fp); return FALSE; }
    fclose(fp);

    return TRUE;
}

// Using int (instead of unsigned int) as return type because DBERROR can be returned.
int db_total_number_of_records()
{
    long filesize;

    filesize = db_file_size();
    if (filesize == DBERROR) return filesize;
    return filesize / sizeof(RECORD);
}

// Using long (instead of unsigned long) as return type because DBERROR can be returned.
long db_file_size()
{
    FILE *fp;
    long filesize;

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return DBERROR;
    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    fclose(fp);

    return filesize;
}

enum BOOL db_delete_record_by_id(const RECORD *to_delete)
{
    FILE *read, *write;
    RECORD record;
    enum BOOL result;
    int i, count;
    long filesize;

    filesize = db_file_size();
    if (filesize == DBERROR || filesize == 0) return FALSE;
    count = db_total_number_of_records();
    if (count == DBERROR || count == 0) return FALSE;

    read = fopen(DBFILE, "rb");
    if (read == NULL) return FALSE;
    write = fopen(TMPFILE, "wb");
    if (write == NULL) { fclose(read); return FALSE; }

    result = TRUE;
    for (i = 0; i < count; i++)
    {
        fread(&record, sizeof(RECORD), 1, read);
        if (ferror(read)) { result = FALSE; break; }
        if (record.id != to_delete->id) {
            fwrite(&record, sizeof(RECORD), 1, write);
            if (ferror(write)) { result = FALSE; break; }
        }
    }

    fclose(read);
    fclose(write);

    if (result == TRUE) {
        if (remove(DBFILE)) return FALSE;
        if (rename(TMPFILE, DBFILE)) return FALSE;
    } else {
        remove(TMPFILE);
    }

    return result;
}

// The record ID must remain same to update that record.
enum BOOL db_update_record_by_id(const RECORD *updated_record)
{
    FILE *fp;
    RECORD record;
    int i, total;
    long position;
    enum BOOL result;

    if (db_file_size() == 0 || db_file_size() == DBERROR) return FALSE;
    total = db_total_number_of_records();
    
    fp = fopen(DBFILE, "r+b");
    if (fp == NULL) return FALSE;
    
    result = FALSE;
    for (i = 0; i < total; i++)
    {
        position = ftell(fp);
        fread(&record, sizeof(RECORD), 1, fp);
        if (ferror(fp)) break;

        if (record.id == updated_record->id) {
            fseek(fp, position, SEEK_SET);
            if (ferror(fp)) break;
            fwrite(updated_record, sizeof(RECORD), 1, fp);
            if (ferror(fp)) break;
            result = TRUE;
            break;
        }
    }

    fclose(fp);
    return result;
}

enum BOOL db_get_new_unique_id(unsigned int *out_new_id)
{
    FILE *fp;
    RECORD record;
    int i, total;
    unsigned int highest_id;
    long filesize;

    highest_id = 0;
    filesize = db_file_size();
    if (filesize == 0 || filesize == DBERROR) { *out_new_id = 1; return TRUE; }
    total = db_total_number_of_records();

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;

    for (i = 0; i < total; i++)
    {
        fread(&record, sizeof(RECORD), 1, fp);
        if (ferror(fp)) { fclose(fp); return FALSE; }
        if (record.id > highest_id) highest_id = record.id;
    }

    fclose(fp);
    *out_new_id = highest_id + 1;

    return TRUE;
}

// out_array should be large enough to store all records found.
// out_count is the number of records found with matching criteria.
enum BOOL db_find_record_by_name(const char *partial_name, RECORD *out_array, int *out_count)
{
    int i, total;
    enum BOOL found;
    RECORD record, record_lowercase, tofind;
    FILE *fp;

    found = FALSE;
    *out_count = 0;
    if (db_file_size() == 0 || db_file_size() == DBERROR) return FALSE;
    total = db_total_number_of_records();
    strcpy(tofind.name, partial_name);
    _strlwr(tofind.name);

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;
    for (i = 0; i < total; i++)
    {
        fread(&record, sizeof(RECORD), 1, fp);
        if (ferror(fp)) { fclose(fp); return FALSE; }
        memcpy(&record_lowercase, &record, sizeof(RECORD));
        _strlwr(record_lowercase.name);
        if (strstr(record_lowercase.name, tofind.name)) { 
            found = TRUE;
            memcpy(&out_array[*out_count], &record, sizeof(RECORD));
            *out_count += 1;
        }
    }
    fclose(fp);

    return found;
}

// out_array should be large enough to store all records found.
// out_count is the number of records found with matching criteria.
enum BOOL db_find_record_by_phone_number(const char *partial_phone_number, RECORD *out_array, int *out_count)
{
    int i, total;
    enum BOOL found;
    RECORD record;
    FILE *fp;

    found = FALSE;
    *out_count = 0;
    if (db_file_size() == 0 || db_file_size() == DBERROR) return FALSE;
    total = db_total_number_of_records();

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;
    for (i = 0; i < total; i++)
    {
        fread(&record, sizeof(RECORD), 1, fp);
        if (ferror(fp)) { fclose(fp); return FALSE; }
        if (strstr(record.phone, partial_phone_number)) { 
            found = TRUE;
            memcpy(&out_array[*out_count], &record, sizeof(RECORD));
            *out_count += 1;
        }
    }
    fclose(fp);

    return found;
}

// The partial_address will be searched in both RECORD.address1 and RECORD.address2
// out_array should be large enough to store all records found.
// out_count is the number of records found with matching criteria.
enum BOOL db_find_record_by_address(const char *partial_address, RECORD *out_array, int *out_count)
{
    int i, total;
    enum BOOL found;
    RECORD record, record_lowercase, tofind;
    FILE *fp;

    found = FALSE;
    *out_count = 0;
    if (db_file_size() == 0 || db_file_size() == DBERROR) return FALSE;
    total = db_total_number_of_records();
    strcpy(tofind.address1, partial_address);
    _strlwr(tofind.address1);

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;
    for (i = 0; i < total; i++)
    {
        fread(&record, sizeof(RECORD), 1, fp);
        if (ferror(fp)) { fclose(fp); return FALSE; }
        memcpy(&record_lowercase, &record, sizeof(RECORD));
        _strlwr(record_lowercase.address1);
        _strlwr(record_lowercase.address2);
        if (strstr(record_lowercase.address1, tofind.address1) || 
            strstr(record_lowercase.address2, tofind.address1)) 
        { 
            found = TRUE;
            memcpy(&out_array[*out_count], &record, sizeof(RECORD));
            *out_count += 1;
        }
    }
    fclose(fp);

    return found;
}

// out_array should be large enough to store all records found.
// out_count is the number of records found with matching criteria.
enum BOOL db_find_record_by_notes(const char *partial_notes, RECORD *out_array, int *out_count)
{
    int i, total;
    enum BOOL found;
    RECORD record, record_lowercase, tofind;
    FILE *fp;

    found = FALSE;
    *out_count = 0;
    if (db_file_size() == 0 || db_file_size() == DBERROR) return FALSE;
    total = db_total_number_of_records();
    strcpy(tofind.notes, partial_notes);
    _strlwr(tofind.notes);

    fp = fopen(DBFILE, "rb");
    if (fp == NULL) return FALSE;
    for (i = 0; i < total; i++)
    {
        fread(&record, sizeof(RECORD), 1, fp);
        if (ferror(fp)) { fclose(fp); return FALSE; }
        memcpy(&record_lowercase, &record, sizeof(RECORD));
        _strlwr(record_lowercase.notes);
        if (strstr(record_lowercase.notes, tofind.notes)) { 
            found = TRUE;
            memcpy(&out_array[*out_count], &record, sizeof(RECORD));
            *out_count += 1;
        }
    }
    fclose(fp);

    return found;
}

// out_database_filename should be at least 13 characters long array
void db_filename(char *out_database_filename)
{
    strcpy(out_database_filename, DBFILE);
}
