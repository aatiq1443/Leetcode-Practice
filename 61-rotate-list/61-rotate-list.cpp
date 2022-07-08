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
    ListNode* rotateRight(ListNode* head, int k) {
         vector<int>ans;
        ListNode* temp=head;
        if(head==NULL) return NULL;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        k=k%n;
        reverse(ans.begin(),ans.begin()+n-k);
        reverse(ans.begin()+n-k,ans.end());
        reverse(ans.begin(),ans.end());
    
        temp=head;
        int i=0;
        while(temp!=NULL){
            temp->val=ans[i++];
            temp=temp->next;
        }
        
        return head;
    }
};