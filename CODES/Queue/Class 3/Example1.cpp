#include<iostream>
#include<queue>
#include<string>
using namespace std;

string solve(string str) {
    int freq[26] = {0};
    queue<char> q;

    string ans = " ";
    
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        //increment frequency
        freq[ch - 'a']++;

        // q.push
        q.push(ch);

        while(!q.empty()) {
            if(freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            else {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()) {
            ans.push_back('#');
        }
    }

    return ans;
}

int  main() {
    string str = "zarcaazrd";
    cout << "final ans: " << solve(str) << endl;
    return 0;
}


// gfg solution

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
            int freq[26] = {0}; // Frequency array for lowercase English alphabets
            queue<char> q; // Queue to maintain the order of characters
            string ans = ""; // Answer string

            for (char ch : str) {
                freq[ch - 'a']++; // Increment frequency of current character
                q.push(ch); // Push current character into the queue

                // Check if the front character of the queue is non-repeating
                while (!q.empty() && freq[q.front() - 'a'] > 1) {
                    q.pop(); // Remove repeated characters from the front of the queue
                }

                // Append the first non-repeating character to the answer string
                if (!q.empty()) {
                    ans += q.front();
                } 
                else {
                    ans += '#'; // If no non-repeating character found, append '#'
                }
            }

        return ans;
    }

};

