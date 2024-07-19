#include<iostream>
#define max 10

using namespace std;

int stack[max];
int top = -1;

void push(int data){
    top++;
    stack[top] = data;
}

void pop(){
    cout  << stack[top] << endl;
    stack[top] = 0;
    top--;
}

int main(){
	int data;
    char order;
    
    while(true){
        cin >> order;
        
        if(order == 'X'){
            break;
        }
        else if(order == 'U'){
            cin >> data;
            push(data);
        }
        else if(order == 'O'){
            pop();
        }
        else if(order == 'T'){
            cout << stack[top] << endl;
        }
        else if(order == 'P'){
            for(int i=0; i <= top; i++){
                cout << stack[i] << " ";
            }
			cout << endl;
        }
        else if(order == 'N'){
            cout << top+1 << endl;
        }
    }
}
