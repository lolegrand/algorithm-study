#include <malloc.h>
#include <stdlib.h>
#include <list.h>

linked_list_t create_ll() {
    return NULL;
}

void push_front_ll(linked_list_t* list, int element) {
    struct link_s* link = (struct link_s*)malloc(sizeof(struct link_s));
    if (link == NULL) {
        perror("Malloc error : push front");
        exit(1);
    }
    link->value = element;
    link->next = *list;
    *list = link;
}

void it_print_ll(linked_list_t list) {
    struct link_s* it = list;

    printf("----- Begin print it linked list ------\n");
    while (it != NULL) {
        printf("\t next value %d \n", it->value);
        it = it->next;
    }
    printf("----- End print it linked list ------\n");
}

static void rec_print_rw_liked_list(linked_list_t list) {
    if (list == 0x00) {
        return;
    }
    printf("\t next value %d \n", list->value);
    rec_print_rw_liked_list(list->next);
}

void rec_right_way_print_ll(linked_list_t list) {
    printf("----- Begin print rec rw linked list ------\n");
    rec_print_rw_liked_list(list);
    printf("----- End print rec rw linked list ------\n");
}

static void rec_print_iw_linked_list(linked_list_t list) {
    if (list == 0x00) {
        return;
    }
    rec_print_iw_linked_list(list->next);
    printf("\t next value %d \n", list->value);
}

void rec_inv_way_print_ll(linked_list_t list) {
    printf("----- Begin print rec iw linked list ------\n");
    rec_print_iw_linked_list(list);
    printf("----- End print rec iw linked list ------\n");
}

void free_ll(linked_list_t* list) {
    struct link_s* next = (*list)->next;
    while (next != NULL) {
        free(*list);
        *list = next;
        next = (*list)->next;
    }
    free(*list);
    *list = NULL;
}

int rec_env_size_ll(linked_list_t list) {
    if (list == NULL) {
        return 0;
    } else {
        return rec_env_size_ll(list->next) + 1;
    }
}

int rec_term_size_ll(linked_list_t list, int aux) {
    if (list == NULL) {
        return aux;
    } else {
        return rec_term_size_ll(list->next, aux + 1);
    }
}

int rec_env_max_ll(linked_list_t list) {
    if (list->next == NULL) {
        return list->value;
    } else {
        int val = rec_env_max_ll(list->next);
        if (val > list->value) {
            return val;
        } else {
            return list->value;
        }
    }
}

int rec_term_max_ll(linked_list_t list, int aux) {
    if (list->next == NULL) {
        if (list->value > aux) {
            return list->value;
        } else {
            return aux;
        }
    }
    if (aux > list->value) {
        return rec_term_max_ll(list->next, aux);
    } else {
        return rec_term_max_ll(list->next, list->value);
    }
}

void it_reverse_ll(linked_list_t* list) {
    // considering *list as the current value.
    struct link_s* lv = NULL;
    struct link_s* nv = (*list)->next;

    while (nv != NULL) {
        (*list)->next = lv;
        lv = (*list);
        (*list) = nv;
        nv = nv->next;
    }
    (*list)->next = lv;
}

