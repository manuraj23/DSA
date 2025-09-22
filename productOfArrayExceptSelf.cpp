#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n),left(n),right(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=0;i<n-1;i++){
            left[i+1]=left[i]*nums[i];
            right[n-i-2]=right[n-i-1]*nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;

    }
int main(){
    return 0;
}