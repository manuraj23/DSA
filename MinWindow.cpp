#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }

        int l = 0, r = 0, subl = 0, subr = 0;
        int formed = 0, total = map.size();
        int lenans = INT_MAX;

        while (r < s.size()) {
            char c = s[r];
            if (map.find(c) != map.end()) {
                map[c]--;
                if (map[c] == 0) formed++;
            }

            while (l <= r && formed == total) {
                int curlen = r - l + 1;
                if (curlen < lenans) {
                    lenans = curlen;
                    subl = l;
                    subr = r + 1;
                }
                char leftc = s[l];
                if (map.find(leftc) != map.end()) {
                    if (map[leftc] == 0) formed--;
                    map[leftc]++;
                }
                l++;
            }
            r++;
        }

        return (lenans == INT_MAX) ? "" : s.substr(subl, subr - subl);
    }
int main(){
    return 0;
}