#include <iostream>
using namespace std;
                           
void heapify(int array[], int n, int i) {
    
    int parent = i;  
    int leftchild = 2 * i + 1;   
    int rightchild = 2 * i + 2;   

    if (leftchild < n && array[leftchild] > array[parent]) {
        parent = leftchild;
    }
         
    if (rightchild < n && array[rightchild] > array[parent]) {
        parent = rightchild;
    }
    
    
    if (parent != i) {
        swap(array[i], array[parent]);
        heapify(array, n, parent);
    }
}

void heapSort(int array[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
        //cout << "\n";
    }
}

int main()
{
    int array[] = { 1, 12, 9, 5, 6, 10 };
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Dizi" << endl;
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
       
    }
  
    heapSort(array, n);
    
    cout <<endl<<endl<< "Heap Sort Hali"<<endl;
    printArray(array, n);
}

