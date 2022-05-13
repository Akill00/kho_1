#include <iostream>

using namespace std;

struct Node{

   int key;
   int bal; // 0: can bang // -1: lech trai // 1:lech phai
   Node *left;
   Node *right;
   Node *parent;
};
struct Tree{
   Node *root;
   int NumberNode;
   int NumeberLeaf;
   int Hight;

};
Node* createNode(int k);
void InitTree(Tree &T);
int Put(Node *&root, Node* x, Node* parent);
int PutNodeTree(Tree &tree, int x);
void Rotate_LL(Node *&T);
void Rotate_LR(Node *&T);
void Rotate_RR(Node *&T);
void Rotate_RL(Node *&T);
int main()
{
    Tree AVL;
    InitTree(AVL);
    PutNodeTree(AVL,6);
    PutNodeTree(AVL,5);
    PutNodeTree(AVL,4);
    //.....


    return 0;
}
Node* createNode(int k){
   Node *n=new Node;
   n->key=k;
   n->bal=0;
   n->left=NULL;
   n->right=NULL;
   n->parent=NULL;
   return n;
}

void InitTree(Tree &T){
   T.root=NULL;
   T.NumberNode=0;
   T.NumberNode=0;
   T.NumeberLeaf=0;
   T.Hight=0;
}

int Put(Node* &root, Node * x, Node* parent)
{
    // return 0 neu khong lm thay doi chieu cao
    // return 1 chieu cao thay doi
    // return -1 khong chen
    int res=0;
	if(root!=NULL)
	{
		if(root->key == x->key)return -1;
		if(root->key>x->key){

                res=Put(root->left, x,root);
                if(res<1) return res;  // khong lm thay doi chieu cao

                switch(root->bal){
                  case -1: if(root->left->bal==-1)  // LL
                           Rotate_LL(root);
                           else
                             if(root->left->bal==1)   // LR
                             Rotate_LR(root);
                           return 0;
                  case 0:  root->bal=-1; return 1;
                  case 1:  root->bal=0 ;  return 0;
                }
              }
		else {
                res=Put(root->right, x,root);
            // continue  ????

	         }
    }

	//Node *tmp = createNode(x);
	x->parent=parent;
	root=x;
	return 1;
}
int PutNodeTree(Tree &tree, int x){ //insert node into tree
    Node *p=tree.root;
    Node *X = createNode(x);
    if(Put(p,X,NULL)!=-1){
        if(tree.root==NULL)
            tree.root=X;
        tree.NumberNode++;

        }

}
void Rotate_LL(Node * &T)
{	Node *T1 = T->left;
	T->left = T1->right; T1->right=T;
	switch(T1->bal)
	{
		case 0:	 T->bal =0;
                 break;
		case -1: T->bal=1;
				 break;
	}
	T1->bal=0;
	T=T1;
}

void Rotate_LR(Node *&T){
// continue ???
}
void Rotate_RR(Node *&T){
// continue ???
}
void Rotate_RL(Node *&T){
// continue ???
}
