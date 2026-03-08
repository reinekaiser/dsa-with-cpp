// O(n*2^n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int> >& allsubsets){
    int n = nums.size();
    if(i == n){
        allsubsets.push_back(ans);
        return;
    }

    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allsubsets);
    ans.pop_back();

    int idx = i+1;
    while(idx < n && nums[idx - 1] == nums[idx]) {
        idx++;
    }

    getAllSubsets(nums, ans, idx, allsubsets);
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int> > allsubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allsubsets);

    return allsubsets;
}


int main() {

    vector<int> nums = {1, 2, 2};
    vector<vector<int> > subsets = subsetsWithDup(nums);

    for(size_t i = 0; i < subsets.size(); i++){
        for(size_t j = 0; j < subsets[i].size(); j++){
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}