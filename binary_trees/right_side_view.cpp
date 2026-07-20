class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;

        queue<pair<TreeNode* , int>>q;
        map<int,int>mp;

        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int level = it.second;

            mp[level] = node->val;

            if(node->left) q.push({node->left , level+1});
            if(node->right) q.push({node->right , level+1});
        }
       for(auto it : mp){
        ans.push_back(it.second);
       }
      return ans;
    }
};