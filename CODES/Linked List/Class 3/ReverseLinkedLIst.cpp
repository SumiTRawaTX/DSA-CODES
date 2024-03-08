// METHOD 1 :-

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while(curr!= NULL) {
//             ListNode* nextNode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr  = nextNode;
//         }
//         return prev;
//     }
// };




//METHOD 2 -

class Solution {
public:

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        //bsae case
        if(curr == NULL) {
            return prev;
        }

        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        ListNode* recursionAns =  reverseUsingRecursion(prev, curr);
        return recursionAns;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseUsingRecursion(prev, curr);
    }
};

