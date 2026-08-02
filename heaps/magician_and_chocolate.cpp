int Solution::nchoc(int A, vector<int> &B) {
    if(A==0 || B.size()==0) return 0;
    
    int mod = 1e9+7;
    priority_queue<int>p;
    
    for(int i=0;i<B.size();i++){
        p.push(B[i]);
    }
    
    long long ans = 0;
    
    while(A--){
        int chocolate = p.top();
        p.pop();
        
        ans = (ans + chocolate) % mod;
        
        p.push(chocolate/2);
        
    }
    
    return (int)ans;
}
