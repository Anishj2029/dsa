#include<iostream>
#include<string>
using namespace std;

struct node{
    string label;
    int childcount;
    node* child[10];
};

class book{
    node* root;
    
    public:
    book(){
        root = NULL;
    }
    
    void create(){
        root = new node;
        cout<<"Enter the name of book : ";
        cin.ignore();
        getline(cin,root->label);
        
        cout<<"Enter the number of chapters in book : ";
        cin>>root->childcount;
        
        for(int i = 0; i < root->childcount; i++){
            root->child[i] = new node;
            cout<<"Enter the name of chapter : ";
            cin.ignore();
            getline(cin,root->child[i]->label);
            
            cout<<"Enter the number of sections in chapter : ";
            cin>>root->child[i]->childcount;
            
            
            for(int j = 0; j < root->child[i]->childcount; j++){
                root->child[i]->child[j] = new node;
                cout<<"Enter the name of section : ";
                cin.ignore();
                getline(cin,root->child[i]->child[j]->label);
                
                cout<<"Enter the number of sub-sections in section : ";
                cin>>root->child[i]->child[j]->childcount;
                
                for(int k = 0 ; k < root->child[i]->child[j]->childcount; k++){
                    root->child[i]->child[j]->child[k] = new node;
                    cout<<"Enter the name of sub-section : ";
                    cin.ignore();
                    getline(cin,root->child[i]->child[j]->child[k]->label);
                    
                    root->child[i]->child[j]->child[k]->childcount = 0;
                }
            }
        }
    }
    
    void Display(){
        cout<<"---Displaying Book---"<<endl;
        cout<<"Name of book : "<<root->label<<endl;
        for(int i = 0; i < root->childcount; i++){
            cout<<"Name of chapters : "<<root->child[i]->label<<endl;
            for(int j = 0; j < root->child[i]->childcount;j++){
                cout<<"Name of section : "<<root->child[i]->label<<endl;
                for(int k = 0; k < root->child[i]->child[j]->childcount; k++){
                    cout<<"Name of sub-section : "<<root->child[i]->label<<endl;
                }
                
            }
        }
    }
};

int main(){
    book b1;
    int choice;
    
    do {
        cout<<"---MENU---"<<endl;
        cout<<"1.ADD A BOOK"<<endl;
        cout<<"2.DISPLAY A BOOK"<<endl;
        cout<<"3.EXIT"<<endl;
        
        cout<<"Enter the choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:
                b1.create();
                break;
                
            case 2:
                b1.Display();
                break;
                
            case 3:
                cout<<"Exiting..."<<endl;
                break;
                
        }
    }while( choice != 3);
}