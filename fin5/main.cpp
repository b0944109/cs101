#include <iostream>

using namespace std;
class MMmanger{
    private:
        int total;
        int sp;
        string a;
        int** b;
    public:
        int* calloc_MM(int size){
            if(sp-size>=0){
                sp-=size;
                int* t = (int*)calloc(size, sizeof(int));
                for(int i = 0;size>0;i++){
                    if(a[i]=='0'){
                        size--;
                        a[i] = '1';
                        b[i] = t;
                    }
                }
                if(sp == 0){
                    print_calloc_array(2, size);
                }else
                    print_calloc_array(0, size);
                return t;
            }else{
                print_calloc_array(1, size);
            }
                
        }
        void free_MM(int* p){
            for(int i = 0;i<total;i++){
                if(b[i]==p){
                    a[i]='0';
                    b[i]=NULL;
                    sp++;
                }
            }
            print_calloc_array(0, 0);
            free(p);
        }
        int get_MMCapacity(){
            cout<<"Capacity:"<<sp;
            cout<<" - ";
        }
        void print_calloc_array(int flag, int size){
            get_MMCapacity();
            if(flag == 0){
                cout<<a<<endl;
            }else if(flag == 1){
                cout<<a<<" <- Out of space: demand "<<size;
            }else{
                cout<<a<<" <- No space"<<endl;
            }
            
        }
        MMmanger(int size){
            total = size;
            sp = total;
            for(int i = 0;i<size;i++)
                a+="0";
            b = new int*[size];
        }
        ~MMmanger(){
            
        }
};
int main()
{
    MMmanger mmer(10);
    int* p1 = mmer.calloc_MM(1);
    int* p2 = mmer.calloc_MM(2);
    int* p3 = mmer.calloc_MM(3);
    int* p4 = mmer.calloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p4);
    int* p5 = mmer.calloc_MM(6);

    return 0;
}