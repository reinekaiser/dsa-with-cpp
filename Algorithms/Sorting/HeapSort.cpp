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

void heapify(vector<int>& arr, int n, int i){
    int largestIdx = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if (left < n && arr[left] > arr[largestIdx])
        largestIdx = left;
    if (right < n && arr[right] > arr[largestIdx])
        largestIdx = right;

    if (largestIdx != i ){
        swap(arr[i], arr[largestIdx]);
        heapify(arr, n, largestIdx);
    }
    
}

void heapSort(vector<int>& arr, int n) {
    for (int i = n/2 -1; i >=0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // n into i, remove the largest
        heapify(arr, i, 0);
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
    heapSort(arr, n);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;


}