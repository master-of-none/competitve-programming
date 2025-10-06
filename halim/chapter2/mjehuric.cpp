#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& nums) {
    for (size_t k = 0; k < nums.size(); k++) {
        cout << nums[k] << " ";
    }
    cout << "\n";
}
int main() {
    vector<int> nums;
    int n;

    while (cin >> n) nums.push_back(n);

    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j + 1], nums[j]);
                printArray(nums);
            }
        }
    }
}