while(curr!=NULL){
count++;
if(count==left){
while(curr!=NULL  and count<right-1){
ListNode*temp=curr;
ListNode*prev=NULL;
ListNode*next_ele;
​
while(temp!=NULL){
next_ele=temp->next;
curr->next=prev;
prev=curr;
curr=next_ele;
}
dummy->next=prev;
}
}
else{
curr=curr->next;
dummy=curr;
}
}
return head;
}
};