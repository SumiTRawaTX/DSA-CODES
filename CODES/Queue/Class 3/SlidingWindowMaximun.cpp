class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // first window
        for(int i=0; i<k; i++) {
            // remove small element
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            // inserting index, so  that we can check out of window element
            dq.push_back(i);
        }

        // store answer for first window 
        ans.push_back(nums[dq.front()]);

        // remaining windows to process
        for(int i=k; i<nums.size(); i++) {
            // out of window element need to remove
            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }

            // again check for current element
            // and remove the small element
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            // inserting index, so that we can check out
            dq.push_back(i);

            // store current window answer
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};