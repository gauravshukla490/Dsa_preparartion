class Solution {
  public:
    vector<int> preOrder(Node* root) {
     vector<int>ans;
     if(root==NULL) return ans;
     
     Node* curr = root;
     while(curr){
         if(curr->left==NULL){
             ans.push_back(curr->data);
             curr = curr->right;
         }
         else{
             Node* temp = curr->left;
             while(temp->right && temp->right != curr){
                 temp = temp->right;
             }
             
             if(temp->right==NULL){
                 temp->right = curr;
                 curr = curr->left;
             }
             else{
                 temp->right = NULL;
                  ans.push_back(curr->data);
                 curr=curr->right;
             }
         }
     }
        return ans;
    }
};