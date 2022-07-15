}
while(!q.empty()){
TreeNode* temp=q.front();
q.pop();
if(temp==NULL){
ans.push_back(vec);
if(!q.empty()){
q.push(NULL);
}
else{
vec.push_back(temp->val);
if(temp->left!=NULL){
q.push(temp->left);
}
if(temp->right!=NULL){
q.push(temp->right);
}
}
}
}
return ans;
}
};