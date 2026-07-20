class Solution {
public:
    int countNodes(TreeNode* root) {
       
        if(root==NULL) return 0;

      queue<TreeNode*>q;
      q.push(root); 
       int cnt=0;

      while(!q.empty()){
        auto it = q.front();
        q.pop();

       cnt++;

       if(it->left) q.push(it->left);
       if(it->right) q.push(it->right);  
      } 

      return cnt;
    }
};