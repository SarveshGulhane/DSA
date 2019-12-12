#include<iostream>
using namespace std;
 
struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
};

//Function to visit nodes in Preorder
void Preorder(struct Node *root)
{
	// base condition for recursion
	if(root == NULL) return;

	printf("%d ",root->data); 
	Preorder(root->left);     
	Preorder(root->right);    
}

//Function to visit nodes in Inorder
void Inorder(Node *root)
{
	if(root == NULL) return;

	Inorder(root->left);       
	printf("%d ",root->data);  
	Inorder(root->right);      
}

//Function to visit nodes in Postorder
void Postorder(Node *root)
{
	if(root == NULL) return;

	Postorder(root->left);   
	Postorder(root->right);   
	printf("%d ",root->data); 
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,int data)
{
	if(root == NULL)
     {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main()
{
	Node* root = NULL;
	
     int keys[10];
     cout<<"Enter keys:\n";
     for(int i=0;i<10;i++)
     {
          cin>>keys[i];
     }

	for (int k=0;k<10;k++)
     {
		root = Insert(root, keys[k]);
     }

	//Print Nodes in Preorder. 
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"\n";
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	//Print Nodes in Postorder
	cout<<"Postorder: ";
	Postorder(root);
	cout<<"\n";
}
