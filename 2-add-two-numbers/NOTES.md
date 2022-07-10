* };
*/
class Solution {
public:
// reverse the linked list
ListNode* reverse(ListNode* head){
ListNode* curr=head;
ListNode* prev=NULL;
ListNode* next_ele;
while( curr != NULL){
next_ele=curr->next;
curr->next = prev;
prev = curr;
curr = next_ele;
}
return prev;
}
//insert at the end
void insAtEnd(ListNode* &head, ListNode * &tail , int data){
ListNode* temp=new ListNode(data);
if(head==NULL){
head=temp;
tail=temp;
return;
}
else{
tail->next=temp;
tail=temp;
}
}
// add both the modulo data and carry of addition should also be added
ListNode* add(ListNode* head1 , ListNode* head2){
int carry=0;
ListNode* ansHead=NULL;