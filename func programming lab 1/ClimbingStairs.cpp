#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int dp1 = 1;
        int dp2 = 2;

        for (int i = 3; i <= n; i++) {
            int current = dp1 + dp2;
            dp1 = dp2;
            dp2 = current;
        }

        return dp2;
    }
};

int main() {
    Solution solution;

    // Тестирование
    cout << "n=2: " << solution.climbStairs(2) << endl;  // Должно быть 2
    cout << "n=3: " << solution.climbStairs(3) << endl;  // Должно быть 3
    cout << "n=5: " << solution.climbStairs(5) << endl;  // Должно быть 8

    return 0;
}