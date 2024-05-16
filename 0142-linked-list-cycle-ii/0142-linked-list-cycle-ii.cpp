/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            int index = 0;
            
            if(slow == fast){
                slow = head;
                break;
            }
        }
        
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }
        
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        if(slow == fast){
            return slow;
        }
       return NULL; 
    }
};