#include <iostream>
using namespace std;

class Node{
	public:
		int value , height;
		
		Node *Left;
		Node *Right;
		
		Node(int data){
			value = data;
			height = 1;
			Left = NULL;
			Right = NULL;
		}
};

class AVL{
	public:
		Node *root;
		
		AVL(int value){
			root = new Node(value);
		}
		
		bool Search(int value){
			Node *i = root;
			while(true){
				if(i->value > value && i->Left != NULL){
					i = i->Left;
				}
				else if(i->value < value && i->Right != NULL){
					i = i->Right;
				}
				else if(i->value == value){
					return true;
				}
				else{
					return false;
				}
			}
		}

		int height(Node* n){
			if(!n){
				return 0;
			}
			return n->height;
		}

		Node* Rotation_Right(Node* y){
			Node* x = y->Left;
			Node* T2 = x->Right;
			
			x->Right = y;
			y->Left = T2;
			y->height = max(height(y->Left) , height(y->Right)) + 1;
			x->height = max(height(x->Left) , height(x->Right)) + 1;
			
			return x;
		}

		Node* Rotation_Left(Node* x){
			Node* y = x->Right;
			Node* T2 = y->Left;
			
			y->Left = x;
			x->Right = T2;
			x->height = max(height(x->Left) , height(x->Right)) + 1;
			y->height = max(height(y->Left) , height(y->Right)) + 1;
			
			return y;
		}

		int GetBalance(Node* b){
			if(!b){
				return 0;
			}
			
			return height(b->Left) - height(b->Right);
		}

		Node* Insert(Node* current , int value){
			if(!current){
				return new Node(value);
			}
			if(value < current->value){
				current->Left = Insert(current->Left , value);
			}	
			else if(value > current->value){
				current->Right = Insert(current->Right , value);
			}
			else{
				return current;
			}
			
			current->height = 1 + max(height(current->Left) , height(current->Right));

			int balance = GetBalance(current);

			if(balance > 1 && value < current->Left->value){
				return Rotation_Right(current);
			}
			if(balance < -1 && value > current->Right->value){
				return Rotation_Left(current);
			}
			if(balance > 1 && value > current->Left->value){
				current->Left = Rotation_Left(current->Left);
				return Rotation_Right(current);
			}
			if(balance < -1 && value < current->Right->value){
				current->Right = Rotation_Right(current->Right);
				return Rotation_Left(current);
			}

			return current;
		}

		void Add(int value){
			root = Insert(root , value);
		}

		void Preorder(Node *root){
			if(root != NULL){
				cout << root->value << " ";
				Preorder(root->Left);
				Preorder(root->Right);
			}
		}

		void Inorder(Node *root){
			if(root != NULL){
				Inorder(root->Left);
				cout << root->value << " ";
				Inorder(root->Right);
			}
		}

		void Delete(int data){
			root = Remove(root , data);
		}

		Node* Remove(Node* root , int key){
			if(!root){
				return root;
			}
			if(key < root->value){
				root->Left = Remove(root->Left , key);
			}
			else if(key > root->value){
				root->Right = Remove(root->Right , key);
			}
			else{
				if(!root->Left || !root->Right){
					Node* temp = root->Left ? root->Left : root->Right;
					if(!temp){
						temp = root;
						root = NULL;
					}
					else{
						*root = *temp;
					}
					delete temp;
				}
				else{
					Node* temp = Min(root->Right);
					root->value = temp->value;
					root->Right = Remove(root->Right , temp->value);
				}
			}

			if(!root){
				return root;
			}
			
			root->height = 1 + max(height(root->Left) , height(root->Right));

			int balance = GetBalance(root);

			if(balance > 1 && GetBalance(root->Left) >= 0){
				return Rotation_Right(root);
			}
			if(balance > 1 && GetBalance(root->Left) < 0){
				root->Left = Rotation_Left(root->Left);
				return Rotation_Right(root);
			}
			if(balance < -1 && GetBalance(root->Right) <= 0){
				return Rotation_Left(root);
			}
			if(balance < -1 && GetBalance(root->Right) > 0){
				root->Right = Rotation_Right(root->Right);
				return Rotation_Left(root);
			}

			return root;
		}

		Node* Min(Node* root){
			Node* current = root;
			
			while(current && current->Left){
				current = current->Left;
			}
				
			return current;
		}
};

int main(){
	AVL t(10);
	int value;
	char check;

	while(cin >> check){	
		switch (check){
			case 'a':
				cin >> value;
				t.Add(value);
				break;

			case 'd':
				cin >> value;
				t.Delete(value);
				break;

			case 'p':
				t.Preorder(t.root);
				cout << endl;
				break;

			case 'x':
				break;
		}
	}
	
	return 0;
}
