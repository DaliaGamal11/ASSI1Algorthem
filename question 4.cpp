#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
  int n = s.size();
  bool dp[n][n];
  memset(dp, 0, sizeof dp);
  int start = 0, end = 0, maxLen = 0;
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
    start = i;
    end = i;
    maxLen = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      start = i;
      end = i + 1;
      maxLen = 2;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if (dp[i + 1][j - 1] && s[i] == s[j]) {
        dp[i][j] = true;
        start = i;
        end = j;
        maxLen = len;
      }
    }
  }
  return s.substr(start, maxLen);
}

int main() {
  cout << "Enter a string:" << endl;
  string s;
  cin >> s;

  cout << "The longest palindromic substring is: " << longestPalindrome(s) << endl;
  return 0;
}
