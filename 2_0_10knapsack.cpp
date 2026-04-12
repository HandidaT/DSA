#include <iostream>
#include <vector>
using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, 
                                        vector<vector<int>> &memo) {

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // Check if we have previously calculated the same subproblem
    if(memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;

    // Pick nth item if it does not exceed the capacity of knapsack
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);
    
    // Don't pick the nth item
    int notPick = knapsackRec(W, val, wt, n - 1, memo);
    
    // Store the result in memo[n][W] and return it
    return memo[n][W] = max(pick, notPick);
}

int knapsackMemoization(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    
    // Memoization table to store the results
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    
    return knapsackRec(W, val, wt, n, memo);
}

int knapsackTabulation(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            
            // If there is no item or the knapsack's capacity is 0
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                int pick = 0;
                
                // Pick ith item if it does not exceed the capacity of knapsack
                if(wt[i - 1] <= j)
                    pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    
                // Don't pick the ith item
                int notPick = dp[i - 1][j];
                
                dp[i][j] = max(pick, notPick);
            }
        }
    }
    return dp[n][W];
}

//Driver Code Ends
int knapsackTabulationSpaceOptimized(int W, vector<int> &val, vector<int> &wt) {

    // Initializing dp vector
    vector<int> dp(W + 1, 0);

    // Taking first i elements
    for (int i = 1; i <= wt.size(); i++) {
        
        // Starting from back, so that we also have data of
        // previous computation of i-1 items
        for (int j = W; j >= wt[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int main() {
//Driver Code Starts
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsackMemoization(W, val, wt) << endl;
    cout << knapsackTabulation(W, val, wt) << endl;
    cout << knapsackTabulationSpaceOptimized(W, val, wt) << endl;
    return 0;
}