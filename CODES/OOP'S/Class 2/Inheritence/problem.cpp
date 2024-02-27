#include<iostream>
using namespace std;

class a {
    public:
        int chemistry;

        a() {
            chemistry = 300;
        }
};

class b {
    public:
        int chemistry;
        b() {
            chemistry = 410;
        }
};

class c: public a, public b {
    public:
        int maths;
};

int main() {
     c obj;
    cout << " " << obj.a::chemistry << " " << obj.maths << endl;
    cout << " " << obj.b::chemistry << " " << obj.maths << endl;
}