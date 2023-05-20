#include <stdio.h>
#include <stdlib.h>
#include "HT_functions.h"
#include "functions.h"

int main() {
    system("cls");

    char action;
    HT *table = NULL;
    char *city = NULL;
    int population;
    int size = CAPACITY;

    table = init_table(table, size);

    while (1) {
        fflush(stdin);

        system("cls");

        puts("Menu:\n"
             "1 - add\n"
             "2 - remove\n"
             "3 - list\n"
             "4 - quit");

        scanf("%s", &action);

        fflush(stdin);

        switch (action) {
            case '1':
                puts("Enter city's name");
                city = input_string(city);
                fflush(stdin);
                puts("Enter city's population");

                scanf("%d", &population);

                add_city_to_HT(table, city, population);
                puts("The city is in the table! Input smth to continue");
                fflush(stdin);
                getchar();
                break;
            case '2':
                puts("Enter city's name");
                city = input_string(city);
                fflush(stdin);
                remove_city_from_HT(table, city);
                puts("Input smth to continue");
                fflush(stdin);
                getchar();
                break;
            case '3':
                puts("DataBase:");
                show_list_of_cities(table);
                puts("Input smth to continue");
                fflush(stdin);
                getchar();
                break;
            case '4':
                delete_cities(table);
                exit(0);
            default:
                puts("No such command\n"
                     "Input smth to continue");
                fflush(stdin);
                getchar();
                break;
        }
        fflush(stdin);
    }
}

