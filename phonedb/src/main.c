/*

    PROJECT: TELEPHONE DIRECTORY DATABASE
    PROGRAMMER: FARHAN ALI QURESHI

*/

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include "common.h"
#include "kbinput.h"
#include "db.h"
#include "query.h"

void add_record();
void edit_record();
void delete_record();
void database_info();
void get_user_input_record(RECORD *record);

int main(void)
{
    char keys[11];
    int choice;

    _clearscreen(_GCLEARSCREEN);
    strcpy(keys, "0123456789");

    while (TRUE)
    {
        // Clear screen and switch off cursor.
        turn_off_cursor();
        clearscreen();

        // Display main menu.
        printf("Telephone Directory\n");
        printf("Program by Farhan Ali Qureshi\n\n");
        printf("(1) Add Record\n");
        printf("(2) Edit Record\n");
        printf("(3) Delete Record\n");
        printf("(4) Search by ID\n");
        printf("(5) Search by Name\n");
        printf("(6) Search by Telephone Number\n");
        printf("(7) Search by Address\n");
        printf("(8) Search by Notes\n");
        printf("(9) Database Information\n");
        printf("(0) Exit\n");

        choice = wait_for_key_from_list(keys);

        if (choice == '0') break;
        if (choice == '1') add_record();
        if (choice == '2') edit_record();
        if (choice == '3') delete_record();
        if (choice == '4') query_id();
        if (choice == '5') query_name();
        if (choice == '6') query_phone_number();
        if (choice == '7') query_address();
        if (choice == '8') query_notes();
        if (choice == '9') database_info();
    }

    // Clear screen and switch on cursor.
    _clearscreen(_GCLEARSCREEN);
    turn_on_cursor();

    return 0;
}

void add_record()
{
    RECORD record;

    memset(&record, 0x00, sizeof(RECORD));
    db_get_new_unique_id(&record.id);
    
    clearscreen();
    printf("Add New Record\n\n");
    get_user_input_record(&record);

    if (ask_yesno_question("\nDo you wish to add this record? (Y/N)") == TRUE) {
        if (db_append_record(&record) == TRUE) {
            printf("\n\nRecord added.\n");
            press_any_key_to_continue();
        } else {
            printf("\n\nError adding new record.\n");
            press_any_key_to_continue();
        }
    }
}

void edit_record()
{
    RECORD record, updated;
    char buffer[81];
    unsigned int id;

    memset(&updated, 0x00, sizeof(RECORD));

    clearscreen();
    printf("Edit Record\n\n");
    printf("Enter Record ID: "); fflush(stdout);
    turn_on_cursor();
    gets(buffer); buffer[80] = 0x00;
    turn_off_cursor();
    id = atoi(buffer);
    if (db_find_record_by_id(id, &record) == FALSE) {
        printf("\nError reading record or record not found.\n");
        press_any_key_to_continue();
        return;
    }

    printf("\n");
    print_record(&record);
    printf("\nNOTE: Enter '=' (without quotes) to keep that field unchanged.\n");
    updated.id = record.id;
    get_user_input_record(&updated);

    if (strcmp(updated.name, "=") == 0) strcpy(updated.name, record.name);
    if (strcmp(updated.phone, "=") == 0) strcpy(updated.phone, record.phone);
    if (strcmp(updated.address1, "=") == 0) strcpy(updated.address1, record.address1);
    if (strcmp(updated.address2, "=") == 0) strcpy(updated.address2, record.address2);
    if (strcmp(updated.notes, "=") == 0) strcpy(updated.notes, record.notes);

    if (ask_yesno_question("\nDo you wish to save changes to this record? (Y/N)") == TRUE) {
        if (db_update_record_by_id(&updated) == TRUE) {
            printf("\n\nRecord updated.\n");
            press_any_key_to_continue();
        } else {
            printf("\n\nError updating the record.\n");
            press_any_key_to_continue();
        }
    }    
}

void delete_record()
{
    RECORD record;
    char buffer[81];
    unsigned int id;

    clearscreen();
    printf("Delete Record\n\n");
    printf("Enter Record ID: "); fflush(stdout);
    turn_on_cursor();
    gets(buffer); buffer[80] = 0x00;
    turn_off_cursor();
    id = atoi(buffer);
    if (db_find_record_by_id(id, &record) == FALSE) {
        printf("\nError reading record or record not found.\n");
        press_any_key_to_continue();
        return;
    }

    printf("\n");
    print_record(&record);

    if (ask_yesno_question("\nDo you wish to delete this record? (Y/N)") == TRUE) {
        if (db_delete_record_by_id(&record) == TRUE) {
            printf("\n\nRecord deleted.\n");
            press_any_key_to_continue();
        } else {
            printf("\n\nError deleting the record.\n");
            press_any_key_to_continue();
        }
    }    
}

void database_info()
{
    char filename[13];
    long filesize;
    int total_records;

    _clearscreen(_GCLEARSCREEN);
    filesize = db_file_size();
    total_records = db_total_number_of_records();
    db_filename(&filename);
    
    printf("Database Information\n\n");
    printf("Database Filename: %s\n", filename);

    if (filesize == DBERROR)
        printf("Database Filesize: Empty or Error Reading\n", filesize);
    else
        printf("Database Filesize: %ld bytes\n", filesize);

    if (total_records == DBERROR)
        printf("Total Number of Records: Empty or Error Reading\n", total_records);
    else
        printf("Total Number of Records: %d\n", total_records);

    press_any_key_to_continue();
}

void get_user_input_record(RECORD *record)
{
    turn_on_cursor();
    printf("NOTE: Numbers written in brackets [] are the maximum characters allowed.\n\n");
    printf("Record ID: %d\n", record->id);

    printf("Name [30]: "); 
    fflush(stdout); 
    gets(record->name); 
    record->name[30] = 0x00;

    printf("Telephone Number [20]: "); 
    fflush(stdout); 
    gets(record->phone); 
    record->phone[20] = 0x00;

    printf("Address Line 1 [40]: "); 
    fflush(stdout); 
    gets(record->address1); 
    record->address1[40] = 0x00;

    printf("Address Line 2 [40]: "); 
    fflush(stdout); 
    gets(record->address2); 
    record->address2[40] = 0x00;

    printf("Notes [60]: "); 
    fflush(stdout); 
    gets(record->notes); 
    record->notes[60] = 0x00;

    turn_off_cursor();
}
