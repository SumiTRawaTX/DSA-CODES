class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {

            fast = fast->next;
            
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }

            if(fast == slow) {
                break;
            }
        }

        // no cycle present
        if(fast == NULL) {
            return NULL;
        }

        slow = head;

        // slow and fast -> 1 step
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};