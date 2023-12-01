#include <iostream>
#include <string.h>
using namespace std;

bool isPalindrome(char name[]) {
    int i = 0;
    int n = strlen(name);
    int j = n - 1;

    while (i < j) {
        if (name[i] == name[j]) {
            i++;
            j--;
        } 
        else {
            return false;
        }
    }

    return true;
}

int main() {
    char name[100] = "babbab";
    cout << "Palindrome check: " << isPalindrome(name) << endl;

    return 0;
}
