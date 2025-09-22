#include <bits/stdc++.h>
using namespace std;
int ContainsDuplicates(vector<int> &nums){
    set<int>temp(nums.begin(),nums.end());
    return temp.size()!=nums.size();
}
    
int main(){
    return 0;
}