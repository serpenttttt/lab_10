#include "functions.h"

BT_node *add_BT_node(char *word, BT_node *tree) {
    // Если дерева нет, то создаем его
    if (tree == NULL) {

        tree = (BT_node *) malloc(sizeof(BT_node)); // Память под узел
        tree->word = (char *) malloc(sizeof(char) * strlen(word));
        tree->word = word;
        printf("%s", tree->word);
        tree->freq = 1;
        tree->left = NULL;
        tree->right = NULL;

    } else {

        // Значения strcmp()
        // 0 -- строки совпадают
        // < 0 -- строка1 меньше строки 2
        // > 0 -- строка1 больше строки 2.
        puts("not null");
        if (strcmp(word, tree->word) == 0) {

            tree->freq += 1;

        } else {

            /*BT_node *temp = (BT_node *) malloc(sizeof(BT_node));
            temp->word = word;
            temp->freq = 1;
            temp->left = NULL;
            temp->right = NULL;*/

            // Условие добавление левого потомка
            if (strcmp(word, tree->word) < 0)
                tree->left = add_BT_node(word, tree->left);

                // Иначе добавляем правый
            else
                tree->right = add_BT_node(word, tree->right);

        }
    }

    return tree;
}

void print_words(BT_node *tree, int mode) {
    if (tree != NULL) {
        if (mode == 1) {

            print_words(tree->left, mode);
            printf("%s %d\n", tree->word, tree->freq);
            print_words(tree->right, mode);

        }
        else {

            print_words(tree->right, mode);
            printf("%s %d\n", tree->word, tree->freq);
            print_words(tree->left, mode);

        }
    }
}

void clear_tree(BT_node *tree) {
    if (tree != NULL) {

        clear_tree(tree->left);
        clear_tree(tree->right);

        free(tree->word);
        free(tree);
    }
}