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

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++){
        int smallest = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        swap(arr[i], arr[smallest]);
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
    selectionSort(arr);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;
}