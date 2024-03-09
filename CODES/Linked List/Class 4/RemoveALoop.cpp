void removeLoop(Node* head) {
    // check forl oop
    Node* slow = head;
    Node* fast = head;
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

    slow = head;

    while(fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* startPoint = slow;

    Node* temp = fast;

    while(temp->next != startPoint) {
        temp = temp->next;
    }

    temp->next = NULL;
}

