// O(n*2^n)

#include <iostream>
#include <vector>

using namespace std;

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int> >& allsubsets){
    if(i == nums.size()){
        allsubsets.push_back(ans);
        return;
    }

    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allsubsets);
    ans.pop_back();
    getAllSubsets(nums, ans, i+1, allsubsets);
}

vector<vector<int> > subset(vector<int>& nums) {
    vector<vector<int> > allsubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allsubsets);

    return allsubsets;
}


int main() {

    vector<int> nums = {1, 2, 3};
    vector<vector<int> > subsets = subset(nums);

    for(size_t i = 0; i < subsets.size(); i++){
        for(size_t j = 0; j < subsets[i].size(); j++){
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}