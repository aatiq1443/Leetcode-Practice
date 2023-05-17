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
    
    ListNode *reverse(ListNode *head){
        
       if(head==NULL || head->next==NULL) return head;
        
        ListNode *node=reverse(head->next);
        
        head->next->next=head;
        head->next=NULL;
        return node;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast ->next && fast->next->next){
            
            slow= slow->next;
            fast = fast->next->next;
            
        }
        
        ListNode *middle = reverse(slow->next);
        // cout<<middle ->val;
        int ans=0;
        
        while(middle!=NULL){
            
            int temp = head->val + middle->val;
            // cout<<temp<<" ";
            ans = max(ans , temp);
            
            head =head->next;
            middle = middle ->next;
            
        }
        return ans;
        
        
    }
};





