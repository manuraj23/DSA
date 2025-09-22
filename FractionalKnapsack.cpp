#include <bits/stdc++.h>
using namespace std;

// Function for Fractional Knapsack
double fractionalKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<pair<double, int>> ratioIndex; // {ratio, index}

    for (int i = 0; i < n; i++) {
        double ratio = (double)val[i] / wt[i];
        ratioIndex.push_back({ratio, i});
    }

    // Sort by ratio in descending order
    sort(ratioIndex.rbegin(), ratioIndex.rend());

    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        int idx = ratioIndex[i].second;

        if (wt[idx] <= W) {
            // Take whole item
            W -= wt[idx];
            finalValue += val[idx];
        } else {
            // Take fraction
            finalValue += val[idx] * ((double)W / wt[idx]);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n = 3;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << "Fractional Knapsack Maximum Value: " 
         << fractionalKnapsack(W, wt, val, n) << endl;
    return 0;
}
