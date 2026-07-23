class Solution {
public:
    int countLeft(TreeNode* root){
        int height = 0;
       while(root){
           height++;
           root=root->left;
       }
        return height;
    }
    int countRight(TreeNode* root){
        int height = 0;
       while(root){
        height++;
        root=root->right;
       }
        return height;
    }
    int countNodes(TreeNode* root) {
       
    if(root==NULL) return 0;
     
    int lh = countLeft(root);
    int rh = countRight(root);

    if(lh==rh){
        return (int)pow(2,lh)-1;
    }
     return 1 + countNodes(root->left) + countNodes(root->right);
    }
};