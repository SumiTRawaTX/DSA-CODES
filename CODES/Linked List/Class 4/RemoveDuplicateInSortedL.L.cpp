class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }

        ListNode* temp = head;

        while(temp != NULL) {
            if(temp->next != NULL && temp->val == temp->next->val) {
                // remove
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                nextNode->next = NULL;
                delete nextNode;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};