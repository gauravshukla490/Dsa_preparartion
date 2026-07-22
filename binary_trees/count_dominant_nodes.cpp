class Solution {
public:
    int cnt = 0;

    int count(TreeNode* root){
        if(root==NULL) return 0;

          int left = count(root->left);
         int right = count(root->right);

         if(root->val >= left && root->val >= right){
            cnt++;
            return root->val;
         }

         int max1 = max(left,right);
         int max2 = max(max1,root->val);

         return max2;


    }
    int countDominantNodes(TreeNode* root) {
        if(root==NULL) return cnt;
        count(root);
        return cnt;
    }
};