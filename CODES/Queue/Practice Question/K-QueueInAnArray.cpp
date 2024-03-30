#include <iostream>
using namespace std;

class KQueue {
public:
    int n, k, freeSpot;
    int* arr;
    int* next;
    int* front;
    int* rear;

    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0) {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }
        for (int i = 0; i < n - 1; ++i) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    // push x int qth queue
    bool push(int x, int qi) {
        //overflow
        if (freeSpot == -1) {
            return false;
        }

        // find first free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // if first element in qi
        if (front[qi] == -1) {
            front[qi] = index;
        }
        else {
            // link that new element to that Q's rearest element
            next[rear[qi]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // pop element from qith queue    
    int pop(int q1) {
        // underflow
        if (front[q1] == -1) {
            return -1;
        }

        // find index to pop
        int index = front[q1];

        // front update
        front[q1] = next[index];

        // update FreeSpot 
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

    ~KQueue() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main() {
    KQueue kq(8, 3);
    
    cout << kq.push(1, 0) << endl;
    cout << kq.push(2, 0) << endl;
    cout << kq.push(5, 1) << endl;
    cout << kq.push(3, 0) << endl;
    cout << kq.pop(1) << endl;
    
    return 0;
}
