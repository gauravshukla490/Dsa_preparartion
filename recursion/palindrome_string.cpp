#include <bits/stdc++.h>
using namespace std;

bool check(int left, int right, char s[]) {
    // Base Case
    if (left >= right)
        return true;

    // Characters don't match
    if (s[left] != s[right])
        return false;

    // Recursive Call
    return check(left + 1, right - 1, s);
}

bool isPalindrome(char s[]) {
    int n = strlen(s);
    return check(0, n - 1, s);
}

int main() {
    char s[] = "madam";

    if (isPalindrome(s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}