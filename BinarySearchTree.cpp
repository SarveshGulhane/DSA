#include<iostream>
using namespace std;
 
struct node
{
	char data;
	struct node *left,*right;
};

node* Insert(node *root,int data)
{
	if(root == NULL)
     {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

int height(node* root)
{
    	int l = root->left ? height(root->left) : 0;
    	int r = root->right ? height(root->right) : 0;
    	if(l>r)
        	return (1 + l);
    	else
        	return (1 + r);
}

void printGivenLevel(struct node* root, int level) 
{ 
	if (root == NULL) 
        	return; 
    	if (level == 1) 
        	printf("%d ", root->data); 
    	else if (level > 1) 
    	{ 
        	printGivenLevel(root->left, level-1); 
        	printGivenLevel(root->right, level-1); 
    	} 
} 

void printLevelOrder(struct node* root) 
{ 
    	int h = height(root); 
    	int i; 
    	for (i=1; i<=h; i++) 
    	{ 
        	printGivenLevel(root, i); 
        	cout<<endl; 
    	} 
} 

node* search(node* root,int num)
{
    	if (root == NULL || root->data == num) 
       	return root; 
    	if (root->data < num) 
       	return search(root->right, num); 
    	return search(root->left, num);
} 

node* minValueNode(node* root) 
{ 
    	node* current = root; 
    	while (current && current->left != NULL) 
        	current = current->left; 
    	return current; 
}

node* deleteNode(node* root, int num1) 
{ 
    	if (root == NULL) 
        	return root; 
    	if (num1 < root->data) 
        	root->left = deleteNode(root->left, num1); 
    	else if (num1 > root->data) 
        	root->right = deleteNode(root->right, num1); 
    	else
    	{ 
        	if (root->left == NULL) 
        	{ 
            	node* temp = root->right; 
            	delete root; 
            	return temp; 
        	} 
        	else if (root->right == NULL) 
        	{ 
            	node* temp = root->left; 
            	delete root; 
            	return temp; 
        	} 
        	node* temp = minValueNode(root->right); 
        	root->data = temp->data; 
        	root->right = deleteNode(root->right, temp->data); 
    	} 
    	return root; 
}

int main()
{
	node* root = NULL;
     int keys[10],num,i;

     cout<<"Enter keys:\n";
     for(i=0;i<10;i++)
     {
          cin>>keys[i];
     }

	for (i=0;i<10;i++)
     {
		root = Insert(root, keys[i]);
     }
	
	cout<<"Level viz:\n"<<endl;
	printLevelOrder(root);

	
	cout<<"\nEnter the element you want to search in the binary search tree\n";
    	cin>>num;
    	node* a=NULL;
    	a=search(root,num);
    	if(a!=NULL) 
        	cout<<"The element is found\n";
    	else
        	cout<<"The element was not found\n";

	
	cout<<"\nEnter the data you want to delete: ";
    	cin>>num;
    	root=deleteNode(root,num);
    	printLevelOrder(root);

    	return 0;
}
