class Solution {
  public:
    void bfs(vector<int>& ans , Node* root , queue<Node*>&q ){
        if(root==NULL) return;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            ans.push_back(temp->data);
            
           if(temp->left){
                q.push(temp->left);
           }
            
           if(temp->right){
                q.push(temp->right);
           }
        }
    }
    vector<int> levelOrder(Node *root) {
        if(root==NULL) return {};
        queue<Node*>q;
        vector<int>ans;
        bfs(ans,root,q);
        return ans;
        
    }
};