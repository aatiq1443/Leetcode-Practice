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
         int size = 0;
        ListNode *temp = head;
        while(temp){
            temp =temp ->next;
            size++;
        }
        
        int total = size - n;
        
        if(total == 0) return head->next;
        
        temp = head;
        int cnt = 0;
        while(temp && cnt<total-1){
            temp =temp ->next;
            cnt++;
        }
        
        temp->next = temp->next->next;
        return head;
        
    }
};