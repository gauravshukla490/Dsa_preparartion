class Solution {
  public:
     void  postorder(Node* root , vector<int>& ans , int& idx){
         if(root==NULL) return;
         
         postorder(root->left , ans, idx);
         postorder(root->right , ans, idx);
         
         root->data = ans[idx];
         idx++;
         
     }
    void  inorder(Node* root , vector<int>& ans){
        if(!root) return;
        
        inorder(root->left , ans);
        ans.push_back(root->data);
        inorder(root->right , ans);
    }
    void convertToMaxHeapUtil(Node* root) {
        vector<int>ans;
        inorder(root , ans);
        int idx=0;
        postorder(root,ans,idx);
    }
};
