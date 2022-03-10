

  ListNode * removeNthFromEnd(ListNode * head, int n) {

    ListNode * slow = head;
    ListNode * fast = head;

    for (int i = 0; i < n; i++) {
      fast = fast -> next;
    }

    while (fast and fast -> next) {
      slow = slow -> next;
      fast = fast -> next;
    }
    if (fast == NULL)
      return NULL;

    slow -> next = slow -> next -> next;
    return head;
  }
