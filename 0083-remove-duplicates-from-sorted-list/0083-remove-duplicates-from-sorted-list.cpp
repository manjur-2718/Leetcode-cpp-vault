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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr= head->next;
        ListNode* prev= head;
        int prevData = prev->val;
        while(curr){
            ListNode* front = curr->next;
            if(prevData==curr->val){
                prev->next=front;
                delete curr;
            }
            else{
                prev=curr;
                prevData=prev->val;
            }
            curr=front;
        }
        return head;
    }
};