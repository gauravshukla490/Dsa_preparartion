class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root==NULL) return true;
        
         if(root->left == NULL && root->right == NULL) return true;
         
         int left =0 , right = 0;
         
         if(root->left) left=root->left->data;
         if(root->right) right=root->right->data;
        
        if((root->data == (left + right)) && isSumProperty(root->left) &&
         isSumProperty(root->right)){
             return true;
         }
        
        return false;
        
    }
};