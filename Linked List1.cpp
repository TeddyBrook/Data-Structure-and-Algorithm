#include<iostream>
using namespace std;

class Node{
	public:
		Node *next = NULL;
		int id;
		Node(int id){
			this->id = id;
		}
};

class LinkList{
	public:
		Node *head;
		Node *tail = NULL;
	
	char search(int id){
        for(Node *ptr = head; ptr != NULL; ptr = ptr->next){
            if(ptr->id == id){
                return false;
            }
        }
        return true;
    }
    
	void print(){
		for(Node *ptr = head; ptr != NULL; ptr = ptr->next){
            cout << ptr->id << " ";
        }
        cout << "\n";
	}
	
	void insert_after(int id , int data){
		Node *neww = new Node(id);
		
		if(head == NULL){
			head = neww;
			print();
			return;
		}
		else if(search(id) == false){
			return;
		}
		else{
			Node *prev = head;
			
			while(prev != NULL && prev->id != data){
				prev = prev->next;
				
				if(prev->next == NULL && prev->id != data){
					prev->next = neww;
					print();
					return;
				}
			}
			
			if(prev != NULL){
				neww->next = prev->next;
				prev->next = neww;
				print();
				return;
			}
		}
	}
	
	void insert_before(int val , int data){
		Node *neww = new Node(val);
		
		if(head == NULL){
			head = neww;
			print();
			return;
		}
		
		if(search(val) == false){
			return;
		}
		
		if(head->id == data){
			neww->next = head;
			head = neww;
			print();
			return;
		}
		
		Node *prev = head;
        	
        while(prev->next != NULL && prev->next->id != data){
        	prev = prev->next;
        }

        if(prev->next == NULL){
            prev->next = neww;
            print();
            return;
        }
		neww->next = prev->next;
        prev->next = neww;
        print();
	}
	
	void remove(int id){
		if(head->id == id){
			head = head->next;
		}
		else if(search(id) == true){
			return;
		}
		else{
			for(Node *ptr = head; ptr != NULL; ptr = ptr->next){
                if(ptr->next->id == id){
                    ptr->next = ptr->next->next;
                    break;
                }
				else if(ptr->next == tail){
                    ptr->next = NULL;
                    tail = ptr;
                    break;
                }
            }
		}
		print();
	}
};

int main(){
	LinkList l;
    
    int id , data;
    char check;
    
    cin >> check;
    
	while(check != 'E'){
		switch(check){
			case ('A') :
				cin >> id >> data;
                l.insert_after(id , data);
                break;
                
			case ('I') :
				cin >> id >> data;
                l.insert_before(id , data);
                break;
			
			case ('D') :
				cin >> id;
                l.remove(id);
                break;
		}
		cin >> check;
	}
	return 0;
}
