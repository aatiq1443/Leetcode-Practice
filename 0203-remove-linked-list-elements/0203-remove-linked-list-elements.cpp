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
    ListNode* removeElements(ListNode* head, int val) {
            
        
        
        if(!head) return NULL;
        
        if(head->val == val && !head->next) return NULL;
        
        if(!head->next) return head;
        
        ListNode *dummy = new ListNode (0 , head);
        ListNode *prev = dummy;
        
        ListNode *curr = head;
        
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
