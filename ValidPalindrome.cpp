#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            if (isalnum(s[i])) {                
            temp += tolower(s[i]);        
        }
        }
        int l=0,r=temp.size()-1;
        while(l<r){
            if(temp[l++]!=temp[r--])return false;
        }
        return true;
}
