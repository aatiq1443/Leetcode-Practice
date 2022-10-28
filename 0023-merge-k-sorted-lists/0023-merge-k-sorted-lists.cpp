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
class compare{
public:
        bool operator()( ListNode * a , ListNode *b){
            return a->val>b->val;
        }    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;
        
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next){
                pq.push(temp->next);
            }
        }
        return dummy->next;
    }
};