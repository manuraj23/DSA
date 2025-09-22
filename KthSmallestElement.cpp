#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> maxHeap(arr.begin(), arr.end());
        if (k > arr.size()) return -1;
        for(int i=0;i<arr.size()-k;i++){
            maxHeap.pop();
        }
        return maxHeap.top();
    }
int main(){
    return 0;
}