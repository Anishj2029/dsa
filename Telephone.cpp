#include<iostream>
#include<string>
using namespace std;

const int table_size = 10;

struct client {
	string name;
	long long tele;
};
struct node {
	client data;
	node* next;
};

class linear {
	client table[table_size];
	bool obs[table_size];
public:
	linear() {
		for(int i = 0; i < table_size; i++) {
			obs[i] = false;
		}
	}

	int hashfuntion(long long tele) {
		return tele % table_size;
	}

	void insert(string name, long long tele) {
		int index = hashfuntion(tele);
		int start = index;

		while(obs[index]) {
			index = (index + 1) % table_size;
			if(index == start) {
				cout<<"NO PLACE TO INSERT THE NAME"<<endl;
			}
		}

		table[index].name = name;
		table[index].tele = tele;
		obs[index]= true;
		cout<<"Insertion is done(linear)"<<endl;
	}

	void search(long long tele) {
    int index = hashfuntion(tele);
    int comparisons = 0;
    int start_index = index;

        while (obs[index]) { 
            comparisons++;
            if (table[index].tele == tele) {
             cout << "We got the searched value!!!" << endl;
            cout << "The number of comparisons we got is: " << comparisons << endl;
                return;
            }

            index = (index + 1) % table_size;

       
            if (index == start_index) {
            break;
            }
        }

       
        cout << "The number of comparisons we got is: " << comparisons << endl;
    }
    
    void Display(){
        cout<<"---Displaying table(Linear)---"<<endl;
        for(int i = 0; i < table_size;i++){
            if(obs[i]){
            cout<<"["<<i<<"]"<<"->"<<table[i].name<<"==="<<table[i].tele<<endl;
            }
            else{
                cout<<"["<<i<<"]"<<"->"<<"[EMPTY]"<<endl;
            }
        }
    }
};

class chaning{
    
    node* table[table_size];
   
    public:
    chaning(){
        for(int i = 0; i < table_size; i++){
            table[i] = NULL;
        }
    }
    
    int hashfuntion(long long tele){
        return tele % table_size;
    }
    
    void insert(string name, long long tele){
        int index = hashfuntion(tele);
        node* temp = new node;
        temp->data.name = name;
        temp->data.tele = tele;
        temp->next = table[index];
        table[index] = temp;
        cout<<"insertion is done(Chaining)"<<endl;
    }
    
    void search(long long tele){
        int index = hashfuntion(tele);
        node* temp = table[index];
        int comparisons = 0;
        
        while(temp){
            
            comparisons++;
            
            if(temp->data.tele == tele ){
                cout<<"WE Found the searche data !!!"<<endl;
                cout<<"The total number of comparisions are : "<<comparisons<<endl;
                break;
            }
            else{
                temp = temp->next;
            }
        }
    }
    
    void Display(){
        cout<<"---Displying table(chaining)"<<endl;
        for(int i = 0; i < table_size;i++){
            cout<<"["<<i<<"]";
            node* temp = table[i];
            while(temp){
                cout<<"->"<<temp->data.name<<"==="<<temp->data.tele;
                temp = temp -> next;
            }
            cout<<"\n";
        }
    }
};

int main() {
	int choice;
	string name;
	long long tele;
	linear l1;
	chaning c1;
	do {
		cout<<"---MENU---"<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Search"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Choice the numebr(1-4) : ";
		cin>>choice;

		switch(choice) {
		case 1:
		    cout<<"Enter the name : ";
		    cin>>name;
		    cout<<"Enter the telephone number : ";
		    cin>>tele;
		    l1.insert(name,tele);
		    c1.insert(name,tele);
		    break;

		case 2:
		    cout<<"Enter the telephone to be searched : ";
		    cin>>tele;
		    l1.search(tele);
		    c1.search(tele);
		    break;
				
		case 3:
			l1.Display();
			c1.Display();
			break;
			
			
			}
			
		} while(choice != 4);

	}
