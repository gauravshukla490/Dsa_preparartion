class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(TreeNode* root , int targetSum , vector<int>& temp , int currSum){
        if(root==NULL) return ;

         temp.push_back(root->val);
         currSum += root->val;

        if(root->left == NULL && root->right==NULL){
            if(currSum == targetSum){
                ans.push_back(temp);
            }
        }
        solve(root->left , targetSum , temp , currSum);
        solve(root->right , targetSum , temp , currSum);

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       if(root==NULL) return ans;
       vector<int>temp;
       int currSum = 0;
       solve(root , targetSum , temp , currSum);
       return ans; 
    }
};