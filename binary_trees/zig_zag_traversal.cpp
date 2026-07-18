class Solution {
public:
    bool leftToRight = true;
    void solve(vector<vector<int>> &ans ,queue<TreeNode*>& q , TreeNode* root){
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);

            for(int i=0; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i ;
                level[index]=node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }
            leftToRight = !leftToRight;
            ans.push_back(level);

        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
       vector<vector<int>>ans;
       queue<TreeNode*>q;
       solve(ans , q , root);
       return ans;  
    }
};