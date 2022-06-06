
#include <iostream>

using namespace std;
class Node{
    public:
        Node* next = NULL;
        int v;
        Node(int n){
            v = n;
        }
};

class LinkedList {
    private:
        Node* head = NULL;
    public:
        LinkedList(){
            
        }
        void append_node(int n){
            if(head == NULL){
                head = new Node(n);
            }else{
                Node* temp = head;
                while(temp->next!= NULL){
                    temp = temp ->next;
                }
                temp -> next = new Node(n);
            }
            showlist(false);
        }
        void del_node(int n){
            Node* temp = head;
            Node* left;
            do{
                if(temp->v ==n)
                    break;
                left = temp;
                temp = temp ->next;
            }while(temp->next!= NULL);
            if(head ==temp){
                head = temp->next;
                delete temp;
            }else if(temp-> next){
                left ->next = temp ->next;
                delete temp;
            }else{
                left-> next = NULL;
                delete temp;
            }
            showlist(true);
        }
        void showlist(bool a){
            Node* temp = head;
            while(temp->next!= NULL){
                if(a)
                    cout<<"free(["<<temp->v<<"]->";
                else
                    cout<<"["<<temp->v<<"]->";
                temp = temp ->next;
            }
            if(a)
                cout<<"free(["<<temp->v<<"]->";
            else
                cout<<"["<<temp->v<<"]->";
            cout<<"null"<<endl;
        }
};
int main()
{
    LinkedList mylink;
    mylink.append_node(0);
    mylink.append_node(1);
    mylink.append_node(2);
    mylink.append_node(3); 
    mylink.del_node(1);
    return 0;
}