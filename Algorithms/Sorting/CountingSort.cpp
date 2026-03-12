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

void countingSort(vector<int>& arr){
    int n = arr.size();
    int k = arr[0];
    for (int i = 1; i<n; i++){
        if (arr[i] > k)
            k = arr[i];
    }

    vector<int> count(k+1, 0);
    for (int i = 0; i<n; i++){
        ++count[arr[i]];
    }

    for (int i = 1; i<=k; i++){
        count[i] = count[i] + count[i-1];
    }

    vector<int> sorted(n);
    for (int i = n-1; i>=0; i--){
        sorted[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = sorted[i];
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
    countingSort(arr);

    cout << "Array after sort: "<< endl;
    printArr(arr);

    return 0;


}