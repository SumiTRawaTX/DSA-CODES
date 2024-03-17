class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newLastNode = 0;  

        int sum = 0;
        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;
            }
            else {
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }
        ListNode* temp = newLastNode->next;

        // form new list
        newLastNode->next = 0;

        // deleting old list
        while(temp) {
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        return head;
    }
};