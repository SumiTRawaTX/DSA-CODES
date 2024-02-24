class Solution {
public:

        void combinationSum_Helper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> & ans, int index ) {
        //base case
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        if(target < 0) {
            return;
        }

        for(int i = index; i<candidates.size();i++) {
            if(i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_Helper(candidates, target-candidates[i], v, ans, i+1);
            
            //backtracking
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum_Helper(candidates, target, v, ans, 0);
        set<vector<int>> st;
        for(auto e: ans) {
            st.insert(e);
        }
        ans.clear();
        for(auto e:st) {
            ans.push_back(e); // only uniqye vectors.
        }
        return ans;
    }
};