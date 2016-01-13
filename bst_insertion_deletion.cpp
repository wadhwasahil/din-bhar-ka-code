#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node {
int data;
node *left,*right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};
node *root = NULL;
node *push(node *p,int val) {
	if(p == NULL){
		p = new node(val);
		return p;
	}
	else if(p->data >= val) p->left = push(p->left,val);
	else p->right = push(p->right,val);


	return p;
}

node *inorder_successor(node *p){
	node *ptr = p -> right;
	while(ptr -> left){
		ptr = ptr->left;
	}
	return ptr;
}
node *pop(node *p,int val){
	if(p == NULL) return p;
	if(val < p->data) p->left = pop(p->left,val);
	else if(val > p->data) p->right = pop(p->right,val);
	else{
		if(p->left==NULL){
			node *q = p->right;
			free(p);
			return q;
		}
		else if(p->right == NULL){
			node *q = p->right;
			free(p);
			return q;
		}
		else{
			node *q = inorder_successor(p);
			swap(p->data,q->data);
			p->right = pop(p->right,q->data);
		}
	}
	return p;
}

void disp(node *p){
	if(p == NULL) return;
	disp(p->left);
	printf("%d ",p->data);
	disp(p->right);
}

int main(){
root = push(root,50);
root = push(root,30);
root = push(root,20);
root = push(root,40);
root = push(root,70);
root = push(root,60);
root = push(root,80);
disp(root);
printf("\n");
root = pop(root,60);
disp(root);
printf("\n");
root = pop(root, 50);
disp(root);
printf("\n");
return 0;
}
