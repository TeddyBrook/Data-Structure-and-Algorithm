#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Graph{
	public:
		int edge[100][100];
		int num;
		
		void AddEdge(int a , int b , int c){
			edge[a][b] = c;
			edge[b][a] = c;
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
		
		void BFS(int start){
			bool visited[100] = {0};
			
			visited[start] = 1;
			vector <int> q;
			q.push_back(start);
			
			while(q.empty() == 0){
				start = q.front();
				cout << start << " ";
				q.erase(q.begin());
				
				for(int i=0; i<this -> num; i++){
					if(visited[i] == 0 && edge[start][i] > 0){
						visited[i] = 1;
						q.push_back(i);
					}
				}
			}
		}
		
		bool Visit_DFS[100];
		
		void Sub_DFS(int s){
			cout << s << " ";
			Visit_DFS[s] = 1;
			
			for(int i=0; i<num; i++){
				if(Visit_DFS[i] == 0 && edge[s][i] > 0){
					Sub_DFS(i);
				}
			}
		}
		
		void DFS(int s){
			for(int i=0; i<num; i++){
				Visit_DFS[i] = 0;
			}
			Sub_DFS(s);
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
	bool s = 1;
	
	cin >> z;
	Graph *g = new Graph(z);
	
	do{
		cin >> c;
		switch(c){
			case 'e':
				if(s){
					cin >> x;
					cin >> y;
					cin >> z;
					g -> AddEdge(x , y , z);
				}
				break;
				
			case 's':
				s=0;
				break;
				
			case 'd':
				cin >> z;
				g -> DFS(z);
				cout << endl;
				break;
				
			case 'b':
				cin >> z;
				g -> BFS(z);
				cout << endl;
				break;
		}
	}
	while(c != 'q');
	
	return 0;
}
