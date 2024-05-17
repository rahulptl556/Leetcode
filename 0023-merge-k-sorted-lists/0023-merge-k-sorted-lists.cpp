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
        ListNode* merge(ListNode* head1, ListNode* head2 ){
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        
        while(head1 && head2){
            if(head1->val <= head2->val){
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
                tail->next = NULL;
            }
            else{
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        if(head1){
            tail->next = head1;
        }
        else{
            tail->next = head2;
        }
        return head->next;
    }
    
    void mergesort(vector<ListNode*>arr, int s, int e){
        if(s>=e){
            return;
        }
        int m = s + (e-s)/2;
        
        // Left Part
        mergesort(arr, s, m);
        
        // Right Part
        mergesort(arr, m+1, e);
        
        arr[s] = merge(arr[s],arr[m+1]);
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int K = lists.size();
        if(K==0){
            return NULL;
        }
      
       ListNode* head = lists[0];
           for(int i=1; i<K; i++){
               head = merge(head,lists[i]);
           }
           return head;
    }
    
};