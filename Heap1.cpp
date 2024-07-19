#include<iostream>
using namespace std;

#define MAX 100

class Heap{

	private:
		int arr[MAX];
		int size;
 
	public:
		Heap(){ 
			size = 0;
		}

	int Remove();

    void Insert(int input);
    void MaxHeap(int num);
    void Print();  
};

void Heap::MaxHeap(int num){
	int i;
    size = num;
    
    for(i=1; i<=size; i++){
        cin >> arr[i];
    }

    for(int j = size/2; j>0; j--){
        int root = arr[j];

        for(int i=j; i<=size/2 ;){
            int Child_Node = 2*i;

            if(Child_Node < size){
                if(arr[Child_Node] > arr[Child_Node + 1]){
                    Child_Node = Child_Node+1;
                }
            }
            if(arr[Child_Node] < root){
                arr[i] = arr[Child_Node];
                i = Child_Node;
            }
			else{
                break;
            }
        }
		arr[i] = root;
    }
}

void Heap::Print(){
    if(size == 0){
		cout << "Heap is Empty";
	}
	else{
		for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
    }
}

void Heap::Insert(int input){
	size++;
	arr[size] = input;
	
	int i;
	
	for(i=size; i>1; i=i/2){
		if(arr[i/2] > input){
			break;
		}
		arr[i] = arr[i/2];
	}
	arr[i] = input;
}

int Heap::Remove(){
	if(size == 0){
		return -1;
	}
	
	int x = arr[1];
	
	arr[1] = arr[size];
	size--;
	
	int i;
	int root = arr[1];
	
	for(i=1; i<=size/2;){
		int Child_Node = 2*i;
		
		if(Child_Node < size){
			if(arr[Child_Node] < arr[Child_Node+1]){
				Child_Node = Child_Node+1;
			}	
		}
		if(root < arr[Child_Node]){
			arr[i] = arr[Child_Node];
			i = Child_Node;
		}
		else{
			break;
		}
	}
	arr[i] = root;

	return x;
}

int main(){
    Heap *h = new Heap();
	
	int x;
    char choice;
    
    while(cin >> choice){
       switch(choice){
			case 'a' :
        		cin >> x;
        		h->Insert(x);
        		break;

			case 'p' :
        		h->Print();
        		cout << endl;
        		break;
        		
			case 'd' :
        		cout << h->Remove() << endl;
        		break;
        	
        	case 'e' :
        		break;
       }
    }
}
