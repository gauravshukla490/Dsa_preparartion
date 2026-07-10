#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int>& nums, int N, int idx,
                          vector<vector<int>>& ans, vector<int> temp)
{
    if(idx == N){
        ans.push_back(temp);
        return ans;
    }

    temp.push_back(nums[idx]);
    solve(nums, N, idx + 1, ans, temp);

    temp.pop_back();
    solve(nums, N, idx + 1, ans, temp);

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans;
    vector<int> temp;

    ans = solve(nums, nums.size(), 0, ans, temp);

    for(auto &v : ans){
        cout << "[ ";
        for(int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}