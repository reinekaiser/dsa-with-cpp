// O(n^2)

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

void swap(int& a, int& b){
    int x = a;
    a = b;
    b = x;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1 ; i++){
        for (int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
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
    bubbleSort(arr);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;
}