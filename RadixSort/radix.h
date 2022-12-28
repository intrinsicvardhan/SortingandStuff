class node {
public:
    int data; 
    node *next; 
    node() {
        data = 0; 
        next = nullptr; 
    }
}; 

void initialiseBins(node **p, int n) {
    for(int i =0; i<n; i++) {
        p[i] = nullptr; 
    }
}

void insertBin(node **p, int index, int x) {
    node *ptr = new node; 
    ptr->data = x;
    ptr->next = nullptr; 
    if(p[index] == nullptr) {
        p[index] = ptr; 
    }
    else {
        node *temp = p[index]; 
        while(temp->next!=nullptr) {
            temp = temp->next; 
        }
        temp->next = ptr; 
    } 
        
}

int deleteBin(node **p, int index) {
    node *ptr = p[index]; 
    p[index] = p[index]->next; 
    int x = ptr->data; 
    delete ptr;
    return x;
}

int find_max(int arr[], int n) {
    int m = arr[0]; 
    for(int i = 1; i<n ; i++) {
        if(arr[i]>m)
            m = arr[i]; 
    }
    return m;
}

int passes(int max) {
    int count {1};
    while(max/10!=0) {
        count++; 
        max/=10;
    }
    return count;
}