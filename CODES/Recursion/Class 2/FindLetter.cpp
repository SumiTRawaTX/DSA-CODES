#include<iostream>
#include<string>
using namespace std;

bool checkKey(string str, int i, int n, char key) {
    //base case
    if(i>=n) {
        //key not found
        return false;
    }

    //1 case solve krdo
    if(str[i]== key) {
        return true;
    }

    //baaki recursion sambhal lega
    bool ans = checkKey(str, i+1, n, key);
    return ans;
}

int main () {

    string str = "lovebabbar";
    int n = str.length();

    char key = 't';

    int i = 0;

    bool ans = checkKey(str, i, n, key);

    cout << "answer is: " << ans << endl;
    return 0;
}