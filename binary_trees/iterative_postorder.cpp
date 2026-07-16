class Solution {
  public:
    vector<int> postOrder(Node* node) {
        if(node==NULL) return {};
        vector<int>ans;
        stack<Node*>st1;
        stack<Node*>st2;
        
        st1.push(node);
        
        while(!st1.empty()){
            Node* temp = st1.top();
            st1.pop();
            
            st2.push(temp);
            
            if(temp->left) st1.push(temp->left);
            
            if(temp->right) st1.push(temp->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }
};