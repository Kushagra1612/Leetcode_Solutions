/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lesshead(0),greaterhead(0);
        ListNode* lesstail=&lesshead;
        ListNode* greatertail=&greaterhead;

        ListNode* current=head;
        while(current!=nullptr){
            if(current->val<x){
                lesstail->next=current;
                lesstail=lesstail->next;
            }
            else{
                greatertail->next=current;
                greatertail=greatertail->next;
            }
            current=current->next;
        }

        lesstail->next=greaterhead.next;
        greatertail->next=nullptr;

        return lesshead.next;
    }
};