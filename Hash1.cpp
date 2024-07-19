#include<iostream>
using namespace std;

int size = 17;

struct HashTable{  
    int key = -1;  
    string value = "-";
    
    HashTable *emp1;  
    HashTable *emp2; 
	 
    HashTable(int key , string value){  
        this->key = key;  
        this->value = value;  
        this->emp1 = NULL;  
    }  
};

class separate{  
	public: 
    	HashTable **ptr;
    	
    	int HashFunction(int k){  
        	return k % size;  
		}
		
    	separate(){  
        	ptr = new HashTable*[size];
        	
        	for(int i=0; i<size; i++){
        		ptr[i] = NULL; 
			}          	 
    	}
    	 
    	void insert(int key , string value){ 
        	int val = HashFunction(key); 
			bool check = true;
			 
        	HashTable* emp2 = NULL;  
        	HashTable* data = ptr[val];
        	
        	while(data != NULL){
            	if(data->key == key){
                	check = false;
                	break;
            	}
				else{
                	emp2 = data;  
                	data = data->emp1;
            	}   
        	}

        	if(check){
            	if(data == NULL){
                	data = new HashTable(key , value);
                	if(emp2 == NULL){  
                    	ptr[val] = data;  
                	}
					else{  
                    	emp2->emp1 = data;
                	}
            	}
				else{
                	data->value = value;  
            	}
        	}
    	}
    	
    	void search(int key){  
        	int val = HashFunction(key);  
        	bool check = false;
        	
        	HashTable* data = ptr[val];  

        	if(key >= 0){
            	if(data != NULL){  
                	while(data != NULL){
                    	if(data->key == key){  
                        	check = true;  
                    	}  
                    	if(check){ 
                        	cout << data->value << endl;
                        	break;
                    	}  
                    	data = data->emp1;  
                	}
            	}  
                if(!check){
                    cout << "-" << endl; 
                }
        	}
        }
        
    	void print(){
			for(int i=0; i<size; i++){
            	HashTable *current = ptr[i];
            	
            	if(current != NULL){
                	while(current != NULL){
                    	cout << "(" << current->key << "," << current->value << ") ";
                    	current = current->emp1;
                	}
            	}
            	else{
                	cout << "(-1,-)";
            	}
            	cout << "\n";
        	}
    	}
};

int main(){  
    separate table;
    
    int key;
    char check;
    string value;
    
    while(cin >> check){    
        switch(check){  
            case 'a' :   
                cin >> key;  
                cin >> value;  
                table.insert(key , value);  
                break;
				  
            case 's' :   
                cin >> key;  
                table.search(key);  
                break;
                
            case 'p' :  
                table.print();
                break;
				  
            case 'e' :  
                return 0;
                break;
        }  
    }
}  
