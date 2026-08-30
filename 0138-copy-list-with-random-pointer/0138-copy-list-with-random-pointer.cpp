/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        temp = head;
        while(temp){
            Node* copy = temp->next;
            Node* random = temp->random;
            if(random){
                copy->random = random->next;
            }
            else{
                copy->random = random;
            }
            temp = copy->next;
        }
        
        temp = head;
        Node* copyHead = temp->next;
        Node* copy = copyHead;
        while(temp){
            temp->next = temp->next->next;
            temp = temp->next;
            if(copy->next){
                copy->next = copy->next->next;
                copy = copy->next;
            }
        }
        return copyHead;
    }
};