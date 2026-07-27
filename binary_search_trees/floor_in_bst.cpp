class Solution {
  public:
    int ans = -1;
    int floor(Node* root , int k){
        if(root->data <=k ){
            ans = root->data;
            if(root->right) floor(root->right , k);
        }
        else if(root->left) floor(root->left , k);
        
        return ans;
        
    }
    int findMaxFork(Node* root, int k) {
        if(root==NULL) return ans;
        return floor( root , k);
        
    }
};