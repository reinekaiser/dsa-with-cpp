// n! = n*(n-1)!, n >= 0

#include <iostream>
#include <vector>

using namespace std;

int factorial(int n){
    if (n == 0){
        return 1;
    }

    return n*factorial(n-1);
}

int clumsyFactorial(int n){
    
}

int main(){
    int n;
    cin >> n;
    cout << n << "! = " << factorial(n) << endl;
    return 0;
}