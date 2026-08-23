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
    void reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return;
    }
    ListNode* findNode(ListNode* head, int k) {
        int pos = 1;
        ListNode* temp = head;
        while (pos != k && temp) {
            pos++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while (temp) {
            ListNode* kthNode = findNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};