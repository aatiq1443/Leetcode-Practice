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
        int k=2;
        int count=0;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next_ele;
        if(head==NULL){
            return NULL;
        }
        while(curr!=NULL && count<k){
            count++;
            next_ele=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_ele;
        }
        if(next_ele!=NULL){
            head->next=swapPairs(next_ele);
        }
        return prev;
    }
};