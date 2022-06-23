#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class freqFile {
    public:
    char c[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
    int co[26];
    char* FD; 
    ifstream tf;
    freqFile(char* a){
        FD = a;
    }
    void readFile(){
        
        tf.open(FD);
    }
    void showFreq(){
        string temp;
        for(int i = 0;i<26;i++){
            co[i]=0;
        }

        while(getline(tf, temp)){
            for(int i =0;i<temp.size();i++){
                temp[i]=tolower(temp[i]);
                for(int k = 0;k<26;k++){
                    if(temp[i]==c[k]){
                        co[k]++;
                    }
                }
            }
            
        }
        for(int i = 0;i<26;i++){
            cout<<"["<<c[i]<<"] = "<<co[i]<<endl;
        }
        tf.close();
        
    }
};

int main() {
    freqFile myFile("main.cpp");
    myFile.readFile();
    myFile.showFreq();
    return 0;
}