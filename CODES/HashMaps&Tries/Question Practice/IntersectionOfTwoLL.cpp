class Solution {
    public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> mp;
        Node* curr = head2;

        // hash L2 items
        while(curr) {
            mp[curr->data]++;
            curr = curr->next;
        }

        Node* IL = NULL;
        Node* it = 0;
        curr = head1;

        while(curr) {
            if(mp.find(ccurr->data) != mp.end()) {
                if(!IL) {
                    IL = curr;
                    it = IL;
                }
                else {
                    if(mp[curr->data] > 0) {
                        it->next = curr;
                        it = it->next;
                        map[curr->data]--;
                    }
                }
            }
            curr = curr->next;
        }
        it->next = NULL;
        return IL;
    }
};