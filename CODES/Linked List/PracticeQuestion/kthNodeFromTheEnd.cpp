void fun(ListNode* head, int& position, int & ans) {
    if(head == 0) return;
    fun(head->next, position, ans);

    if(postion ==0) {
        ans = head->data;
        
    }

    position --;
}

int getNode(ListNode* list, int position) { 
    int ans = -1;
    fun(list, position, ans);
    return ans;
}