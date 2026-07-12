#include <bits/stdc++.h>
using namespace std;

void findSubset(int idx, vector<int>& nums,
                vector<int>& temp,
                vector<vector<int>>& ans) {
 
    ans.push_back(temp);

    for (int i = idx; i < nums.size(); i++) {

        if (i != idx && nums[i] == nums[i - 1])
            continue;

        temp.push_back(nums[i]);

        findSubset(i + 1, nums, temp, ans);

        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> temp;

    sort(nums.begin(), nums.end());

    findSubset(0, nums, temp, ans);

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ans = subsetsWithDup(nums);

    for (auto subset : ans) {

        cout << "[ ";

        for (int x : subset)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}