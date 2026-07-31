 class BSTiterator{
    stack<TreeNode*>st;
    bool reverse;
     
     void pushAll(TreeNode* root ){
         while(root!=NULL){
            st.push(root);
            if(!reverse){
                root = root->left;
            }
            else root=root->right;
         }
     }
    
    public:
       
        BSTiterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root );
    }

    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);

        else pushAll(temp->left);

        return temp->val;
    }

 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        
        BSTiterator L(root , false);
        BSTiterator R(root , true);

        int i = L.next();
        int j = R.next();

        while(i<j){
           if(i + j == k){
            return true;
           }

           else if(i + j < k){
            i = L.next();
           }

           else j = R.next();
        }
       return false;
    }
};