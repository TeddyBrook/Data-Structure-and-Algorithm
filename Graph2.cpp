#include<iostream>
using namespace std;

class Graph{
	public:
		int edge[100][100];
		int Mat[100][100];
		int num;
		
		void AddEdge(int a , int b , int c){
			edge[a][b] = c;
		}
		
		void PrintGraph(){
			for(int i=0; i<this -> num; i++){
				cout << i << "-->";
				for(int j=0; j<this -> num; j++){
					cout << edge[i][j] << " ";
				}
				cout << endl;
			}
		}
		
		void Matrix(){
			for(int i=0; i<this -> num; i++){
				for(int j=0; j<this -> num; j++){
					Mat[i][j] = edge[i][j];
				}
			}
			
			for(int k=0; k<this -> num; k++){
				for(int i=0; i<this -> num; i++){
					for(int j=0; j<this -> num; j++){
						if(Mat[i][j] == 1){
							for(int k=0; k<this -> num; k++){
								if(Mat[j][k] == 1){
								   Mat[i][k] =1;
								}
							}
						}
					}
				}
			}
			
			for(int i=0; i<this -> num; i++){
				for(int j=0; j<this -> num; j++){
					cout << Mat[i][j];
					if(j != this -> num-1){
						cout << " ";
					}
				}
				cout << endl;
			}
		}
		
		Graph(int n){
			this -> num = n;
			
			for(int i=0; i<this -> num; i++){
				for(int j=0; j<this -> num; j++){
					edge[i][j] = 0;
				}
			}
		}
};

int main(){
	int x , y , z;
	char c;
	
	cin >> z;
	Graph *g = new Graph(z);
	
	do{
		cin >> c;
		
		switch(c){
			case 'e':
				cin >> x;
				cin >> y;
				cin >> z;
				g -> AddEdge(x , y , z);
				break;
					
			case 's':
				g -> Matrix();
				break;
		}
	}
	while(c != 's');
	
	return 0;
}
