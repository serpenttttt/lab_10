#include "HT_functions.h"

HT *init_table(HT *table, int size) {

    table = (HT *) malloc(sizeof (HT));
    table->size = size;
    table->count_of_elements = 0;
    table->cities = (City **) calloc(table->size, sizeof (City*));
    for (int i = 0; i < table->size; ++i) {
        table->cities[i] = NULL;
    }

    return table;
}

City *create_city(char *city, int population) {
    City *new_city = (City *) malloc(sizeof (City *));
    new_city->city = (char *) malloc(strlen(city) + 1);
    new_city->next = NULL;
    //new_city->population = malloc(sizeof(int));

    new_city->city = strcpy(new_city->city, city);
    new_city->population = population;

    return new_city;
}

int make_hash(char *city) {
    int hash_value = 0;
    for (int i = 0; city[i]; ++i) {
        hash_value += city[i];
    }
    return hash_value % CAPACITY;
}

void delete_city(City *delete_city) {
    free(delete_city->city);
    free(delete_city);
}

void delete_cities(HT* table) {
    for (int i = 0; i<table->size; i++) {
        City *new_city = table->cities[i];
        if (new_city != NULL)
            delete_city(new_city);
    }

    free(table->cities);
    free(table);
}

void collision(HT *table, int index, City *new_city) {

    while(table->cities[index]->next != NULL) {
        table->cities[index]->next = table->cities[index]->next->next;
    }
    table->cities[index]->next = (City *) malloc(sizeof (City));
    table->cities[index]->next = new_city;
}

HT *add_city_to_HT(HT* table, char *city, int population) {
    City *new_city = create_city(city, population);

    int index = make_hash(city);

    City* current_city = table->cities[index];

    if (current_city == NULL) {
        if (table->count_of_elements == table->size) {
            puts("There is no space in HashTable");
            delete_city(new_city);
            return table;
        }

        table->cities[index] = new_city;
        table->count_of_elements++;
    } else {
        if (strcmp(current_city->city, city) == 0) {
            table->cities[index]->population = population;
            return table;
        }
        else {
            collision(table, index, new_city);
            return table;
        }
    }
    return table;
}

void remove_city_from_HT(HT *table, char *city) {
    int index = make_hash(city);
    //если город находится в начале списка
    if (table->cities[index] == NULL){
        puts("The city doesn't exist");
        return;
    }
    if (strcmp(table->cities[index]->city, city) == 0) {
        //если ссылается на нулл, то просто делит
        if (table->cities[index]->next == NULL) {
            delete_city(table->cities[index]);
            table->cities[index] = NULL;
            puts("The city has been deleted!");
        } else { //если есть связный список

            City *temp = table->cities[index]->next;

            delete_city(table->cities[index]);

            table->cities[index] = temp;

            puts("The city has been deleted!");

        }
        // поиск в связном списке города, если его нет в начале списка
    } else {
        while (table->cities[index]->next != NULL && strcmp(table->cities[index]->next->city, city) != 0) {
            table->cities[index] = table->cities[index]->next;
        }
        if (table->cities[index]->next == NULL) {
            puts("No such city");
            return;
        }
        City *temp = table->cities[index]->next->next;
        delete_city(table->cities[index]->next);
        table->cities[index]->next = temp;
        puts("The city has been deleted!");
    }
}

void show_list_of_cities(HT *table) {
    puts("\n<-------------------------------------------->");

    for (int i = 0; i<CAPACITY; ++i) {
        if (table->cities[i] != NULL) {
            printf("City: %s\t|\tPopulation: %d\n", table->cities[i]->city, table->cities[i]->population);


            if (table->cities[i]->next != NULL) {
                City *current_city = table->cities[i]->next;
                while (current_city != NULL) {
                    printf("City: %s\t|\tPopulation: %d\n", current_city->city, current_city->population);
                    current_city = current_city->next;
                }
            } else
                continue;
        }
    }

    puts("<-------------------------------------------->\n");
}