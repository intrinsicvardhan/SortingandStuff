#include <iostream>
using namespace std;

class node {
    public:
    int data; 
    node *left; 
    node *right; 
    node() {
        data = 0; 
        left = nullptr; 
        right = nullptr; 
    }
    
};


void inorder(node *root) {
    while(root) {
        inorder(root->left); 
        cout<<root->data; 
        inorder(root->right); 
        
    }
}

void preorder(node *root) {
    while(root) {
        cout<<root->data; 
        preorder(root->left); 
        preorder(root->right); 
    }
}

void postorder(node *root) {
    while(root) {
        postorder(root->left); 
        postorder(root->right); 
        cout<<root->data; 
    }
}

void bin_search(node *root, int key) {
    if(root==NULL) {
        cout<<"not found or empty tree\n"; 
    return;
    }
    if(root->data == key) {
        cout<<"found!\n"; 
        return; 
        
    }
    if(root->data <key)
        bin_search(root->right, key); 
    else 
        bin_search(root->left, key); 
    
}

void insert(node *root, int x) {
    node *ptr = new node; 
    ptr->data = x ;
    ptr->right = nullptr; 
    ptr->left = nullptr;
    if(root==nullptr) {
        root = ptr; 
        cout<<"inserted the root element\n";
        return; 
    }
    node *t {root}, *i{nullptr}; 
    while(t!=nullptr) {
        if(x>t->data) {
            i = t; 
            t=t->right;
        }
        else {
            i = t; 
            t=t->left; 
        }
    }
    i = ptr;
    cout<<"inserted "<<i->data<<"\n";
}



int main() {
    node *root{nullptr};
    insert(root,10);
    insert(root,20); 
    return 0;
}