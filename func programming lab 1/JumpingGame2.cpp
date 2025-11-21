#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;  // текущая граница достижимости
        int farthest = 0;    // самая дальняя точка, которую можем достичь

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // Когда достигаем конца текущего прыжка
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // Если можем уже достичь конца
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};

int main1() {
    Solution solution;

    // Тест кейс 1
    vector<int> nums1 = { 2, 3, 1, 1, 4 };
    cout << "Input: [2,3,1,1,4]" << endl;
    cout << "Output: " << solution.jump(nums1) << endl; // Ожидается 2
    cout << endl;

    // Тест кейс 2
    vector<int> nums2 = { 2, 3, 0, 1, 4 };
    cout << "Input: [2,3,0,1,4]" << endl;
    cout << "Output: " << solution.jump(nums2) << endl; // Ожидается 2

    return 0;
}