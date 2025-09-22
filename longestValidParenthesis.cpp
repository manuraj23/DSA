#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top());
                } else {
                    st.push(i);
                }
            }
        }

        return maxLen;
    }