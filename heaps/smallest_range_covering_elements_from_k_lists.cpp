class Solution {
public:
    struct compare{

        bool operator()(vector<int>&a , vector<int>&b){
             return a[0] > b[0];
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int> , vector<vector<int>> , compare>p;

        int k = nums.size();
        int curr_max = INT_MIN;

        for(int i = 0; i < k; i++){
            p.push({nums[i][0] , i , 0});
            curr_max = max(curr_max , nums[i][0]);
        }

        int start = 0;
        int end = INT_MAX;

        while(p.size() == k){

            vector<int>curr = p.top();
            p.pop();

            int curr_min = curr[0];
            int row = curr[1];
            int col = curr[2];

            if(curr_max - curr_min < end - start){
                start = curr_min;
                end = curr_max;
            }

            if(col + 1 < nums[row].size()){

                int next_val = nums[row][col+1];
                p.push({next_val , row , col + 1});
                curr_max = max(curr_max , next_val);
            }
        }

        return {start , end};
    }
};