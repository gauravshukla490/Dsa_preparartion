int Solution::solve(vector<int> &A, int B) {
    if(A.size()==0 || B==0) return 0;
    
    priority_queue<int>p;
    
    for(int i = 0;i < A.size();i++){
        p.push(A[i]);
    }
    
    int  profit = 0;
    while(B--){
       int cost = p.top();
       p.pop();
       
       profit += cost;
       
       if(cost--){
           p.push(cost--);
       } 
    }
    return profit;
}