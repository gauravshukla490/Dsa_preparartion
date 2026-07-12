#include <bits/stdc++.h>
using namespace std;

void findCombination(int idx, int target,
                     vector<int>& candidates,
                     vector<int>& temp,
                     vector<vector<int>>& ans) {

    // Target achieved
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    // Target negative
    if (target < 0)
        return;

    // try choices from current state
    for (int i = idx; i < candidates.size(); i++) {

        // Skip duplicate elements at the same recursion level
        if (i != idx && candidates[i] == candidates[i - 1])
            continue;

        // Optimization
        if (candidates[i] > target)
            break;

        // CHOOSE
        temp.push_back(candidates[i]);

        // EXPLORE
        // i+1 because every element can be used only once
        findCombination(i + 1, target - candidates[i],
                        candidates, temp, ans);

        // UNDO
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    vector<vector<int>> ans;
    vector<int> temp;

    sort(candidates.begin(), candidates.end());

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

    vector<vector<int>> ans = combinationSum2(candidates, target);

    for (auto combination : ans) {

        cout << "[ ";

        for (int x : combination)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}