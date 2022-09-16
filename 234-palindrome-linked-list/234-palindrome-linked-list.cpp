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
    ListNode* midNode(ListNode *head){
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast = fast ->next ->next;
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
    
        ListNode* middle = midNode(head);

        ListNode * temp = middle->next;

        middle->next = reverse(temp);

        ListNode *head1 = head;
        ListNode *head2 = middle->next;

        while(head2!= NULL){

            if(head1->val != head2->val) return 0;

            head1 = head1->next;

            head2 = head2->next;

        }
    return 1;
    }
    
    
};