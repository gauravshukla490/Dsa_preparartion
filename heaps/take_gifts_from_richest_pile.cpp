class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        if(gifts.size()==0) return 0;

        priority_queue<long long>p;

        for(int i = 0 ;i < gifts.size() ;i++){
            p.push(gifts[i]);
        }

        while(k--){
            long long gift = p.top();
            p.pop();

            p.push(sqrt(gift));
        }
        long long ans = 0 ;
        while(!p.empty()){
              ans +=  p.top();
              p.pop();
        }

        return ans;
    }
};