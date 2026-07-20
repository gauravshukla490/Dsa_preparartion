class Solution {
public:
    bool check(TreeNode* n1 , TreeNode* n2){
        if(n1==NULL && n2==NULL) return true;

        if(n1==NULL || n2==NULL) return false;

        if(n1->val != n2->val) return false;

        return check(n1->left , n2->right) &&
                check(n1->right , n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root->left , root->right);
    }
};