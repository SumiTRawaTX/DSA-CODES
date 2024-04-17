#include<iostream>
using namespace std;

class Heap {
    public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int value) {
        // value insert 
        size = size + 1;
        int index = size;
        arr[index] = value;
    

        // place value at its correct position
        while(index > 1) {
            int paraentIndex = index / 2;

            if(arr[index > arr[paraentIndex]]) {
                swap(arr[index], arr[paraentIndex]);
                index = paraentIndex;
            }
            else {
                break;
            }
        }
    }
}; 

int main() {
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "print the head " << endl;

    for(int i = 1;i<=h.size;i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.insert(110);

    for(int i = 1;i<=h.size;i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

}