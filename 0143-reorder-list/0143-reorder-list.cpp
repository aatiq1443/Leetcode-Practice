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
    void reorderList(ListNode* head) {
        
         if(head->next==NULL || head->next->next==NULL){
            return;
        }
        
        ListNode* temp=head;
        
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        
        temp->next->next=head->next;
        head->next=temp->next;
        temp->next=NULL;
        
        reorderList(head->next->next);
     
        
    }
};