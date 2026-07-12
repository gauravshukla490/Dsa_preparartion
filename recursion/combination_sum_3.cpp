#include <bits/stdc++.h>
using namespace std;

void combo(int idx, int k, int target,
           vector<int>& temp,
           vector<vector<int>>& ans) {

    // Exactly k numbers choosen
    if (temp.size() == k) {

        // target achieved
        if (target == 0)
            ans.push_back(temp);

        return;
    }

    // Target negative 
    if (target < 0)
        return;

    // try all possible numbers from current state
    for (int i = idx; i <= 9; i++) {

        // Optimization
        if (i > target)
            break;

        // CHOOSE
        temp.push_back(i);

        // EXPLORE
        // i+1 because every number can be used only once
        combo(i + 1, k, target - i, temp, ans);

        // UNDO
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int target) {

    vector<vector<int>> ans;
    vector<int> temp;

    combo(1, k, target, temp, ans);

    return ans;
}

int main() {

    int k, target;
    cin >> k >> target;

    vector<vector<int>> ans = combinationSum3(k, target);

    for (auto combination : ans) {

        cout << "[ ";

        for (int x : combination)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}