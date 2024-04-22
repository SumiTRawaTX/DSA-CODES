string isSubset(int a[], int b[], int n, int m) {
    unordered_map<int,int>mp;
    string ans = "Yes";

    // map hasing using a1
    for(int i=0; i<n; i++){
        map[a[j]]++;
    }

    //check whether all element of a2 present in a1.
    for(int i=0; i<m; i++){
        if(mp.find(b[i]) == mp.end()){
            ans = "No";
            break;
        } 
        else {
            // present
            if(map[b[i]] > 0) {
                map[a2[i]]--;
            }
            else {
                ans = "No";
                break;
            }
        }
    }
    return ans;
}