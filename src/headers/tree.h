#ifndef LINKED_LIST_TREE_H
#define LINKED_LIST_TREE_H

typedef struct node_s {
    int value;
    struct node_s* left;
    struct node_s* right;
} node_t;

typedef struct node_s* tree_t;

/**
 * Create a new tree.
 * @return
 */
tree_t init_tree();

/**
 * Create a node for a tree.
 * @param value The value of the node.
 * @return The new node.
 */
struct node_s* create_node(int value);

/**
 * Compute the weight of a tree.
 * @param tree The tree to be computed.
 * @return The weight of the tree.
 */
int weight(tree_t tree);

/**
 * Compute the longest section of a tree.
 * @param tree The tree to be computed.
 * @return The longest section of a tree.
 */
int longest_section(tree_t tree);

void print_infix(tree_t tree);

void print_postfix(tree_t tree);

void print_prefix(tree_t tree);

int minimal(tree_t tree);

#endif //LINKED_LIST_TREE_H
