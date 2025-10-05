// #include "header.h"
// using namespace std;
//
// int lastStoneWeight(vector<int> stones) {
//     priority_queue<int> heap;
//
//     for (int s : stones) {
//         heap.push(s);
//     }
//
//     while (heap.size() > 1) {
//         int x = heap.top();
//         heap.pop();
//         int y = heap.top();
//         heap.pop();
//
//         int temp = y - x;
//         heap.push(temp);
//     }
//     return !heap.empty() ? heap.top() : 0;