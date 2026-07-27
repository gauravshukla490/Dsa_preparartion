class Solution {
  public:
 
    int minValue(Node* root) {
        if(root==NULL) return -1;
        
        while(root->right){
            root = root->right;
        }
        return root->data;
    }
};