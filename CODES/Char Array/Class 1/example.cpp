#include<iostream>
using namespace std;

int main () {

    // char ch[100];
    // cout << "enter your name" << endl;
    // cin >> ch;
    // cout << "appka naam " << ch << endl;


    // char ch[100];
    // ch[0]='a';
    // ch[1]='b';
    // cin >> ch[2];
    // cout << ch[0] << ch[1] << ch[2] << endl;

    // char name[100];
    // cin >> name;
    // for (int i=0; i<7; i++) {
    //     cout << "index: " << i << " value: " << name[i] << endl;
    // }

    // int value =(int)name[6];
    // cout << "value is : " << value << endl;

    char name[100];
    cout << "enter your name" << endl;
    cin.getline(name, 50);
    // cin >> name;

    cout << "your name is: " << name << endl;
    return 0;

}