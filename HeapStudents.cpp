// Read the marks obtained by students of second year in an online examination of
// particular subject. Find out maximum and minimum marks obtained in that subject. Use
// heap data structure. Analyze the algorithm.

#include<iostream>
using namespace std;

#define MAX 4

class studentheap{
    int marks[MAX];
    int size;
    
    public:
    studentheap(){
        size = 0;
    }
    int getsize(){
        return size;
    }
    void Insert(int mark){
        size ++;
        int i = size;
        marks[i] = mark;
        
        while( i > 1 && marks[i] < marks[i/2]){
            swap(marks[i],marks[i/2]);
            i = i / 2;
        }
    }
    
    void Display(){
        cout<<"---Display---"<<endl;
        for(int i = 1; i <=size ;i++){
            cout<<marks[i]<<" ";
        }
        cout<<"\n";
    }
    
    void Minmark(){
        if(!size){
            cout<<"Marks are not entered !!!"<<endl;
        }
        else{
            cout<<"The minimum marks are : "<<marks[1]<<endl;
        }
    }
     void Maxmark(){
         if(!size){
             cout<<"Marks are not entered !!!"<<endl;
         }
         else{
            int maxmark = marks[1];
            for(int i = 2; i <=size; i++){
                if(marks[i] > maxmark){
                    maxmark = marks[i];
                }
            } cout<<"Maxmarks is : "<< maxmark <<endl;
         }
     }
    
};
int main(){
    studentheap s1;
    int choice;
    int n;
    int mark;
    
    do{
        cout<<"---Menu---"<<endl;
        cout<<"1.Insert marks"<<endl;
        cout<<"2.Find minmum mark"<<endl;
        cout<<"3.Find Maximum mark"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;
        
        cout<<"Enter the choice (1-5) : ";
        cin>>choice;
        
        switch(choice){
        case 1:
            cout<<"Enter the number of marks to be inserted : ";
            cin>>n;
            for(int i = 0 ; i < n; i++){
                if(s1.getsize() >= MAX){
                    cout<<"The limit is reached, cannot insert more marks !!!"<<endl;
                    break;
                }
                cout<<"Enter the mark "<<i<<" : ";
                cin>>mark;
                s1.Insert(mark);
                
            }
            break;
            
            
        case 2:
            s1.Minmark();
            break;
            
        case 3:
            s1.Maxmark();
            break;
            
        case 4:
            s1.Display();
            break;
        }
    }while( choice != 5);
}