
#include <iostream>
//creating linked lists
using namespace std;

class node {
    public:
    int data; 
    node *next;
};

//creating a head pointer and equating it to NULL

node *head = NULL;

void insert_beg (int x) {
    node *ptr = new node; //creating a pointer object of node
    ptr->data = x; 
    ptr->next = head;
    head = ptr; 
    cout<<"inserting at beginning"<<endl;
}
//inserting at end 
void insert_end (int x) {
    node *ptr = new node; 
    ptr->data = x;
    ptr->next = NULL;
    
    if(head == NULL)//empty list
        head = ptr;
    
    else 
    {
        node *temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = ptr;
        
    }
}

void begin_delete() {
    node *ptr; 
    if(head==NULL)
        cout<<"list is empty"<<endl;
    else
    {
        ptr = head;
        head = ptr->next;
        delete ptr; 
        cout<<"node deleted from the beginning"<<endl;
    }
}

void end_delete() {
    node *ptr, *ptr1; 
    if(head == NULL)
        cout<<"list is empty"<<endl;
    else if(head->next == NULL) //only one element
    {
        head=NULL;
        delete head;
        cout<<"only node of the list is deleted"<<endl;
    } 
    
    else {
        ptr = head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr= ptr->next;
        }
        ptr1->next =NULL;
        delete ptr;
        cout<<"deleted end node from the list"<<endl;
    }
        
        
}

void display_list() {
    node *temp = head;
    if(head==NULL)
        cout<<"empty list"<<endl;
    else
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    cout<<endl;
}

int num_of_elem() {
    int counter{}; 
    node *temp = head;
    while(temp!=NULL) {
        counter++;
        temp=temp->next;
    }
    
    return counter;
}


void clear() {
    node *temp = head; 
    if(head==NULL)
        cout<<"list is empty"<<endl;
    else
        while(head!=NULL) {
            cout<<"deleting..."<<endl;
            temp = head;
            head = head->next;
            cout<<head->data;
            delete temp; 
    
        }
}

void mid_elem() {
    node *fast_ptr = head;
    node *slow_ptr = head;
    while(fast_ptr->next!=NULL) {
            fast_ptr=fast_ptr->next;
            if(fast_ptr->next!=NULL)
                fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
    }
        cout<<slow_ptr->data;
        cout<<" is the middle element"<<endl;
}
//reversing a linked list
//sliding pointers are used for single linked list
//O(n) where n = total number of links
void reverse()
    {
        node* current = head;
        node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
void insert(int x, int index) {
    node *temp {head};
    node *ptr = new node;
    ptr->data = x;
    for(int i = 0; i<index-1; ++i){
        temp=temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    
}

void del(int index) {
    node *prev = NULL;
    node *curr = head;
    for(int i = 0; i<index; ++i) {
        prev = curr; 
        curr = curr->next;
    }
    prev->next = curr->next; 
    delete curr;
}

int main() {
    insert_beg(100);
    insert_end(200);
    insert_beg(102); 
    insert_end(903);
    display_list(); 
    int num = num_of_elem();
    cout<<endl<<num<<endl;
    mid_elem();
    reverse(); 
    display_list();
    insert(10,3);
    display_list();
    del(3);
    display_list();
    
    return 0;
}