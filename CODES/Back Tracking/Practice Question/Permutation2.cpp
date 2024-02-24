// method 1 :-

class Solution {
public:

    void permuteUniqueHelper(vector<int> & nums, vector<vector<int>> & ans, int start) {
        //basa case
        if(start == nums.size()) {
            ans.push_back(nums);
            return;
        }


        for(int j = start; j < nums.size(); j++) {
            swap(nums[j], nums[start]);
            permuteUniqueHelper(nums, ans, start+1);

            //backtracking
            swap(nums[j], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>> ans;
        permuteUniqueHelper(nums, ans, 0);

        //push ans into stack
        set<vector<int>> st;
        for(auto e:ans) {
            st.insert(e);
        }
        ans.clear();
        for(auto e:st) {
            ans.push_back(e);
        }

        return ans;
    }
};