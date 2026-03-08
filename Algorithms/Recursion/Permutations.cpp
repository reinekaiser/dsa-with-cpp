#include <iostream>
#include <vector>
#include <set>

using namespace std;

void getAllPermutations(vector<int>& nums, int idx, vector<vector<int> >& allpermus){
    int n = nums.size();
    if (idx == n){
        allpermus.push_back(nums);
        return;
    }

    // set<int> used;

    for (int i = idx; i<n; i++){

        // if(used.count(nums[i])) continue;
        // used.insert(nums[i]);

        swap(nums[idx], nums[i]);
        getAllPermutations(nums, idx+1, allpermus);
        swap(nums[idx], nums[i]);
    }

}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > allpermus;
    
    getAllPermutations(nums, 0, allpermus);

    return allpermus;
}


int main() {

    vector<int> nums = {1, 2, 3};
    vector<vector<int> > permus = permute(nums);

    for(size_t i = 0; i < permus.size(); i++){
        for(size_t j = 0; j < permus[i].size(); j++){
            cout << permus[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}