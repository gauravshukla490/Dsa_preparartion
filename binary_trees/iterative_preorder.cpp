class Solution {
  public:
    void solve(Node* root , stack<Node*>&st , vector<int>& ans){
        st.push(root);
        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
        }
    }
    vector<int> preOrder(Node* root) {
        if(root==NULL) return {};
        stack<Node*>st;
        vector<int>ans;
        solve(root , st , ans);
        return ans;
        
    }
};