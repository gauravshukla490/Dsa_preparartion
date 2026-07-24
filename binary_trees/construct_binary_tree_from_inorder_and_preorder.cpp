class Solution {
public:
    unordered_map<int , int>InMap;

    TreeNode* solve(vector<int>& preorder , int preStart , int preEnd , vector<int>&inorder , int inStart , int inEnd){

        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int k = InMap[root->val];

        int leftSize = k - inStart;

        root->left = solve(preorder , preStart + 1 , preStart + k ,
                           inorder , inStart , k - 1);

        root->right = solve(preorder , preStart + leftSize + 1 , preEnd ,
                            inorder , k + 1 , inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            InMap[inorder[i]]=i;
        }

       return solve(preorder , 0 , preorder.size() - 1 ,
              inorder , 0 , inorder.size() - 1);
    }
};