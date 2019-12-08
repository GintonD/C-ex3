#define size_arr 5
#include <stdio.h> 
void shift_element (int* arr, int i){
int  size = sizeof(arr)/sizeof(arr[0]);
for (int j=0; j<size&&j<i; j++){
         *( arr+1+j)=*(arr+j);
          i--;
} //end for
} //end function
void insertionSort(int* arr, int len) 
{ 
    int i, val, j; 
    for (i = 1; i < len; i++) { 
       val= *(arr+i);
        j = i - 1; 
        //here we need to chenge with shift element
        while (j >= 0 && arr[j] > val) { 
           * (arr+ j + 1) =  *(arr+ j); 
            j = j - 1; 
            // until here
        }  //end while
       *(arr +j+1) = val; 
    } //end for
} //end function
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n-1; i++) 
        printf("%d ,", *(arr+i)); 
        printf("%d ", *(arr+i)); 

} 
 int main() 
{ 
    int arr[size_arr];
    printf ("enter 50 number into array \n");
    for (int i=0; i<size_arr; i++){
     printf ("plese insert number in arr. now in place:  %d \n",i+1);
    scanf("%d", &*(arr+i));   
    }

    insertionSort(arr, size_arr); 
    printArray(arr, size_arr); 


}
