// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // constructor
    TrieNode(char d) {
        this->data = d;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

void insertWord(TrieNode* root, string word) {

    // cout << "Inserting word: " << word << endl;
    // base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion handle
    return insertWord(child, word.substr(1));
}

bool SearchingWord(TrieNode* root, string word) {
    // base case
    if(word.length() == 0) {
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        // not present
        return false;
    }

    // recursion handle
    return SearchingWord(child, word.substr(1));
}

int main() {

    TrieNode* root = new TrieNode('-');
    // root->insertWord("codding")
    insertWord(root, "codding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelper");
    insertWord(root, "make");
    insertWord(root, "makecode");
    insertWord(root, "makecoder");

    if(SearchingWord(root, "code")) {
        cout << "Present" << endl;
    }
    else {
        cout << "Not Present" << endl;
    }
}