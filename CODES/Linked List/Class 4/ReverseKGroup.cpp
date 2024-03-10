class Solution {
public:

    int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL) {
            len ++;
            temp = temp->next;
        }
        return len;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        //empty list
        //base case
        if(head == NULL) {
            return head;
        }
        // if single node is present
        if(head->next == NULL) {
            return head;
        }

        ListNode* prev= NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int pos = 0;

        int len = getLength(head);
        if(len < k) {
            return head;
        }

        // reverse from k node
        while(pos<k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos ++;
        }

        // recursion will handle it
        ListNode* reverseAns = NULL;
        if(nextNode != NULL){
            reverseAns = reverseKGroup(nextNode, k);
            head->next = reverseAns;
        }
        return prev;
    }
};