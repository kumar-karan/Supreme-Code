#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10000007;

int countValidPasswords(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Initialize base cases
    for (int j = 0; j <= k; j++) {
        dp[0][j] = 1;
    }

    // Fill in the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[i][j] = 26 * dp[i - 1][j];
            } else {
                dp[i][j] = (25 * dp[i - 1][j - 1] + 26 * dp[i - 1][j]) % MOD;
            }
        }
    }

    // The result is the total count of valid passwords of length n
    // with exactly k consecutive equal characters
    int result = dp[n][k];

    return result;
}

int main() {
    int n, k;
    cout << "Enter the length of the password (n): ";
    cin >> n;
    cout << "Enter the maximum number of consecutive equal characters (k): ";
    cin >> k;

    int result = countValidPasswords(n, k);
    cout << "Number of valid passwords: " << result << endl;

    return 0;
}
