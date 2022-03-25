#include <tree.h>
#include <stdio.h>


int main() {

    tree_t myTree = init_tree();

    int number_of_node = 10;
    node_t* global_node[number_of_node];

    for (int i = 0; i < number_of_node; i ++) {
        global_node[i] = create_node(i);
    }

    myTree = global_node[0];
    global_node[0]->left = global_node[1];
    global_node[0]->right = global_node[5];
    global_node[1]->left = global_node[2];
    global_node[1]->right = global_node[3];
    global_node[3]->left = global_node[4];
    global_node[5]->right = global_node[6];
    global_node[6]->left = global_node[7];
    global_node[7]->left = global_node[8];
    global_node[7]->right = global_node[9];
    global_node[9]->right = global_node[10];

    printf("The weight of the tree is %d\n", weight(myTree));

    printf("The longest section of the tree is %d\n", longest_section(myTree));

    printf("\n-----\n");
    print_infix(myTree);
    printf("\n-----\n");
    print_postfix(myTree);
    printf("\n-----\n");
    print_prefix(myTree);
    printf("\n-----\n");

    printf("The minimal value of the tree is %d\n", minimal(myTree));

    return 0;
}

