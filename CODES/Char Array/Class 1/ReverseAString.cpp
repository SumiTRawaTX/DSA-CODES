#include <iostream>
#include <cstring>
using namespace std;

void reverseCharArray(char name[]) {
    int n = strlen(name);
    int i = 0;
    int j = n - 1;

    while (i < j) {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}

int main() {
    char name[100];
    cin >> name;
    cout << "Initially: " << name << endl;
    reverseCharArray(name);
    cout << "After reverse: " << name << endl;

    return 0;
}
