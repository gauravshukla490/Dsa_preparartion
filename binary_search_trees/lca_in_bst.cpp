class Solution {
public:
     TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;

        if((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val) || (root->val == p->val) || (root->val == q->val)){
            return root;
        }

        else if(p->val < root->val && q->val < root->val){
             return findLCA(root->left , p , q);
        }

        else{
           return  findLCA(root->right , p , q);
        }
     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
       return findLCA(root , p , q);
    }
};