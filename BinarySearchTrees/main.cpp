#include <iostream>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iInsert(int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
    void Postorder(Node* p); 
    void Preorder(Node *p); 
    Node* Tree_Min(Node *p) {
        if(!p) 
            return nullptr; 
        else if (p&&p->lchild) 
            Tree_Min(p->lchild); 
        else
            return p;
    }
    Node* Tree_Max(Node *p) {
        if(!p) 
            return nullptr; 
        else if(p&&p->rchild) 
            Tree_Max(p->rchild); 
        else 
            return p; 
    }
};

void Preorder(Node* p) {
    if(p) {
    cout<<p->data<<"\n"; 
    Preorder(p->lchild); 
    Preorder(p->rchild); 
    }
}
 
void BST::iInsert(int key) {
 
    Node* t = root;
    Node* p;
    Node* r;
 
    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
 
    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
 
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
 
}
 
void BST::Inorder(Node* p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void BST::Postorder(Node* p) {
    if (p){
        Postorder(p->lchild); 
        Postorder(p->rchild); 
        cout<<p->data<<"\n";
    }
}
 
 
Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;//case for not finding 
}
 
Node* BST::rInsert(Node *p, int key) {//recursive insert
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }
 
    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
    return p;  // key == p->data?
}
 
Node* BST::rSearch(Node *p, int key) { //recursive search
    if (p == nullptr){
        return nullptr;
    }
 
    if (key == p->data){
        return p;
    } else if (key < p->data){
        return rSearch(p->lchild, key);
    } else {
        return rSearch(p->rchild, key);
    }
}
 
Node* BST::Delete(Node *p, int key) {
    Node* q;
 
    if (p == nullptr){
        return nullptr;
    }
 //case 1. if it is a leaf node
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 //else case
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
 
int BST::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
 
Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
 
Node* BST::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}
 
 
int main() {
 
    BST bs;
    bs.iInsert(10);
    bs.iInsert(6);
    bs.iInsert(10);
    bs.iInsert(22);
    bs.iInsert(2);
    bs.iInsert(11); 
    bs.iInsert(3); 
    cout<<bs.Tree_Min(bs.getRoot())->data<<" is the minimum value of the tree\n";
    cout<<bs.Tree_Max(bs.getRoot())->data<<" is the maximum value of the tree\n";
    
 
    Preorder(bs.getRoot());
    
    
    return 0;
}