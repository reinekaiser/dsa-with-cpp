// O(nlogn) - bad: O(n^2)

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void printArr(vector<int> arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void swap(int& a, int& b){
    int x;
    if (a != b){
        x = a;
        a = b;
        b = x;
    }
}

int partition(vector<int>& arr, int start, int end){
    int i = start - 1;
    int pivot = arr[end];

    for (int j = start; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);

    return i;
}

void quickSort(vector<int>& arr, int start, int end){
    if (start < end){
        int pivotIdx = partition(arr, start, end);
        quickSort(arr, start, pivotIdx -1);
        quickSort(arr, pivotIdx +1, end);
    }
}

int main() {
    srand(time(0));

    vector<int> arr;
    int n;
    
    cout << "Enter the length of array: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        arr.push_back(rand() % 101);
    }

    printArr(arr);
    quickSort(arr, 0, n-1);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;


}