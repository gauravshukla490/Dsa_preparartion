#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Function to check if the substring s[start...end] is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    // Backtracking function to generate all palindrome partitions
    void solve(int idx, vector<string> &temp, vector<vector<string>> &ans, string &s) {

        // Base case:
        // If we have reached the end of the string,
        // store the current partition.
        if (idx >= s.length()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring starting from idx
        for (int i = idx; i < s.length(); i++) {

            // Check if current substring is a palindrome
            if (isPalindrome(s, idx, i)) {

                // Choose
                temp.push_back(s.substr(idx, i - idx + 1));

                // Explore remaining string
                solve(i + 1, temp, ans, s);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, temp, ans, s);

        return ans;
    }
};

int main() {

    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<vector<string>> ans = obj.partition(s);

    cout << "\nPalindrome Partitions:\n";

    for (auto &partition : ans) {
        for (auto &str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}