#include <stdio.h>

typedef struct node{
    int a;
    struct node_t *next;
}node_t;

node_t* allocate_node(int data){
    node_t* t = calloc(1, sizeof(node_t));
    t->a = data;
    return t;
}

void show_list(node_t* list){
    node_t* temp = list;
    printf("[%d]->", temp->a);
    while(temp->next != NULL){
        temp = temp->next;
        printf("[%d]->", temp->a);
    }
    printf("%s\n", "null");
}

node_t* append_node(node_t* list, int new_data){
    if(list == NULL){
        list = allocate_node(new_data);
    }else{
        node_t* temp = list;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = allocate_node(new_data);
        }
    return list;
}

void free_all_node(node_t* list){

    printf("free([%d])->", list->a);
    if(list->next != NULL)
        free_all_node(list->next);
    else
        printf("null");
    free(list);
}

int main()
{
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 11);
    show_list(head);
    head = append_node(head, 222);
    show_list(head);
    head = append_node(head, 3333);
    show_list(head);
    free_all_node(head);

    return 0;
}
