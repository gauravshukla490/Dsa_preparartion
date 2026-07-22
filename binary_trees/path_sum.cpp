class Solution {
public:
    bool sum(TreeNode* root , int targetSum , int currSum){
    if(root==NULL) return false;

     currSum += root->val;
     
     if(root->left == NULL && root->right==NULL){
        if(currSum == targetSum) return true;

        else return false;
     }

     if( sum(root->left , targetSum , currSum) ||
      sum(root->right , targetSum , currSum)){
        return true;
      }

      currSum -= root->val;
      return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==NULL) return false;
    int currSum=0;
    
    return sum(root , targetSum ,currSum );

    }
};