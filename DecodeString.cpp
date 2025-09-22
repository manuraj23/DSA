#include <bits/stdc++.h>
using namespace std;
string decodeString(string s) {
        stack<string> stringStack;
        stack<int> intStack;
        string num = "";

        for (char c : s) {
            if (isdigit(c)) {
                num += c; // handle multi-digit numbers
            } 
            else if (c == '[') {
                intStack.push(stoi(num));
                num = "";
                stringStack.push("["); // push as string
            } 
            else if (c == ']') {
                string res = "";
                while (stringStack.top() != "[") {
                    res = stringStack.top() + res;
                    stringStack.pop();
                }
                stringStack.pop(); // remove '['
                int a = intStack.top();
                intStack.pop();

                string temp = "";
                for (int i = 0; i < a; i++) temp += res;
                stringStack.push(temp);
            } 
            else {
                stringStack.push(string(1, c)); // convert char to string
            }
        }
        // Combine everything left in the stack
        string ans = "";
        while (!stringStack.empty()) {
            ans = stringStack.top() + ans;
            stringStack.pop();
        }
        return ans;
    }
