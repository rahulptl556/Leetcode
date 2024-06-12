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
        ListNode* prev = head;
       if(head == NULL || head -> next == NULL){
           return head;
       }
        ListNode* curr = prev -> next;
        
        while(curr){
            if(prev -> val == curr -> val){
                prev -> next = curr -> next;
                delete curr;
                curr = prev -> next;
            }
            else{
                prev = prev -> next;
                curr = curr -> next;
            }
        }
        return head;
    }
};