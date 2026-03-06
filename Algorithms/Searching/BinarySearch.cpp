// complexity : O(logn) - sorted array

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void printArr(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(vector<int> arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end){
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2;

        if (key < arr[mid])
            end = mid - 1;
        else if (key > arr[mid]) 
            start = mid + 1;
        else 
            return mid;
    }

    return -1;
}

int recBinarySearch(vector<int> arr, int key, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start)/2;
        if (key > arr[mid])
            return recBinarySearch(arr, key, mid+1, end);
        else if (key < arr[mid])
            return recBinarySearch(arr, key, start, mid-1);
        else 
            return mid;
    }
    return -1;
}

int main() {

    vector<int> arr;
    int n;
    int key;

    cout << "Enter the length of array: ";
    cin >> n;

    cout << "Enter " << n << "number in order: ";
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    printArr(arr);

    cout << "Enter the key need to be find: ";
    cin >> key;

    cout << "Result after searching: " << binarySearch(arr, key)<< endl;

    return 0;
}