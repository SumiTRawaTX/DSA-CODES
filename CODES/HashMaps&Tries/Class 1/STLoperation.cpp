#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    //creation
    unordered_map<string, int> m;

    // insertion 1-
    pair<string, int> p = make_pair("sumit", 1);
    m.insert(p);

    // insertion 2-
    pair<string, int> p2("rawat", 2);
    m.insert(p2);

    // insertion 3-
    m["singh"] = 3;


    // access
    cout << m.at("rawat") << endl;

    cout << m.at("sumit") << endl;

    cout << m["singh"] << endl;

    // search
    cout << m.count("inova") << endl;
    cout << m.count("sumit") << endl;

    if(m.find("fortuner") != m.end()) {
        cout << "Fortuner is present" << endl;
    }
    else {
        cout << "not present" << endl;
    }

    //size
    cout << m.size() << endl;

    cout << m["humour"] << endl;
    cout << m.size() << endl;

    cout << "printing all entries: " << endl;

    for(auto i: m) {
        cout << i.first << " -> " << i.second << endl;
    }
}