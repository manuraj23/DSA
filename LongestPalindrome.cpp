#include<iostream>
using namespace std;
string longestPalindrome(string s) {
        int n=s.size();
        string ans=s.substr(0,1);
        for(int i=1;i<n;i++){
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > ans.size()) {
                    ans = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > ans.size()) {
                    ans = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
        }
        return ans;
    }
int main(){
    cout<<"Hello World";
    return 0;
}
