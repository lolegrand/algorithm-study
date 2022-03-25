#include <tree.h>
#include <malloc.h>
#include <stdlib.h>


tree_t init_tree() {
    return NULL;
}

struct node_s* create_node(int value) {
    struct node_s* node = (struct node_s*)malloc(sizeof (struct node_s));
    if (node == NULL) {
        perror("Error while allocating a node");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

int weight(tree_t tree) {
    if (!tree) return 0;
    return weight(tree->right) + weight(tree->left) + 1;
}

int longest_section(tree_t tree) {
    if (!tree) return 0;
    return longest_section(tree->right) > longest_section(tree->left) ?
    longest_section(tree->right) + 1 : longest_section(tree->left) + 1;
}

void print_infix(tree_t tree) {
    if (tree) {
        print_infix(tree->left);
        printf("%d ", tree->value);
        print_infix(tree->right);
    }
}

void print_postfix(tree_t tree) {
    if (tree) {
        print_infix(tree->left);
        print_infix(tree->right);
        printf("%d ", tree->value);
    }
}

void print_prefix(tree_t tree) {
    if (tree) {
        printf("%d ", tree->value);
        print_infix(tree->left);
        print_infix(tree->right);
    }
}

int minimal(tree_t tree) {
    if (!tree->left && !tree->right)
        return tree->value;

    int min_left = minimal(tree->left);
    int min_right = minimal(tree->right);


    return min_left > min_right ? (min_right < tree->value ? min_right : tree->value) : (min_left < tree->value ? min_right : tree->value);
}
