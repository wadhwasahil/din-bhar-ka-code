#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node{
	int data;
	node *left,*right;
	int height;
	node(int val){
		left=right=NULL;
		height=1;
		data=val;
	}
}*root=NULL;
int get_height(node *p){
	if(p==NULL) return 0;
	return p->height;
}
int get_balance(node *p){
	if(p==NULL) return 0;
	else return get_height(p->left)-get_height(p->right);
}
node * right_rotate(node *y){
	node *x=y->left;
	node *T1=x->right;

	x->right=y;
	y->left=T1;

	y->height= max(get_height(y->left),get_height(y->right))+1;
	x->height= max(get_height(x->left),get_height(x->right))+1;
	return x;
}

node * left_rotate(node *x){
	node *y = x->right;
	node *T2 = y->left;

	y->left=x;
	x->right=T2;

	y->height= max(get_height(y->left),get_height(y->right))+1;
	x->height= max(get_height(x->left),get_height(x->right))+1;
	return y;
}
node *push(node *p,int val){
	if(p==NULL){
		p = new node(val);
		return p;
	}
	if(p->data > val) p->left=push(p->left,val);
	if(p->data < val) p->right = push(p->right,val);
	p->height=max(get_height(p->right),get_height(p->left))+1;
	int balance = get_balance(p);
	if(balance>1 && val < p->left->data)
		return right_rotate(p);
	if(balance>1 && val>p->left->data){
		p->left=left_rotate(p->left);
		return right_rotate(p);
	}
	if(balance<-1 && val > p->right->data) return left_rotate(p);
	if(balance<-1 && val<p->right->data){
		p->right=right_rotate(p->right);
		return left_rotate(p);
	}
return p;
}

node *inorder_successor(node *p){
	while(p->left) p=p->left;
	return p;
}
node *pop(node *p,int val){
	if(p==NULL) return p;
	if(p->data > val) p->left = pop(p->left,val);
	else if(p->data < val) p->right = pop(p->right,val);
	else{
		if(p->left==NULL){
			node *temp = p->right;
			free(p);
			return temp;
		}
		else if(p->right==NULL){
			node *temp = p->left;
			free(p);
			return temp;
		}
		else{
			node *temp=inorder_successor(p->right);
			swap(p->data,temp->data);
			p->right = pop(p->right,temp->data);
		}
	}
	p->height = max(get_height(p->left),get_height(p->right))+1;
	int balance = get_balance(p);
	if(balance>1 && get_balance(p->left)>=0 ) return right_rotate(p);
	if(balance>1 && get_balance(p->left)<0){
		p->left=left_rotate(p->left);
		return right_rotate(p);
	}
	if(balance<-1 && get_balance(p->right) <=0) return left_rotate(p);
	if(balance<-1 && get_balance(p->right)>0){
		p->right = right_rotate(p->right);
		return left_rotate(p);
	}
	return p;
}
void preorder(node *p){
	if(p==NULL) return;
	cout<<p->data<<" ";
	preorder(p->left);
	preorder(p->right);
}
int main(){
  root = push(root, 10);
  root = push(root, 20);
  root = push(root, 30);
  root = push(root, 40);
  root = push(root, 50);
  root = push(root, 25);
	preorder(root);
	printf("\n");
	root = pop(root, 10);
	preorder(root);
return 0;
}
