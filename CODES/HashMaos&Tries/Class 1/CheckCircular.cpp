#include<iostream>
#include<unordered_map>
using namespace std;

bool checkCircular(Node* head) {
    unordered_map<node* ,bool>vst;
    Node* temp = head;

    while(temp != NULL) {
        if(vst.find[temp] != vst.end()) {
            vis[temp] = true;
        }
        else {
            return false;
        }
        temp = temp->next;
    }

    return false;
}

int main() {

}