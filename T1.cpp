#include<iostream>
using namespace std;

class Node{
	public:
		int key;
		Node* Left;
		Node* Right;
	
	Node(int data){
		key = data;
		Left = NULL;
		Right = NULL;
	}
};

class BST{
	public:
		Node* root;
		
		BST(){
			root = NULL;
		}
		
		bool Search(Node* root , int x){
			if(root == NULL){
				return 0;
			}
			if(root->key == x){
				return 1;
			}
			else if(x < root->key){
				return Search(root->Left,x);
			}
			else{
				return Search(root->Right,x);
			}
		}
		
		Node* Insert(Node* root , int x){
			if(root == NULL){
				root = new Node(x);
			}
			else if(x < root->key){
				root->Left = Insert(root->Left,x);
			}
			else{
				root->Right = Insert(root->Right,x);
			}
			return root;
		}
		
		Node* Remove(Node* n , int x){
			if(n == NULL){
				return NULL;
			}
			if(x == n->key){
				if(n->Left == NULL && n->Right == NULL){
					return NULL;
				}
				else if(n->Left != NULL && n->Right != NULL){
					Node* temp = n->Right;
					while(temp && temp->Left != NULL){
						temp = temp->Left;
					}
					n->key = temp->key;
					n->Right = Remove(n->Right,temp->key);
				}
				else if(n->Left != NULL && n->Right == NULL){
					if(root == n){
						root = n->Left;
						return root;
					}
					else{
						return n->Left;
					}
				}
				else if(n->Left == NULL && n->Right != NULL){
					if(root == n){
						root = n->Right;
						return root;
					}
					else{
						return n->Right;
					}
				}
			}
			else if(x < n->key){
				n->Left = Remove(n->Left,x);
			}
			else{
				n->Right = Remove(n->Right,x);
			}
			return n;
		}
		
		int Height(Node* n){
			if(n == NULL){
				return 0;
			}
			
			int Height_Left = Height(n->Left);
			int Height_Right = Height(n->Right);
			
			if(Height_Left > Height_Right){
				return Height_Left + 1;
			}
			else{
				return Height_Right + 1;
			}
		}
		
		void Tree_Level(Node*root , int level){
			if(root == NULL){
				return;
			}
			if(level == 1){
				cout << root->key << ",";
			}
			else if(level > 1){
				Tree_Level(root->Left,level-1);
				Tree_Level(root->Right,level-1);
			}
		}
		
		void Print(Node* root){
			int i , h = Height(root);
			
			for(i=1; i<=h; i++){
				Tree_Level(root,i);
				cout << "|";
			}
		}
		
		void Preorder(Node* root){
			if(root == NULL){
				return;
			}
			cout << root->key << ",";
			Preorder(root->Left);
			Preorder(root->Right);
		}
		
		void Inorder(Node* root){
			if(root == NULL){
				return;
			}
			Inorder(root->Left);
			cout << root->key << ",";
			Inorder(root->Right);
		}
		
		void Postorder(Node* root){
			if(root == NULL){
				return;
			}
			Postorder(root->Left);
			Postorder(root->Right);
			cout << root->key << ",";
		}
};

int main(){
	int input , size , i;
	char check;
	
	BST *b = new BST();
	
	while(cin >> check){
		switch(check){
			case 'a' :
				cin	>> input;
				b->root = b->Insert(b->root,input);
				break;
				
			case 'd' :
				cin	>> input;
				b->Remove(b->root,input);
				break;
				
			case 'b' :
				b->Print(b->root);
				cout << endl;
				break;
				
			case 'p' :
				b->Preorder(b->root);
				cout << endl;
				break;
			
            case 'i' :
				b->Inorder(b->root);
				cout << endl;
				break;
			
			case 't' :
				b-> Postorder(b->root);
				cout << endl;
				break;
			
			case 'x' :
        		break;
		}
	}

	return 0;
}
