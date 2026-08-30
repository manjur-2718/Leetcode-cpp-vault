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
        Node* temp = head;
        map<Node*,Node*> mpp;
        while(temp){
            Node* node = new Node(temp->val);
            mpp[temp]= node;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};