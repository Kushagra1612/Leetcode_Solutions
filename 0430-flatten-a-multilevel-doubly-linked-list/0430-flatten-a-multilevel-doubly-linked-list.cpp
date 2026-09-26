class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;

        stack<Node*> stlk;
        stlk.push(head);

        Node dummy(0);
        Node* prev=&dummy;

        while(!stlk.empty()) {
            Node* curr=stlk.top();
            stlk.pop();

            Node* nextNode = curr->next;

            prev->next=curr;
            curr->prev=prev;

            if(nextNode){
                stlk.push(nextNode);
            }
            if(curr->child){
                stlk.push(curr->child);
                curr->child=nullptr;
            }
            prev=curr;
        }
        head->prev=nullptr;
        return head;
    }
};