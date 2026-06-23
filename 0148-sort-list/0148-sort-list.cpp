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
private:
    ListNode* findMid(ListNode* head){
        ListNode* fast = head -> next;
        ListNode* slow  = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode* ans = new ListNode (-1);
        ListNode* mvr = ans;
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                mvr -> next = l1;
                l1 = l1 -> next;
                mvr = mvr -> next;
            }
            else{
                mvr -> next = l2;
                l2 = l2 -> next;
                mvr = mvr -> next;
            }
        }
        if(l1) mvr -> next = l1;
        else mvr -> next = l2;
        return ans -> next;
    }

    ListNode* ms(ListNode* head){
        if(head == NULL || head -> next == nullptr) return head;
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = nullptr;
        left = ms(left);
        right = ms(right);
        return merge(left , right);
    }
public:
    ListNode* sortList(ListNode* head) {
       return ms(head);
    }
};