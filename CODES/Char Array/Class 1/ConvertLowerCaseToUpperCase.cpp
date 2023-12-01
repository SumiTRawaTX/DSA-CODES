#include<iostream>
#include<string.h>
using namespace std;

void convertintouppercase (char arr[]) {
    int n=strlen(arr);

    for(int i=0; i<n; i++ ) {
        arr[i] = arr[i] -'a'+'A';
    }
}
int main() {

    char arr[100]="babbar";
    convertintouppercase(arr);
    cout << arr << endl;

    return 0;

}