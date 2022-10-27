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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        int cnt = 0;
        
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while(curr && cnt<2){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
            
        }
        if(next)
            head->next = swapPairs(next);
        
        return prev;
        
    }
};