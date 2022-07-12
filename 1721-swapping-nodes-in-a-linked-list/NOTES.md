ListNode* reverse(ListNode* &head, int k){
ListNode* curr=head;
ListNode* prev=NULL;
ListNode* next_ele=NULL;
while(curr){
next_ele=curr->next;
curr->next=prev;
prev=curr;
curr=next_ele;
}
int count=0;
while(prev!=NULL && count<k-1){
count++;
prev=prev->next;
}
cout<<prev->val;
return prev;
}
ListNode* swapNodes(ListNode* head, int k) {
if(head==NULL) return NULL;
int count=0;
ListNode* last=reverse(head,k);
ListNode* temp=head;
while(temp!=NULL && count<k-1){
temp=temp->next;
count++;
}
// swap(temp->val,last->val);
ListNode* dummy=temp;
cout<<dummy->val;
cout<<endl<<last->val;
return head;