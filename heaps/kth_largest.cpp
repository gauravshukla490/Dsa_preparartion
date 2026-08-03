class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    if(k > nums.size()) return -1;

    priority_queue<int , vector<int> , greater<int>>p; 

    for(int x : nums){
        p.push(x);

        while(p.size() > k){
            p.pop();
        }
    }

    return p.empty() ? -1 : p.top();
    }
};