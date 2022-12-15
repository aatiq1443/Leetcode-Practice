class FindElements {
    TreeNode* head=new TreeNode(-1);
public:
    FindElements(TreeNode* root) {
        head=root;
        head->val=0;
        recover(head);
    }
    
    void recover(TreeNode* root)
    {
        if(root->left)
        {
            root->left->val=(root->val)*2+1;
            recover(root->left);
        }
        if(root->right)
        {
            root->right->val=(root->val)*2+2;
            recover(root->right);
        }
        return;
    }
    
    bool find(int target) {
        return get(target,head);
    }
    
    bool get(int target,TreeNode* root)
    {
        if(root==NULL)
            return false;
        if(root->val==target)
            return true;
        
        bool t1=get(target,root->left);
        bool t2=get(target,root->right);
        
        if(t1||t2)
            return true;
        return false;
    }
};