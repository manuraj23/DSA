#include <bits/stdc++.h>
using namespace std;
int MaxProfit(vector<int> &prices){
    int n=prices.size();
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return profit;
}
    
int main(){
    return 0;
}