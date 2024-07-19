#include <iostream>

using namespace std;

char size[100];
bool run = true;
int top=0;

bool full(){
    if(top == 100){
        return true;
    }
	else{
        return false;
    }
}

bool empty(){
    if(top == 0){
        return true;
    }
    else{
        return false;
    }
}

char push(char x){
    if(!full()){
        top++;
        size[top] += x;
    }
}

char pop(){
    if(!empty()){
        size[top] += ' ';
        top--;
    }
    else{
        run = false;
    }
}

int main(){
    int i=0 , check=0;
    char input[100];
    
    cin >> input;

    while(run){
        if(input[i]=='('){
            push(input[i]);
            check++;
        }
        else if(input[i]==')'){
            pop();
            check--;
        }
        
        i++;
        
        if(input[i]== '\0'){
			run = false ;
		}
    }

    if(check == 0){
        cout << "Pass";
    }
	else{
        cout << "Error";
    }

    return 0;
}
