#ifndef LAB_10_HT_H
#define LAB_10_HT_H

typedef struct City {
    char *city;
    int population;
    struct City *next;
} City;

typedef struct HT {
    City **cities;
    int size;
    int count_of_elements;
} HT;

#endif //LAB_10_HT_H
