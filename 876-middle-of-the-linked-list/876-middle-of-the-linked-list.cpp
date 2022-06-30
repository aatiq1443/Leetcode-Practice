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
    ListNode* solve(ListNode* head , int pos){
        int count=0;
        ListNode* temp=head;
        while(count<(pos-1)){
            count++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
            count++;
           temp=temp->next;
        }
        int var=count/2;
        var+=1;
        return solve(head,var);
        
        
        
        
    }
};