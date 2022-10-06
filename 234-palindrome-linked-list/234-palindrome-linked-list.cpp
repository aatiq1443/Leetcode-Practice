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
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast && fast->next){
            slow= slow->next;
            fast = fast->next ->next;
        }
        return slow;
        
    }
    
    ListNode *reverse(ListNode *head){
        
        ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next_ele = NULL;
    
    while(curr!=NULL){
        
        next_ele= curr->next;
        curr->next = prev;
        prev= curr;
        
        curr= next_ele;
        
    }
    return prev;
        
    }
    
    
    bool isPalindrome(ListNode* head) {
        
         if(!head || !head->next) return true;
        
        if(head->next->next == NULL){
            if(head->val != head ->next ->val) return false;
            else return true;
        }
        
        ListNode *mid = getMid(head);
        
        ListNode *temp = mid->next;
        
        mid->next = reverse(temp);
        
        ListNode *head1 = head ; 
        ListNode *head2 = mid->next;
        
        while(head2){
            if(head1->val != head2->val) return false;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};