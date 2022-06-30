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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==1){
            return NULL;
        }
        int pos=count-n;
        count=0;
        temp=head;
        if(pos==0){
            return head->next;
        }
        while(count<(pos-1)){
            count++;
            temp=temp->next;
        }
       ListNode* new_temp=temp->next->next;
        temp->next=new_temp;
        return head;
    }
};