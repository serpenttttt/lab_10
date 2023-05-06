#ifndef LAB_10_FUNCTIONS_H
#define LAB_10_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

BT_node *add_BT_node(char *word, BT_node *tree);

void print_words(BT_node *tree, int mode);

void clear_tree(BT_node *tree);

#endif //LAB_10_FUNCTIONS_H
