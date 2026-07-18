class Solution {
  public:
    bool isLeaf(Node* root){
        if(root==NULL) return false;
        return (root->left == NULL && root->right == NULL) ;
        
    }
    
    void leftTraversal(Node* root , vector<int>& ans){
        Node * curr = root->left;
        while(curr ){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
             if(curr->left) curr=curr->left;
               else curr=curr->right;
        }
    }
    
    void rightTraversal(Node* root , vector<int>& ans){
        Node* curr = root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
             if(curr->right) curr=curr->right;
                else curr=curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    
    void leafTraversal(Node* root , vector<int>& ans){
        if(root==NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        
        if(root->left) leafTraversal(root->left,ans);
        if(root->right) leafTraversal(root->right,ans);
    }
    vector<int> boundaryTraversal(Node *root) {
     vector<int>ans;
     if(root==NULL) return ans;
     if(!isLeaf(root)) ans.push_back(root->data);
     
     leftTraversal(root,ans);
     leafTraversal(root,ans);
     rightTraversal(root,ans);
     
     return ans;
  }
};