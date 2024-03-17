class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        if(!head) return 0;

        Node* it = head;
        while(it) {
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = it->next->next;
        }

        it = head;
        while(it) {
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        it = head;
        Node* cloneHead = it->next;
        while(it) {
            Node* cloneNode = it->next;
            it->next = it->next->next;
            if(cloneNode->next) {
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }
        return cloneHead;
    }
};