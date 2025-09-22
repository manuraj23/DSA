#include <bits/stdc++.h>
using namespace std;

// Function to generate the next palindrome
string nextPalindrome(string num) {
    int n = num.size();
    string result = num;

    // Mirror left half to right half
    for (int i = 0; i < n / 2; i++) {
        result[n - 1 - i] = result[i];
    }

    // If mirrored number is greater, return it
    if (result > num) return result;

    // Otherwise, increment the middle
    int carry = 1;
    int mid = (n - 1) / 2;

    while (mid >= 0 && carry) {
        int digit = (result[mid] - '0') + carry;
        carry = digit / 10;
        digit %= 10;
        result[mid] = digit + '0';
        result[n - 1 - mid] = result[mid]; // keep palindrome property
        mid--;
    }

    // If carry still remains (e.g., 999 -> 1001)
    if (carry) {
        result = "1";
        for (int i = 1; i < n; i++) result += "0";
        result += "1";
    }

    return result;
}

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Next palindrome is: " << nextPalindrome(num) << endl;
    return 0;
}
