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
    
    ListNode *getMid(ListNode *head){
        if(!head || !head->next) return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
    }
    
    ListNode *reverse(ListNode *head){
        if(!head || !head->next) return head;
        
        ListNode *newnode = reverse(head->next);
        
        head->next->next = head;
        head ->next = NULL;
        
        return newnode;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *middle = getMid(head);   
        
        ListNode *temp = middle;
        
        middle = reverse(temp);
        
        ListNode *head1 = head;
        ListNode *head2 = middle;
        
        while(head2){
            if(head1->val != head2->val ) return false;
            head1 = head1->next;
            head2 = head2->next;
                
        }
        
        return true;
        
    }
};