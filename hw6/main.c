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
node_t* add_node(node_t* head, int new_data){
    node_t* newHead = allocate_node(new_data);
    newHead->next = head;
    return newHead;
}
node_t* del_node(node_t* head, int n){
    node_t* t = head;
    node_t* l = head;
    while(t){
        if(n == 0){
            if(t == head){
                head = t->next;
            }else{
                l->next = t->next;
            }
            free(t);
            t = NULL;
        }else{
           n--;
           l = t;
           t = t->next;
        }
    }
    return head;
}

int main()
{
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node (head, -1);
    show_list(head);
    del_node(head, 1);
    show_list(head);
    free_all_node(head);
    return 0;

}
