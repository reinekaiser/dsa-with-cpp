// complexity : O(n)

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

int linearSearch(vector<int> arr, int key) {
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main() {
    srand(time(0));

    vector<int> arr;
    int n;
    int key;

    cout << "Enter the length of array: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        arr.push_back(rand() % 101);
    }

    printArr(arr);

    cout << "Enter the key need to be find: ";
    cin >> key;

    cout << "Result after searching: " << linearSearch(arr, key) << endl;

    return 0;
}