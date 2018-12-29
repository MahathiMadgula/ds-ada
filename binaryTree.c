/*Implemetation of a Binary Tree using C
Submitted by M.Mahathi.
(Done on 21st Dec 2018)
*/

#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *left,*right;
};

typedef struct NODE node;
node *last;	//Global Variable that stores the last node(used during deletion)
node* root;
int flag;
 //Queue used during insertion
 node* q[100]; int front=0,rear=-1;

//Function Declarations
node* getnode(int);
node* insert(node*,int);
void delete(node*,node*,int);
int max(int a, int b);
int height(node*,int);
void print(node*,int);
void levelord(node* );
void remov(node* root,node* last);
void preorder(node* root,int val);

node* getnode(int val){
//Function to allocate space eqivalent to struct NODE
	node* nn=(node*)malloc (sizeof(node));
	nn->data=val;
	nn->left=NULL;nn->right=NULL;
}

node* insert(node* root,int val){ 
//Inserts nodes in the level-order
	node* nn=getnode(val); 
	if(root==NULL){ 
		return nn; 
	} 
	else{ 
		q[++rear]=root; 
		do{ 
			node* head=q[front++]; 
			if(head->left!=NULL){ 
				q[++rear]=head->left; 
			} 
			else{ 
				head->left=nn;return root; 
			} 
			if(head->right!=NULL){ 
				q[++rear]=head->right; 
			} 
			else{ 
				head->right=nn;return root; 
			} 
			 
		}while(front!=rear); 
	} 
} 

int height(node* root,int count){
//Gets the height of the tree
	if(root!=NULL){
		count=count+1;
		return max(height(root->left,count),height(root->right,count));
	}
	else
		return count;
}

void delete(node* head,node* root,int val){
//Finding node whose value is equal to val by performing pre-order traversal	
	if(root!=NULL){
		if(root->data==val){
			remov(head,last);//remove the last-node
			if(flag==0){	/*flag=0 => First node with (value=value-to-be-deleted) is found, replace it's value with last-node's 						value and remove last-node*/
				root->data=last->data;remov(head,root);}
			else{
	/*flag=1 => Another duplicate is found,remove this duplicate node with (value=value-to-be-deleted)*/				
				remov(head,root);
			}
			flag=1;
			return;
		}
		delete(head,root->left,val);
		delete(head,root->right,val);
	}
	else return;	
}

void remov(node* root,node* lst){
	if(root->left!=NULL || root->right!=NULL){
		if(root->left){
			if(root->left->data==lst->data){root->left=NULL;return;}
		}	
		if(root->right){
			if(root->right->data==lst->data){root->right=NULL;return;}
		}
		else{
		remov(root->left,last);
		remov(root->right,last);}
	}
	else	return;
}

int max(int a, int b){
	if(a>b)	return a;
	else	return b;
}


void print(node* root,int level){
//Recursive function that prints elements of a particular level
  if(level>=1){
	if(root==NULL)	return;
	else if(level==1){
		last=root;	//Finally stores the last node which can replace the node-to-be-deleted		
		printf("%d ",root->data);
	}
	else{
		print(root->left,level-1);
		print(root->right,level-1);
	}
  }
}

void levelord(node* root){
//For each level, calls print function to print elements of that level(starting from root;towards leaves)
	int i;
	int h=height(root,0);//printf("\nHeight=%d",h);
	for(i=1;i<=h;i++){
		print(root,i);
		printf("\n");
	}
}

int main(){
	root=NULL; //Root node of the tree
	int del;
	int ins,inp=1;
	while(inp){
	  printf("\nHit 1 to enter element, 2 to delete, else 0\n");scanf("%d",&inp);
	  switch(inp){
	    case 1:
		printf("Enter data to be inserted\n");
		scanf("%d",&ins);
		root=insert(root,ins);
		printf("levelorder traversal yields:\n");
		levelord(root);//Last gets updated after every delete
		printf("\nLst=%d\n",last->data);
		break;
	    case 2:
		flag=0;
		printf("\nEnter the element to be deleted: ");
		scanf("%d",&del);
		if(last->data==del){	
			flag=1;
			remov(root,last);
		}
		delete(root,root,del);
		if(flag==1){
		  printf("levelorder traversal yields:\n");
		  levelord(root);
		}
		else{
		  printf("Element not found\n");
		}
		printf("\nLst=%d\n",last->data);
		break;
	    default:
		printf("Final tree(levelorder):\n");levelord(root);
		return 0;
	  }
	}

	return 0;
}
