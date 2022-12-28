#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
    int data; 
    node *next;
    node *head;
    node() {
        head= NULL;
        next = NULL;
        data = 0;
    }
    
    void remove_cycle() {
        node *temp = head;
        node *temp2 = NULL;
        if(head==NULL)
            cout<<"empty list!!\n";
        else {
            while(temp->next!=head)
                temp=temp->next; 
            temp2 = temp->next;
            temp->next=temp2;
        }
        cout<<"removed cycle in the list if it exists!\n";
    }
    //create a middle node 
    void reverse() {
        node *mid = new node;
        node *temp = head, *temp2 = head;
        while(temp->next=NULL) {
            mid->next = temp->next;
            temp->next = mid;
        }
    }
    
};

