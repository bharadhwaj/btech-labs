/* Program to implement Binary Search Tree. */

#include<iostream>
#include<stdlib.h>
using namespace std;
class bst {
	public:
		struct node {
			int data;
			struct node *lchild, *rchild;
		};
		typedef struct node node;
		node* bstinsert(node *temp, int elt);
		int bstsearch(node *temp, int elt);
		node* findelt(node *temp, int ch);
		node* bstdelete(node *temp, int elt);
		void preorder(node *temp);
		void inorder(node *temp);
		void postorder(node *temp);
};
bst::node *root = NULL, *t, *t1;
bst::node* bst::bstinsert(bst::node* root, int elt) {
	node* newnode = (node*) malloc (sizeof(node));
	newnode->data = elt;
	newnode->lchild = newnode->rchild = NULL;
	if(root == NULL) {
		root = newnode;  	
		cout<<"\n\n Element Successfully Inserted! \n\n";
	} 
	else if( root->data > elt) 
	    root->lchild = bstinsert(root->lchild, elt);   	        
	else if( root->data < elt)
	    root->rchild = bstinsert(root->rchild, elt);
	else
	    cout<<"\n Error: Element already exist!\n\n";
	return root;
}

int bst::bstsearch(node *temp, int elt) {
	if(temp != NULL) { 
		if(elt == temp->data)
    		return 1;
  	  	else if(elt < temp->data)
   		    return bstsearch(temp->lchild, elt);
  	  	else if(elt > temp->data)
    	    return bstsearch(temp->rchild, elt);
    }
    else
    	return 0;
       
}

bst::node* bst::findelt(bst::node* temp, int ch) {
	if(ch == 0){ //To find Minimum
		bst::node *root = NULL;
		while(temp->lchild != NULL)
			temp = temp->lchild;
	}
	else {//To find Maximum
			while(temp->rchild != NULL)
				temp = temp->rchild;
	}
	return temp;	
}

bst::node* bst::bstdelete(bst::node* temp, int elt) {
		bst::node *temp1;
		if(elt == temp->data) {
			root = temp;
			if( temp->rchild == NULL) {
				temp = temp->lchild;
				temp1 = temp;
				free(temp1);
			}
			else if(temp->rchild != NULL){
				node* temp1 = findelt(temp->rchild,0);
				temp->data = temp1->data;
				temp->rchild = bstdelete(temp->rchild,temp->data);
			}
			
				
		}
		else if(elt < temp->data)
			temp->lchild = bstdelete(temp->lchild, elt);
		else if(elt > temp->data)
			temp->rchild = bstdelete(temp->rchild, elt);
	return temp; 
}

void bst::preorder(node *temp) {
	if(temp != NULL) {
		cout<<temp->data<<" -> ";
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}

void bst::inorder(node *temp) {
	if(temp != NULL) {
		inorder(temp->lchild);
		cout<<temp->data<<" -> ";
		inorder(temp->rchild);
	}
}

void bst::postorder(node *temp) {
	if(temp != NULL) {
		postorder(temp->lchild);
		postorder(temp->rchild);
		cout<<temp->data<<" -> ";
	}
}

int main() {
	int ch, ch1, elt;
	bst obj;
	
	do {
		cout<<"\t  Binary Search Tree \n\t ********************";
		cout<<"\n 1. Insertion. \n 2. Searching. \n 3. Deletion. \n 4. Displaying. \n 5. Exit. \n";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"\n Enter the element to be inserted: ";
				cin>>elt;
				root = obj.bstinsert(root, elt);
				break;
			case 2:
				cout<<"\n Enter the element to be searched: ";
				cin>>elt;
				if(obj.bstsearch(root, elt) == 1) 
					cout<<"\n Element "<<elt<<" is present in Binary Search Tree. \n\n";
				else
					cout<<"\n Element "<<elt<<" is not present in Binary Search Tree. \n\n";
				break;
			case 3:
				do {
					cout<<"\n\t Delete Options \n\t ***************";
					cout<<"\n 1. Ordinary Deletion. \n 2. Ascending Order Deletion. \n 3. Descending Order Deletion. \n 4. Exit.";
					cout<<"\n Enter your choice: ";
					cin>>ch1;
					t1 = root;
					switch(ch1) {
						case 1:
							cout<<"\n Enter the element to be deleted: ";
							cin>>elt;
							if(obj.bstsearch(root, elt) != 1)
        					cout<<"\n Error: Element not in the Binary Search Tree.\n\n";
    						else {
    							root = obj.bstdelete(root, elt);
    							cout<<"\n\n Element Successfully Deleted! \n\n";
    							cout<<"\n Elements in Inorder after deletion is: \n";
							obj.inorder(root);
    						}
    						break;
						case 2:
							t = obj.findelt(t1, 0);
							root = obj.bstdelete(root, t->data);
							cout<<"\n Elements in Inorder after deletion is: \n";
							obj.inorder(root);
							break;
						case 3:
							t = obj.findelt(t1, 1);
							root = obj.bstdelete(root, t->data);
							cout<<"\n Elements in Inorder after deletion is: \n";
							obj.inorder(root);
							break;
						case 4:
							break;
						default:
							cout<<"Error: Invalid entry! Try with numbers 1-4. \n\n";
					}
				}while(ch1 != 4);
				break;
			case 4:
				do {
					cout<<"\t Display Options \n\t ****************";
					cout<<"\n 1. Inorder Traversal. \n 2. Preorder Traversal. \n 3. Postorder Traversal. \n 4. Exit.";
					cout<<"\n Enter your choice: ";
					cin>>ch1;
					switch(ch1) {
						case 1:
							cout<<"\n Elements in Inorder is: \n";
							obj.inorder(root);
							cout<<"\n\n";
							break;
						case 2:
							cout<<"\n Elements in Preorder is: \n";
							obj.preorder(root);
                            cout<<"\n\n";
							break;
						case 3:
							cout<<"\n Elements in Postorder is: \n";
							obj.postorder(root);
							cout<<"\n\n";
							break;
						case 4:
							break;
						default:
							cout<<"Error: Invalid entry! Try with numbers 1-4. \n\n";
					}
				}while(ch1 != 4);
				break;
			case 5:
				break;
			default:
				cout<<"Error: Invalid entry! Try with numbers 1-5. \n\n";
		}
	}while(ch != 5);
	cout<<"\n";
}
