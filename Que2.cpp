#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCoins(vector<int> coins, int change) {
    vector<int> dp(change + 1, change + 1);
    dp[0] = 0;

    for (int i = 1; i <= change; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[change];
}

int main() {
    vector<int> britishPounds = {1, 2, 5, 10, 20, 50};
    vector<int> usDollars = {1, 5, 10, 25};
    vector<int> norwegianKrone = {1, 5, 10, 20};

    int change = 43;
    cout << "Minimum number of coins required to make change for " << change << " cents: " << minCoins(britishPounds, change) << endl;

    return 0;
}