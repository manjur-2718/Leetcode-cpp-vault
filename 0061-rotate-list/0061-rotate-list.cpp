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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int length=1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
            length++;
        }

        k=k%length;
        if(k==0) return head;

        int toTravel = length-k;
        ListNode* tail1 = head;
        while(--toTravel){
            tail1=tail1->next;
        }
        ListNode* front = tail1->next;
        tail1->next=NULL;
        ListNode* tail2=front;
        while(--k){
            tail2=tail2->next;
        }
        tail2->next = head;
        head = front;
        return head;
    }
};