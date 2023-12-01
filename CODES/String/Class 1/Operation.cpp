#include<iostream>
#include<string>
using namespace std;

int main() {

    // // string create
    // string str;
    // //input
    // cin >> str;
    // // getline(cin, str);

    // // output
    // cout << str;

    // cout << "length: " << str.length() << endl;
    // cout<< "empty: " << str.empty() << endl;

    // str.push_back('A');
    // cout << str;

    // cout << endl;

    // str.pop_back();
    // cout << str;
    
    // cout << endl;

    // cout << str.substr(0, 6) << endl;

    // string a = "Love";
    // string b = "Love";

    // if(a.compare(a) == 0) {
    //     cout << "a and b are exactly same strings" << endl;
    // }
    // else {
    //     cout << "a and b are not same " << endl;
    // }

    // cout << endl;

    // string sentence = "hello ji kaise ho sab";
    // string target = "everyone";
    // cout << sentence.find(target) << endl;

    // if(sentence.find(target) == std::string::npos) {
    //     cout << "not found" << endl;
    // }

    // string str ="this is my first message";
    // string word ="babbar";
    // str.replace(0, 4, word);
    // cout << str << endl;

    string str = "abcdegh";
    str.erase(0,4);
    cout << str;

    return 0;
}