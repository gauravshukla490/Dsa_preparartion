class Solution {
  public:
   
    vector<int> inOrder(Node* root) {
     if(root==NULL) return {};
     stack<Node*>st;
     vector<int>ans;
     
     Node* temp=root;
     
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()==true) break;
            
            temp=st.top();
            st.pop();
            
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
     return ans;
    }
};