Node* reverse(Node* &head) {
    Node* prev= NULL;
    NOde* curr = head;

    while(curr != NULL) {
        Node* next =  curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


void addOne(Node* &head) {
    // reverse
    head = reverse(head);

    // add  1
    int carry = 1;

    Node* temp = head;

    wile(temp-> != NULL) {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum/10;

        temp->data = digit;
        temp = temp->next;

        if(carry == 0) {
            break;
        }
    }

    // process last node
    int totalSum = temp -> data + carry;
    int digit = totalSum % 10;
    carry = totalSum / 10;
    carry = totalSum/10;

    temp -> data = digit;
    if(carry != 0) {
        Node* newNode = new Node(carry);
        temp->next = newNode;
    } 
   
    //reverse
    head = reverse(head);
}