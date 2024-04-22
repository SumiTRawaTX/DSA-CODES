class Solution {
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        map<int, Node*> mp;
        Node* curr = head1;

        // L1 hashed
        while(curr) {
            mp[curr->data] = curr;
            curr = curr->next;
        }
        curr = head2;

        // L2 hashed
        while(curr) {
            mp[curr->data] = curr;
            curr = curr->next;
        }
        Node* UL = NULL;
        curr = 0;

        // iterate MAP & make final UL
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(!UL) {
                UL = it->second;
                curr = UL;
            }
            else {
                curr->next = it->second;
                curr= curr->next;
            }
        }
        curr->next = 0;
        return UL;
    }
};