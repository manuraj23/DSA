#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
        int n=nums.size();
        if (n<2)return nums[0];
        int rob=0;
        int noRob=0;
        for(int i=0;i<n;i++){
            int newRob=noRob+nums[i];
            int newNoRob=max(noRob,rob);
            rob=newRob;
            noRob=newNoRob;
        }
        return max(rob,noRob);
    }