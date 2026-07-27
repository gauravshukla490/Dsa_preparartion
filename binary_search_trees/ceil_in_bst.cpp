class Solution {
  public:
   int ans = -1;
   int ceil(Node* root , int x){
       
       if(root->data >= x){
           ans = root->data;
           if(root->left) ceil(root->left , x);
       }
       else if(root->right) ceil(root->right , x);
       
       return ans;
   }
    int findCeil(Node* root, int x) {
    if(root==NULL) return -1;
    return ceil(root , x);
        
    }
};
