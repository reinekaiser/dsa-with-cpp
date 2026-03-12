//O(n)

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

void countSort(vector<int>& arr, int n, int pos){
    int count[10] = { 0 }; //0-9
    for (int i = 0; i<n; i++){
        ++count[(arr[i]/pos) % 10];
    }

    for (int i = 1; i<10; i++){
        count[i] = count[i] + count[i-1];
    }

    vector<int> temp(n);
    for (int i = n-1; i>=0; i--){
        temp[--count[(arr[i]/pos) % 10]] = arr[i];
    }

    for (int i = 0; i<n; i++){
        arr[i] = temp[i];
    }
}

void radixSort(vector<int>& arr){
    int n = arr.size();
    int k = arr[0];
    for (int i = 1; i<n; i++){
        if (arr[i] > k)
            k = arr[i];
    }

    for (int pos = 1; k/pos > 0; pos = pos*10){
        countSort(arr, n, pos);
    }
}

int main() {
    srand(time(0));

    vector<int> arr;
    int n;
    
    cout << "Enter the length of array: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        arr.push_back(rand() % (n+1));
    }

    printArr(arr);
    radixSort(arr);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;


}