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
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int cnt = 0;
        
        ListNode *temp = head;
        
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        int len = cnt/k;
        int extra = cnt%k;
        
        temp = head;
        
        vector<ListNode*> ans;
        
        while(temp){
            ans.push_back(temp);
            
            int curr = 1;
            
            while(curr < len){
                temp = temp->next;
                curr++;
            }
            
            if(extra>0 && cnt > k){
                temp = temp->next;
                extra--;
            }
            
            ListNode *x = temp->next;
            temp->next = NULL;
            temp = x;
            
            
        }
        
        while(cnt <k ){
            ans.push_back(NULL);
            cnt++;
        }
        
        
        return ans;
        
    }
};