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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int head1=0;
            if(l1!=NULL){
                head1=l1->val;
            }
           int head2=0;
            if(l2!=NULL){
                head2=l2->val;
            }
            int sum = carry + head1 + head2;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
             if(l1!=NULL) 
                l1=l1->next;
            if(l2!=NULL) 
                l2=l2->next;
        }
        return dummy->next;
    }
};