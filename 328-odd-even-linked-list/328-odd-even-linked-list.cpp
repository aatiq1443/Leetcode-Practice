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
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode *curr = head;
        ListNode *next_ele = head->next;
        ListNode *temp;
        while(next_ele && next_ele->next){
            temp = next_ele ->next;
            next_ele -> next = temp ->next;
            temp->next = curr->next;
            curr->next = temp;
            
            curr = curr->next;
            next_ele = next_ele ->next;
        } 
        return head;
    }
};