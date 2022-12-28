#include<stdio.h>
#include<stdlib.h>
struct node* createnode(int element);
struct node* insert(struct node*root,int element);
struct node*search(struct node*root,int key);
struct node* inorder(struct node*root);
struct node{
	int key;
	struct node*lch;
	struct node*rch;
};

struct node* createnode(int element)
{
	struct node*node;
	node=(struct node*)malloc(sizeof(struct node));
	node->key=element;
	node->lch=NULL;
	node->rch=NULL;
	return node;
}

struct node* insert(struct node*root,int element)
{
	if(root==NULL)
	{
		root=createnode(element);
	}
	else if(element < root->key)
	{
		root->lch=insert(root->lch,element);
	}
	else //(element>=root->key)
	{
		root->rch=insert(root->rch,element);
	}
	return root;
}
/*struct node* insert_right(struct node*root->rch,element)
{
	root->rch=createnode(element);
	return root->rch;
}	

struct node* insert_left(struct node*root->lch,element)
{
	root->lch=createnode(element);
	return root->lch;
}
no need to write separate functions in that only we can call recursively
*/
struct node *search(struct node*root,int key)
{
	if(root==NULL || root->key==key)
	{
		return root;
	}
	if(key<root->key)
	{
	    return search(root->lch,key);
	 }
	 if(key>root->key)
	 {
	 	return search(root->rch,key);
	 }
}
struct node* inorder(struct node*root)
{
	if(root==NULL)
		return 0;
	inorder(root->lch);
	printf("%d\n",root->key);
	inorder(root->rch);
}
	

int main(){
	struct node*root=NULL,*result;
	
	root=insert(root,1);
	root=insert(root,4);
	root=insert(root,10);
	root=insert(root,19);
	root=insert(root,2);
	root=insert(root,13);
	root=insert(root,13);
	result=search(root,999);
	if(result == NULL)
		printf("notfound\n");
	else
	 printf("element found");
	 
	 inorder(root);
	 
}
	
