class Solution {
public:
ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0,head);
    ListNode* prev=&dummy;

    while(prev->next && prev->next->next){
        ListNode* first=prev->next;
        ListNode* second =prev->next->next;
        
        prev->next=second;
        first->next=second->next;
        second->next=first;

        prev=first;
    }
        return dummy.next;
    }
};
    // ListNode* swapPairs(ListNode* head) {
    //     if(!head || !head->next) return NULL;

    //     ListNode* first=head;
    //     ListNode* second=head->next;

    //     first->next=swapPairs(second->next);
    //     second->next =first;

    //     return second;
    // }