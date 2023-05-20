#ifndef LAB_10_STRUCT_H
#define LAB_10_STRUCT_H

typedef struct BT_node {
    char *word;
    int freq;
    struct BT_node *left;
    struct BT_node *right;
} BT_node;

#endif //LAB_10_STRUCT_H
