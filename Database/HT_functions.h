#ifndef LAB_10_HT_FUNCTIONS_H
#define LAB_10_HT_FUNCTIONS_H

#include "HT.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CAPACITY 50000

HT *init_table(HT *table, int size);

City *create_city(char *city, int population);

HT *add_city_to_HT(HT* table, char *city, int population);

void delete_city(City *new_city);

void delete_cities(HT* table);

void remove_city_from_HT(HT *table, char *city);

void show_list_of_cities(HT *table);

#endif //LAB_10_HT_FUNCTIONS_H
