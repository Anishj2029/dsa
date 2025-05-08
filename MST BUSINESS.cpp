// You have a business with several offices; you want to lease phone lines to connect them
// up with each other; and the phone company charges different amounts of money to
// connect different pairs of cities. You want a set of lines that connects all your offices
// with a minimum total cost. Solve the problem by suggesting appropriate data structures.
//prims algorithm

#include<iostream>
#include<string>
using namespace std;

class graph{
	int city[4][4];
	
	public:
		graph(){
			for(int i = 0 ; i < 4 ; i++ ){
				for(int j = 0; j < 4 ; j ++){
					city[i][j] = 0;
				}
			}
		}
		
		void input(){
			string name[4]={"SATARA","PUNE","KARAD","MUMBAI"};
			
			for(int i = 0; i < 4; i ++){
				for(int j = i+1; j <4 ; j ++){
					cout<<"Enter the distance from "<<name[i]<<" to "<<name[j]<<" : ";
					cin>>city[i][j];
					city[j][i] = city[i][j];
				}
			}
		}
		
		void printmatrix(){
			cout<<"---printing Matrix---"<<endl;
			for(int i = 0; i < 4 ; i++){
				for(int j = 0; j < 4 ; j++){
					cout<<city[i][j]<<" ";
				}
				cout<<" "<<endl;
			}
		}
		
		void MST(){
			int selected[4]={1,0,0,0};
			int totalweight = 0;
			
			for(int edge = 0 ; edge < 3 ; edge ++){
				int min = 999 , u  = -1 , v = -1;
				
				for(int i = 0; i < 4 ; i++){
					if(selected[i]){
						for(int j = 0 ; j < 4; j++){
							if(!selected[j] && city[i][j] && city[i][j] < min){
								min = city[i][j];
								u = i;
								v = j;
							}
						}
					}
				}
				if( u != -1 && v != -1){
					cout<<"The smallest distance from "<< u <<" to "<< v <<" is = "<< min<<endl;
					selected[v] = 1;
					totalweight = totalweight + min;
					
				}
			}
			cout<<"The total weight is : "<<totalweight<<endl;
		}
};

int main(){
	graph g1;
	g1.input();
	g1.printmatrix();
	g1.MST();
	return 0;
}
