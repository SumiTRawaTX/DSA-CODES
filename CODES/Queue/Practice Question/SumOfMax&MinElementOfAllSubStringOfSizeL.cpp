// #include<iostream>
// #include<deque>
// using namespace std;


// maxSlidingWindow(vector<int>& nums, int k) {
//     deque<int> dq1, d12;
//     int ans = 0;

//     // first window of k size
//     for(int i=0; i<k; i++) {
//         // choose element remove krdo
//         while(!dq.empty() && nums[i] >= nums[dq.back()]) {
//             dq.pop_back();
//         }

//         // bada element remove krdo
//         while(!q2.empty() && nums[i] <= mums[d2.back()]) {
//             dq2.pop_back();
//         }

//         // inserting index so that we cah check out of window element
//         dq.push_back(i);
//         dq2.push_back(i);
//     }

//     ans += nums[dq.front()] + nums[dq2.front()];

//     for(int i=k; i<nums.size(); i++) {
//         //out of
//     }
// }  