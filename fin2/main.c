#include <stdio.h>

typedef struct LinkedList{
    char a;
    struct node_t *next;
}LinkedList;

LinkedList* allocNode(int data){
    LinkedList* t = calloc(1, sizeof(LinkedList));
    t->a = data;
    return t;
}

void show_list(LinkedList* list){
    LinkedList* temp = list;
    printf("[%c]->", temp->a);
    while(temp->next != NULL){
        temp = temp->next;
        printf("[%c]->", temp->a);
    }
    printf("%s\n", "null");
}

LinkedList* appendList(LinkedList* list, char new_data){
    if(list == NULL){
        list = allocNode(new_data);
    }else{
        LinkedList* temp = list;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = allocNode(new_data);
        }
    return list;
}

void free_all_node(LinkedList* list){

    printf("free([%d])->", list->a);
    if(list->next != NULL)
        free_all_node(list->next);
    else
        printf("null");
    free(list);
}
LinkedList* add_node(LinkedList* head, char new_data){
    LinkedList* newHead = allocNode(new_data);
    newHead->next = head;
    return newHead;
}
LinkedList* del_node(LinkedList* head, int n){
    LinkedList* t = head;
    LinkedList* l = head;
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
LinkedList* reverseList(LinkedList* head){
    LinkedList* Newhead = NULL;
    if(head->next!=NULL){
        Newhead = reverseList(head->next);
        appendList(Newhead,head->a);
        return Newhead;
    }else{
        Newhead = appendList(Newhead,head->a);
        return Newhead;
    }
    
}

int main()
{
    LinkedList* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    show_list(head);
    head = reverseList(head);
    show_list(head);
    return 0;

}