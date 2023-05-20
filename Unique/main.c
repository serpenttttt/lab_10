#include "functions.h"
#include "struct.h"

int main(int argc, char *argv[]) {

    int parameter;

    int mode = 1;

    if (argc == 2)
        parameter = 1;

    else if (argc == 4) {
        parameter = 3;
        if (strcmp(argv[2], "DESC") == 0)
            mode = 2;
    }
    else {
        puts("Invalid number of parameters");
        return -1;
    }

    FILE *file = fopen(argv[parameter], "r");

    if (file == NULL) {
        puts("No such file");
        return -1;
    }

    char *word = (char *) malloc(sizeof(char));

    BT_node *tree = NULL;

    char c;

    while ((c = fgetc(file)) != EOF) {
        for (int i = 0; c != '\n'; ++i) {
            word = (char *) realloc(word, i + 2);
            word[i] = c;
            word[i + 1] = '\0';
            c = fgetc(file);
        }
        tree = add_BT_node(word, tree);
    }

    print_words(tree, mode);

    clear_tree(tree);

    return 0;
}
