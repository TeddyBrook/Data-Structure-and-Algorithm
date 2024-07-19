#include<iostream>
using namespace std;

class Stack {
	public:
    	char arr[100];
    	int top = 0;

    	void push(char input) {
        	if (top >= 100) {
        		//
        	}
        	else {
        		top++;
            	arr[top] = input;
        	}
    	}

    	void pop(char input) {
        	if (top <= 0) {
				//        	
			}
        	else {
            	input = arr[top];
        		top--;
        		cout << input;
        	}
    	}
};

int main(){
	Stack s;

    int i=0 , j=0;
    char input[100];
    
    cin >> input;

	while(input[j] != '\0'){
        s.push(input[j]);
        j++;
    }
    
    while(i <= j){
    	s.pop(input[i]);
    	i++;
	}

    return 0;
}
