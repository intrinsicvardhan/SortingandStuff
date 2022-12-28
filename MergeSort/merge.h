
//here m is the size of the array1 and n is the size of the array2
void merge(int arr1[], int arr2[], int m, int n) { //merging two sorted arrays 
    int i{}, j{} , k{};
    int arr3[m+n] {};
    while(i<m&&j<n) {
        if(arr1[i]<arr2[j]) {
            arr3[k] = arr1[i]; 
            k++; 
            i++;
        }
        else {
            arr3[k] = arr2[j];
            j++; 
            k++;
        }
    }
    for(;i<m; ++i) 
        arr3[k++] = arr1[i]; 
    for(;j<n ;++j) 
        arr3[k++] = arr2[j];
        
}

void merge(int arr[], int l, int mid, int h) {
    int i = l, j = mid+1, k =l ;
    int arr2[100] {} ;
    while(i<=mid&&j<=h) {
        if(arr[i]<arr[j]) 
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++]; 
    }
    for(; i<= mid; i++) 
        arr2[k++] = arr[i]; 
    for(; j<= h; j++)
        arr2[k++] = arr[j]; 
        
    for(i =l; i<= h; i++) 
        arr[i] = arr2[i];
}
