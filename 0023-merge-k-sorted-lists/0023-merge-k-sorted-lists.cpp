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
struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return (a->val)>(b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(ListNode* head:lists){
            if(head!=NULL) pq.push(head);
        }
        if(pq.empty()) return nullptr;

        ListNode* res=nullptr;
        ListNode* head=nullptr;
        while(!pq.empty()){
            ListNode *n=pq.top();
            pq.pop();
            if(head==NULL){
                head=n;
                res=n;
            }
            else{
                res->next=n;
                res=n;
            }

            if(n->next!=NULL){
                pq.push(n->next);
            }

        }
        return head;
        
    }
};