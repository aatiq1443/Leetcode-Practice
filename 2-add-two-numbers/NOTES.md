ListNode* ansTail=NULL;
while(head1!=NULL || head2!=NULL || carry!=0){
int data1=0;
if(head1!=NULL){
data1=head1->val;
}
int data2=0;
if(head1!=NULL){
data2=head1->val;
}
int sum=data1+data2+carry;
int digit=sum%10;
​
insAtEnd(ansHead,ansTail,digit);
carry=sum/10;
if(head1!=NULL)
head1=head1->next;
if(head2!=NULL)
head2=head2->next;
}
return ansHead;
}
ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
//reverse both the linked list to add from the right side
first=reverse(first);
second=reverse(second);
// add both linked list
ListNode* ans=add(first,second);
// reverse the linked list for required ans
ans=reverse(ans);
return ans;
}
};