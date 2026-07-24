
class Solution {
public:
    unordered_map<int,int>InMap;
     
    TreeNode* solve(vector<int>&inorder , int inStart  , int inEnd , vector<int>&postorder , int postStart , int postEnd){

        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int k = InMap[root->val];

        int leftSize = k - inStart;

        root->left = solve(inorder , inStart , inStart + leftSize - 1 ,
                           postorder , postStart , postStart + leftSize -1);

        root->right = solve(inorder , inStart + leftSize + 1 , inEnd ,
                            postorder , postStart + leftSize , postEnd- 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            InMap[inorder[i]]=i;
        }

        return solve(inorder , 0 , inorder.size() -1 ,
                      postorder , 0 , postorder.size()-1);


    }
};