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
     ListNode* reverse(ListNode* head){
         
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
         
        while(current!=NULL){
            
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
         
        head=prev;
         
        return head;
         
    }
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=reverse(l1);
        l2=reverse(l2);
        
        ListNode* res = NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        
        int carry = 0,sum;
        while(l1||l2){
            
            sum = carry + (l1?l1->val:0)+(l2?l2->val:0);
            
            carry= (sum>=10)?1:0;
            sum=sum%10;
            temp = new ListNode(sum);
            if(res==NULL)
                res=temp;
            else
                prev->next=temp;
            prev=temp;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        
        if(carry>0) temp->next = new ListNode(carry);
        return reverse(res);
        
    }
   
};