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
        if(head == nullptr) return head;
        Node* mvr = head;
        while(mvr){
            Node *temp = new Node(mvr -> val);
            temp -> next = mvr -> next;
            mvr -> next = temp;
            mvr = mvr -> next -> next;
        } 
        Node* new_node = head -> next;
        Node* old_node = head;
        while(old_node){
            if(old_node -> random == nullptr) new_node -> random = nullptr;
            else new_node -> random = old_node -> random -> next;
            if(new_node -> next)new_node = new_node -> next -> next;
            old_node = old_node -> next -> next;
        }

        Node* ans = head -> next;
        Node* mvr1 = head;
        Node* mvr2 = ans;
        while(mvr1){
            Node* temp = mvr2 -> next;
            if(mvr2 -> next) mvr2 -> next = mvr2 -> next -> next;
            mvr2 = mvr2 -> next;
            mvr1 -> next = temp;
            mvr1 = temp;
        }
        return ans;
    }
};