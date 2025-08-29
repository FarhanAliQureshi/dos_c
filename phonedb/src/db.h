#ifndef DB_H
#define DB_H

#include "common.h"

#define DBFILE      "PHONEDB.DAT"
#define TMPFILE     "PHONEDB.NEW"
#define DBERROR     -1
#define FILEERROR   -1

struct directory_entry {
    unsigned int id;
    // One additional byte in each of following fields for NUL character.
    char name[31];
    char phone[21];
    char address1[41];
    char address2[41];
    char notes[61];
};
typedef struct directory_entry RECORD;

enum BOOL db_append_record(const RECORD *in_record);
enum BOOL db_find_record_by_id(const unsigned int id, RECORD *out_record);
enum BOOL db_read_record_by_index(const int index_in_file, RECORD *out_record);
int db_total_number_of_records();
long db_file_size();
enum BOOL db_delete_record_by_id(const RECORD *to_delete);
enum BOOL db_update_record_by_id(const RECORD *updated_record);
enum BOOL db_get_new_unique_id(unsigned int *out_new_id);
enum BOOL db_find_record_by_name(const char *partial_name, RECORD *out_array, int *out_count);
enum BOOL db_find_record_by_phone_number(const char *partial_phone_number, RECORD *out_array, int *out_count);
enum BOOL db_find_record_by_address(const char *partial_address, RECORD *out_array, int *out_count);
enum BOOL db_find_record_by_notes(const char *partial_notes, RECORD *out_array, int *out_count);
void db_filename(char *out_database_filename);

#endif
