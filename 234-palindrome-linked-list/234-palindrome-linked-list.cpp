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
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        
        ListNode *middle=getMid(head);
        
        ListNode*temp= middle->next;
        
        middle->next=reverse(temp);
        
        ListNode *head1=head;
        ListNode *head2=middle->next;
        
        while(head2!=NULL){
            if(head1->val!=head2->val) return false;
            
                head1=head1->next;
                head2=head2->next;
            
        }
        return true;
    }
    
    ListNode *getMid(ListNode *head){
        ListNode *slow=head;
        ListNode *fast= head-> next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
    ListNode *reverse(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *nextele=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return nextele;
    }
};