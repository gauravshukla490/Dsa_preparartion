class Solution {
public:
   void markParents(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parent){
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
   } 
     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        unordered_map<TreeNode*,TreeNode*>parent;
        markParents(root , parent);
        
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            if(level == k) break;
            for(int i = 0; i < size ; i++){
                 TreeNode* curr = q.front();
                 q.pop();

                 if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                 }
                 if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                 }

                 if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                 }
            }
             level++;
        }
        vector<int>result;
        while(!q.empty()){
           TreeNode* curr = q.front();
           q.pop();
           result.push_back(curr->val);
        }  
         return result;
    }
};