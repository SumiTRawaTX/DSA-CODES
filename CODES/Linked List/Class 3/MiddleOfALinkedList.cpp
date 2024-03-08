class Solution {
public:

    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len ++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        int position = n/2 + 1;


        // Method 1 -

        // int currPos = 1;
        // ListNode* temp = head;
        // while(currPos != position) {
        //     currPos++;
        //     temp = temp->next;
        // }
        // return temp;


        //Method 2 -
        
        ListNode* temp = head;
        while(position != 1) {
            position--;
            temp = temp->next;
        }
        return temp;
    }
};