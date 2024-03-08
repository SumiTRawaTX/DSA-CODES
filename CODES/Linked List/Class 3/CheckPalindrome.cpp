class Solution {
public:

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        //base case
        if(curr == NULL) {
            return prev;
        }

        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        return reverseUsingRecursion(prev, curr);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL) {
            fast = fast->next;
            if(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    bool compareList(ListNode* head, ListNode* head2){
        while(head != NULL && head2 != NULL) {
            if(head->val != head2->val) {
                return false;
            }
            else {
                head = head->next;
                head2 = head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        //break into 2 half
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        //reverse second half
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);

        //compare both linked list
        bool ans = compareList(head, head2);
        return ans;
        
    }
};