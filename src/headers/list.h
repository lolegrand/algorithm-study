#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

struct link_s {
    int value;
    struct link_s* next;
};

typedef struct link_s* linked_list_t;

/**
 * Create a new linked list.
 * @return The new linked list.
 */
linked_list_t create_ll();

/**
 * Add element in front of the list.
 * @param list The list to add the element.
 * @param element The element to be added.
 */
void push_front_ll(linked_list_t* list, int element);

/**
 * Pretty print the list using iterative algorithm.
 * @param list The list to be printed.
 */
void it_print_ll(linked_list_t list);

/**
 * Pretty print the list in using recursive algorithm.
 * @param list The list to be printed.
 */
void rec_right_way_print_ll(linked_list_t list);

/**
 * Pretty print the list reversed using recursive algorithm.
 * @param list List to be computed.
 */
void rec_inv_way_print_ll(linked_list_t list);

/**
 * Compute size of a list using enveloped recursive algorithm.
 * @param list List to be computed.
 * @return The size of the list.
 */
int rec_env_size_ll(linked_list_t list);

/**
 * Compute size of the list using terminal recursive algorithm.
 * @param list List to be computed.
 * @param init The initial value of the algorithm (should be 0).
 * @return The size of the list.
 */
int rec_term_size_ll(linked_list_t list, int init);

/**
 * Research the maximum value of the list using enveloped recursive algorithm.
 *
 * @warning The list shouldn't be empty.
 *
 * @param list List to be computed.
 * @return The max value of the list.
 */
int rec_env_max_ll(linked_list_t list);

/**
 * Research the maximum value of the list using terminal recursive algorithm.
 *
 * @warning The list shouldn't be empty.
 *
 * @param list List to be computed.
 * @param init The initial value of the algorithm (should be INT minimal value).
 * @return The max value.
 */
int rec_term_max_ll(linked_list_t list, int init);

/**
 * Reverse a list.
 * @param list The list to be reversed.
 */
void it_reverse_ll(linked_list_t* list);

/**
 * Free the current list.
 * @param list The list to be freed.
 */
void free_ll(linked_list_t* list);


#endif //LINKED_LIST_LIST_H
