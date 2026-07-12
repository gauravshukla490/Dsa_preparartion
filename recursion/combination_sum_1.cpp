#include <bits/stdc++.h>
using namespace std;

void findCombination(int idx, int target,
                     vector<int>& candidates,
                     vector<int>& temp,
                     vector<vector<int>>& ans) {

    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    if (target < 0)
        return;

    for (int i = idx; i < candidates.size(); i++) {

        temp.push_back(candidates[i]);

    //i because same element can be choosen unlimited times
        findCombination(i, target - candidates[i],
                        candidates, temp, ans);

        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> ans;
    vector<int> temp;

    findCombination(0, target, candidates, temp, ans);

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> candidates(n);

    for (int i = 0; i < n; i++)
        cin >> candidates[i];

    int target;
    cin >> target;

    vector<vector<int>> ans = combinationSum(candidates, target);

    for (auto combination : ans) {

        cout << "[ ";

        for (int x : combination)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}