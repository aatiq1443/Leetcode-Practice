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
//         if(head==NULL){
//             return NULL;
//         }
//         ListNode * temp= head;
//         ListNode * curr=deleteDuplicates(head->next);
        
//         if(temp->val==curr->val){
            
//             return temp->next;
//         }
//         return temp;
        
        if(!head || !head->next) return head;
        
        head->next=deleteDuplicates(head->next );
        
        return head->val == head->next->val ? head->next : head;
        
    }
};