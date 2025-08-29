#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "query.h"
#include "db.h"

void print_records_table(int count, RECORD *array);

void query_id()
{
    RECORD record;
    char buffer[81];
    unsigned int id;

    clearscreen();
    printf("Search Record by ID\n\n");
    printf("NOTE: Enter exact Record ID\n\n");
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
    press_any_key_to_continue();
}

void query_name()
{
    RECORD *array;
    char buffer[81];
    int total, count;

    clearscreen();
    printf("Search by Name\n\n");

    total = db_total_number_of_records();
    if (total == DBERROR || total == 0) {
        printf("Error reading database or database is empty.\n");
        press_any_key_to_continue();
        return;
    }
    array = (RECORD*)malloc(sizeof(RECORD) * total);
    if (array == NULL) {
        printf("Error! Out of memory.\n");
        press_any_key_to_continue();
        return;
    }

    printf("NOTE: You can enter partial name to find all matching records.\n");
    printf("NOTE: Search is case-insensitive.\n\n");
    printf("Enter Search Criteria: "); fflush(stdout);
    turn_on_cursor();
    gets(buffer); buffer[80] = 0x00;
    turn_off_cursor();

    if (db_find_record_by_name(buffer, array, &count) == FALSE) {
        printf("\nError reading record or record not found.\n");
        press_any_key_to_continue();
        free(array);
        return;
    }

    if (count == 0) {
        printf("\nNo record found matching criteria.\n");
    } else {
        printf("\n");
        print_records_table(count, array);
    }
    
    free(array);
    press_any_key_to_continue();
}

void query_phone_number()
{
    RECORD *array;
    char buffer[81];
    int total, count;

    clearscreen();
    printf("Search by Telephone Number\n\n");

    total = db_total_number_of_records();
    if (total == DBERROR || total == 0) {
        printf("Error reading database or database is empty.\n");
        press_any_key_to_continue();
        return;
    }
    array = (RECORD*)malloc(sizeof(RECORD) * total);
    if (array == NULL) {
        printf("Error! Out of memory.\n");
        press_any_key_to_continue();
        return;
    }

    printf("NOTE: You can enter partial phone number to find all matching records.\n\n");
    printf("Enter Search Criteria: "); fflush(stdout);
    turn_on_cursor();
    gets(buffer); buffer[80] = 0x00;
    turn_off_cursor();

    if (db_find_record_by_phone_number(buffer, array, &count) == FALSE) {
        printf("\nError reading record or record not found.\n");
        press_any_key_to_continue();
        free(array);
        return;
    }

    if (count == 0) {
        printf("\nNo record found matching criteria.\n");
    } else {
        printf("\n");
        print_records_table(count, array);
    }
    
    free(array);
    press_any_key_to_continue();    
}

void query_address()
{
    RECORD *array;
    char buffer[81];
    int total, count;

    clearscreen();
    printf("Search by Address\n\n");

    total = db_total_number_of_records();
    if (total == DBERROR || total == 0) {
        printf("Error reading database or database is empty.\n");
        press_any_key_to_continue();
        return;
    }
    array = (RECORD*)malloc(sizeof(RECORD) * total);
    if (array == NULL) {
        printf("Error! Out of memory.\n");
        press_any_key_to_continue();
        return;
    }

    printf("NOTE: You can enter partial address to find all matching records.\n");
    printf("NOTE: Search will look into both Address Line 1 and Address Line 2.\n");
    printf("NOTE: Search is case-insensitive.\n\n");
    printf("Enter Search Criteria: "); fflush(stdout);
    turn_on_cursor();
    gets(buffer); buffer[80] = 0x00;
    turn_off_cursor();

    if (db_find_record_by_address(buffer, array, &count) == FALSE) {
        printf("\nError reading record or record not found.\n");
        press_any_key_to_continue();
        free(array);
        return;
    }

    if (count == 0) {
        printf("\nNo record found matching criteria.\n");
    } else {
        printf("\n");
        print_records_table(count, array);
    }
    
    free(array);
    press_any_key_to_continue();
}

void query_notes()
{
    RECORD *array;
    char buffer[81];
    int total, count;

    clearscreen();
    printf("Search by Notes\n\n");

    total = db_total_number_of_records();
    if (total == DBERROR || total == 0) {
        printf("Error reading database or database is empty.\n");
        press_any_key_to_continue();
        return;
    }
    array = (RECORD*)malloc(sizeof(RECORD) * total);
    if (array == NULL) {
        printf("Error! Out of memory.\n");
        press_any_key_to_continue();
        return;
    }

    printf("NOTE: You can enter partial notes to find all matching records.\n");
    printf("NOTE: Search is case-insensitive.\n\n");
    printf("Enter Search Criteria: "); fflush(stdout);
    turn_on_cursor();
    gets(buffer); buffer[80] = 0x00;
    turn_off_cursor();

    if (db_find_record_by_notes(buffer, array, &count) == FALSE) {
        printf("\nError reading record or record not found.\n");
        press_any_key_to_continue();
        free(array);
        return;
    }

    if (count == 0) {
        printf("\nNo record found matching criteria.\n");
    } else {
        printf("\n");
        print_records_table(count, array);
    }
    
    free(array);
    press_any_key_to_continue();
}

void print_record(RECORD *record)
{
    printf("Record ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Telephone Number: %s\n", record->phone);
    printf("Address Line 1: %s\n", record->address1);
    printf("Address Line 2: %s\n", record->address2);
    printf("Notes: %s\n", record->notes);
}

void print_records_table(int count, RECORD *array)
{
    int i;

    printf("Total Records Found: %d\n\n", count);
    printf("ID    Name                           Telephone Number\n");
    printf("----- ------------------------------ --------------------\n");
    for (i = 0; i < count; i++) {
        printf("%5u %-30s %-20s\n", array[i].id, array[i].name, array[i].phone);
    }
}
