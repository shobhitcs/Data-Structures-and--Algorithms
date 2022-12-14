#include<stdio.h>
class Node
{
private:
public:
    int data;
    Node* left;
    Node* right;
    Node(int n,Node* lft,Node* rgt);
    ~Node();
    friend class Tree;
};

Node::Node(int n=0,Node* lft=NULL,Node* rgt=NULL)
{
    data=n;
    left=lft;
    right=rgt;

}

Node::~Node()
{
}

class Tree
{
private:
public:
    Node* root;
    Tree();
    ~Tree();
    void insert(Node* root,int n);
    void Inorder(Node* root);
    void Preorder(Node* root);
    void Postorder(Node* root);
    bool search(Node* rot,int n);
    void dis_leaf(Node* rot);
    void isfull_tree(Node* rot);
};

Tree::Tree()
{
    root=NULL;
}

Tree::~Tree()
{
}


void Tree::insert(Node* rot,int n){
    if(root==NULL){
        root=new Node(n);
        return;
    }
    else{
        Node* iter=rot;
        if(n<iter->data){
            if(iter->left==NULL){
                iter->left=new Node(n);
                return;
            }
            insert(iter->left,n);
        }
        else if (n>iter->data)
        {   
            if(iter->right==NULL){
                iter->right=new Node(n);
                return;
            }
            insert(iter->right,n);
        }
        
    }
}


void Tree::Inorder(Node* rot)
{   
    // printf("Hello");
    if (!rot) {
        return;
    }
    Inorder(rot->left);
    printf("%d ",rot->data);
    // cout << root->data << endl;
    Inorder(rot->right);
}
void Tree::Preorder(Node* rot)
{   
    // printf("Hello");
    if (!rot) {
        return;
    }
    printf("%d ",rot->data);
    Preorder(rot->left);
    // cout << root->data << endl;
    Preorder(rot->right);
}
void Tree::Postorder(Node* rot)
{   
    // printf("Hello");
    if (!rot) {
        return;
    }
    Postorder(rot->left);
    // cout << root->data << endl;
    Postorder(rot->right);
    printf("%d ",rot->data);
}

bool Tree::search(Node* rot,int n){
    if(rot==NULL){
        return false;
    }
    if(rot->data==n){
        return true;
    }
    if(n<rot->data){
        return search(rot->left,n);
    }
    else if (n>rot->data)
    {
        return search(rot->right,n);
    }
    
}
void Tree::dis_leaf(Node* rot)
{   
    // printf("Hello");
    if (!rot) {
        return;
    }
    dis_leaf(rot->left);
    if(rot->left==NULL && rot->right==NULL)
    printf("%d ",rot->data);
    // cout << root->data << endl;
    dis_leaf(rot->right);
}

void Tree::isfull_tree(Node* rot)
{   
    // printf("Hello");
    if (!rot) {
        return;
    }
    isfull_tree(rot->left);
    if((rot->left==NULL) ^ (rot->right==NULL))
    printf("%d ",rot->data);
    // cout << root->data << endl;
    isfull_tree(rot->right);
}
int main(){
    Tree t;
    t.insert(t.root,2);
    t.insert(t.root,10);
    t.insert(t.root,3);
    t.insert(t.root,1);
    t.insert(t.root,17);
    t.insert(t.root,13);
    // t.insert(t.root,35);
    // printf("%d \n",(t.root->left)->data);
    t.Postorder(t.root);
    if(t.search(t.root,35))
    printf("\nTRUE\n");
    else 
    printf("\nFALSE\n");
   t.dis_leaf(t.root);
    printf("\n\n");
   t.isfull_tree(t.root);
    return 0;
}