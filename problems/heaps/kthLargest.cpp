// #include "header.h"
// using namespace std;
//
// class KthLargest {
// public:
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     int k;
//     KthLargest(int k_, vector<int>& nums) {
//         k = k_;
//         for (int num : nums) {
//             minHeap.push(num);
//         }
//         while (minHeap.size() > k) {
//             minHeap.pop();
//         }
//     }
//
//     int add(int val) {
//         minHeap.push(val);
//         while (minHeap.size() > k) {
//             minHeap.pop();
//         }
//         return minHeap.top();
//     }
// };
