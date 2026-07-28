class Solution {
public:
    int cnt=0;
    int ans=-1;
    int inorder(TreeNode* root , int k){
        if(root==NULL) return 0;

        inorder(root->left , k);
        cnt++;

        if(cnt==k){
          ans  =  root->val;
        }

        inorder(root->right , k);

        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        return inorder(root,k);     
    }
};