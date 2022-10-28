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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = NULL;
        
        while(even && even->next){
            temp = even->next;
            
            even->next = temp->next;
            temp->next = odd->next;
            odd->next = temp;
            
            odd = odd->next;
            even = even->next;
        }
        
        return head;
    }
};