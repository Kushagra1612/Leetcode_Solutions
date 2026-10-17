class Solution {
public:
    // Helper function to split the list into two halves
    ListNode* split(ListNode* head, int size) {
        for (int i = 0; head && i < size - 1; i++) {
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* nextHead = head->next;
        head->next = nullptr; // Break the link
        return nextHead;
    }

    // Helper function to merge two sorted lists and return the new head
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode*& tail) {
        ListNode dummy(0);
        tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        while (tail->next) {
            tail = tail->next; // Move tail to the actual end of the merged list
        }
        
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Count total nodes
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // Bottom-up merge sort iterative approach
        for (int size = 1; size < n; size *= 2) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);

                ListNode* mergedTail = nullptr;
                ListNode* mergedHead = merge(left, right, mergedTail);
                
                tail->next = mergedHead;
                tail = mergedTail;
            }
        }

        return dummy.next;
    }
};