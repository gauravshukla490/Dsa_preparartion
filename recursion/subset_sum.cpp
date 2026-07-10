#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int idx, int sum) {

    // Target achieved
    if (sum == 0)
        return true;

    // No elements left
    if (idx == arr.size())
        return false;

    // Pick
    if (solve(arr, idx + 1, sum - arr[idx]))
        return true;

    // Not Pick
    return solve(arr, idx + 1, sum);
}

bool isSubsetSum(vector<int>& arr, int sum) {
    return solve(arr, 0, sum);
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum))
        cout << "Subset Exists\n";
    else
        cout << "Subset Doesn't Exist\n";

    return 0;
}