#include<iostream>
#include<deque>
#include<vector>

using namespace std;


vector<int> sumSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> sum;
    int n = nums.size();
    int s = 0;

    for (int i=0; i<k; i++){
        s += nums[i];
        dq.push_back(nums[i]);
    }
    sum.push_back(s);

    int j = 1;
    for (int i = 1; i<n-k+1; i++){
        int ans = sum[j-1] - dq.front() + nums[i+k-1];

        sum.push_back(ans);

        dq.pop_front();
        dq.push_back(nums[i+k-1]);
        j++;
    }

    return sum;
}

void printArr(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    vector<int> ans = sumSlidingWindow(nums, 3);

    printArr(ans);

    return 0;
}