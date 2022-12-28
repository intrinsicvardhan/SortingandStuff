#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    node *lchild; 
    int data; 
    node *rchild; 
};

class BT {
public:
    int lheight, rheight, count = 0;
    int leafnodes =0;
    node *root; 
    void create() {
        node *p, *t; 
        int x; 
        queue<node*> q; 
        cout<<"enter root value\n"; 
        cin>>x; 
        node *ptr = new node; 
        ptr->data= x; 
        ptr->lchild = ptr->rchild = nullptr; 
        root = ptr; 
        q.push(root);
        while(!q.empty()) {
            p = q.front(); 
            q.pop(); 
            cout<<"enter left child of "<<p->data<<"\n"; 
            cin>>x; 
            if(x!=-1) {
                t = new node; 
                t->data = x; 
                t->lchild = t->rchild = nullptr; 
                p->lchild = t; 
                q.push(t);
            }
            cout<<"enter right child of "<<p->data<<"\n"; 
            cin>>x; 
            if(x!=-1) {
                t = new node; 
                t->data = x; 
                t->lchild = t->rchild = nullptr; 
                p->rchild = t; 
                q.push(t);
            }
        }
    }
    
    void inorder(node *t) {
        if(t) {
            inorder(t->lchild); 
            cout<<t->data<<" "; 
            inorder(t->rchild); 
        }
    }
    
    int Height(node *t) {
        if(!t) 
            return 0; 
        else {
            lheight = Height(t->lchild); 
            rheight = Height(t->rchild); 
        }
            
        return max(lheight, rheight)+1; 
            
    }
    
    int Count(node *t) {
        if(!t) 
            return 0;
        else {
            count++; 
            Count(t->lchild); 
            Count(t->rchild);
        }
            
        return count;
    }
    
    void level_order(node *r) {
        node *t;
        queue<node *> q1; 
        q1.push(r); 
        while(!q1.empty()) {
            t = q1.front(); 
            q1.pop(); 
            cout<<t->data<<" ";
            if(t->lchild)
                q1.push(t->lchild); 
            if(t->rchild)
                q1.push(t->rchild); 
        }
    }
    
    int LeafNodes(node *t) {
        if(t&&!t->lchild&&!t->rchild) 
            leafnodes++;
        if(!t)
            return 0;
        else {
            LeafNodes(t->lchild); 
            LeafNodes(t->rchild); 
        }
        return leafnodes;
    }
    //we know external nodes are internal nodes+1 for binary trees 
    int InternalNodes(node *t) {
        return LeafNodes(t)-1;
    }
};

int main() {
    BT b1; 
    b1.create(); 
    b1.inorder(b1.root); 
    cout<<"\n";
    cout<<b1.Height(b1.root)<<" is the height of the tree\n";
    cout<<b1.Count(b1.root)<<"is the number of nodes in the tree\n"; 
    b1.level_order(b1.root); 
    cout<<"\n"<<b1.LeafNodes(b1.root)<<" is the number of leaf nodes\n";
    return 0; 
    
}