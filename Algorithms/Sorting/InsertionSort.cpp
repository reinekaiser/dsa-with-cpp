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


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++){
        int current = arr[i];
        int prev = i - 1;

        while (prev >=0 && arr[prev] > current) {
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = current;
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
    insertionSort(arr);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;
}