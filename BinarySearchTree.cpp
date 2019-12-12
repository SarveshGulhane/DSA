#include<iostream>
using namespace std;
 
struct node
{
	char data;
	struct node *left;
	struct node *right;
};

void preorder(struct node *root)
{
	if(root == NULL) return;

	printf("%d ",root->data); 
	preorder(root->left);     
	preorder(root->right);    
}

void inorder(node *root)
{
	if(root == NULL) return;

	inorder(root->left);       
	printf("%d ",root->data);  
	inorder(root->right);      
}

void postorder(node *root)
{
	if(root == NULL) return;

	postorder(root->left);   
	postorder(root->right);   
	printf("%d ",root->data); 
}

node* insert(node *root,int data)
{
	if(root == NULL)
     {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = insert(root->left,data);
	else 
		root->right = insert(root->right,data);
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

void printlevel(struct node* root, int level) 
{ 
	if (root == NULL) 
        	return; 
    	if (level == 1) 
        	printf("%d ", root->data); 
    	else if (level > 1) 
    	{ 
        	printlevel(root->left, level-1); 
        	printlevel(root->right, level-1); 
    	} 
} 

void levelviz(struct node* root) 
{ 
    	int h = height(root); 
    	int i; 
    	for (i=1; i<=h; i++) 
    	{ 
        	printlevel(root, i); 
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

node* minvalue(node* root) 
{ 
    	node* current = root; 
    	while (current && current->left != NULL) 
        	current = current->left; 
    	return current; 
}

node* deleten(node* root, int num1) 
{ 
    	if (root == NULL) 
        	return root; 
    	if (num1 < root->data) 
        	root->left = deleten(root->left, num1); 
    	else if (num1 > root->data) 
        	root->right = deleten(root->right, num1); 
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
        	node* temp = minvalue(root->right); 
        	root->data = temp->data;
        	root->right = deleten(root->right, temp->data); 
    	} 
    	return root; 
}
 
int main()
{
	node* root = NULL;
     int keys[100],num,n,op;

	cout<<"Enter no. of Nodes: ";
	cin>>n;

     cout<<"Enter keys:\n";
     for(int i=0;i<n;i++)
     {
          cin>>keys[i];
     }

	for (int k=0;k<n;k++)
     {
		root = insert(root, keys[k]);
     }

	do
	{
		cout<<"\nEnter Operation: 1.Pre/In/Post-order 2.Level viz 3.Search 4.Delete\n";
		cin>>op;

		switch (op)
		{
		case 1:
			cout<<"\nPreorder: ";
			preorder(root);
			cout<<"\nInorder: ";
			inorder(root);
			cout<<"\nPostorder: ";
			postorder(root);
			cout<<endl;
			break;
		
		case 2:
			cout<<"\nLevel viz:\n";
			levelviz(root);
			break;

		case 3:
		{
			cout<<"\nEnter the element you want to search: ";
    			cin>>num;
    			node* a=NULL;
    			a=search(root,num);
    			if(a!=NULL) 
        			cout<<"The element is found\n";
    			else
        			cout<<"The element was not found\n";
		}
			break;

		case 4:
			cout<<"\nEnter the data you want to delete: ";
    			cin>>num;
    			root=deleten(root,num);
    			levelviz(root);
			break;
		}
	}while(op!=5);

     return 0;
}
