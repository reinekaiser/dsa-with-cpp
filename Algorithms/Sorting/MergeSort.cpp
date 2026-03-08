// O(nlogn)

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

void merge(vector<int>& arr, int start, int mid, int end){
    vector<int> temp;
    int i = start;
    int j = mid+1;
    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }  
    }
    //if left or right array remain element
    while (i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++){
        arr[idx + start] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    if (start < end) {
        int mid = start + (end - start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
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
    mergeSort(arr, 0, n-1);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;


}