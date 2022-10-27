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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        ListNode *kth = NULL;
        
        while(--k){
            
            temp1 = temp1->next;
        }
        kth = temp1;
        temp1 = temp1->next;
        
        while(temp1){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        swap(kth->val , temp2->val);
        
        return head;
        
    }
};