#include<iostream>
#include<string>
#define Size 1000

using namespace std;

class Queue{
	public:
    	int arr[1000];
    	int i , size = 1000;
    	int head = 1 , tail = 0;

    	int empty(){
        	if(head > tail){
            	return 1;
        	}
			else {
            	return 0;
        	}
    	}

    	int full(){
        	if(tail == size){
            	return 1;
        	}
			else{
            	return 0;
        	}
    	}

    	void Enqueue(int input){
        	if(!full()){
            	tail++;
            	arr[tail] = input;
        	}
    	}

    	int Dequeue(){
        	if(!empty()){
            	int tmp = arr[head];
            	head++;
            	return tmp;
        	}
        	return -1;
    	}

    	void print(){
        	for(i=head; i<=tail; i++){
            	cout << arr[i] << " ";
        	}
        	cout << endl;
    	}
};

int main(){
	Queue q;
    string str;
    int num;

    while(1){
        cin >> str;
        
        if(str == "e"){
            cin >> num;
            q.Enqueue(num);
        }
        if(str == "d"){
            cout << q.Dequeue() << endl;
        }
        if(str == "p"){
            q.print();
        }
        if(str == "n"){
            cout << (q.tail - q.head + 1) << endl;
        }
        if(str == "s"){
            if(!q.empty()){
                cout << q.arr[q.head] << " " << q.arr[q.tail] << endl;
            }
        }
        if(str == "x"){
            break;
        }
    }
}
