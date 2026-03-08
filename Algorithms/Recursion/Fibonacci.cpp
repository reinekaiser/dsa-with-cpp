// F(n) = F(n - 1) + F(n - 2), n > 1
// find F(n)

#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int fibonacci(int n){
    if(n <= 1) return n;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

int generateFibonacci(vector<int>& fibo, int n){
    if(n <= 1){
        fibo[n] = n;
        return n;
    }

    if (fibo[n] != -1)
        return fibo[n];

    fibo[n] = generateFibonacci(fibo, n-2) + generateFibonacci(fibo, n-1);

    return fibo[n];
}

int main() {
    int n;
    
    cout << "Give me fibonacci at n = ";
    cin >> n;
    vector<int> fibo(n+1, -1);

    int fib_n = generateFibonacci(fibo, n);
    cout << n << " first fibonacci numbers:" <<endl;
    printArr(fibo);

    cout << "F(" << n << ") = " << fib_n <<endl;

    return 0;
}