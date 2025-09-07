#include "header.h"
using namespace std;

int kthLargestElement(vector<int> &nums, int k) {
    priority_queue<int, vector<int>> heap;
    for (int n : nums) {
        heap.push(n);
    }
    while (k > 1) {
        heap.pop();
        k--;
    }
    return heap.top();
}