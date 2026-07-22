class Solution {
  public:
  vector<vector<int>>ans;
    
    void allPaths(Node* root, vector<int>& temp){
        if(root==NULL) return ;
        
        temp.push_back(root->data);
        
       if(root->left==NULL && root->right==NULL){
           ans.push_back(temp);
       }
       
       if(root->left) allPaths(root->left , temp);
       
       if(root->right) allPaths(root->right , temp);
       
        temp.pop_back();
    }
    vector<vector<int>> paths(Node* root) {
     if(root==NULL) return ans;
     vector<int>temp;
     allPaths(root , temp);
     return ans;
     
    }
};