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
        
       ListNode* temp=head;
        int count=0;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL && count<k-1){
            temp=temp->next;
            count++;
        }
        int size_rev=0;
        ListNode* rev=head;
        while(rev!=NULL && size_rev<size-k){
            size_rev++;
            rev=rev->next;
        }
        swap(temp->val,rev->val);
        return head;
    }
};