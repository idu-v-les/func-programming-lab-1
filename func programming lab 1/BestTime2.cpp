#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int n = prices.size();
        int maxProfit = 0;

        while (i < n - 1) {
            // Находим локальный минимум (день покупки)
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            int buy = prices[i];

            // Находим локальный максимум (день продажи)
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int sell = prices[i];

            maxProfit += sell - buy;
        }

        return maxProfit;
    }
};

int main5() {
    Solution solution;

    // Тест кейс 1
    vector<int> prices1 = { 7, 1, 5, 3, 6, 4 };
    cout << "Input: [7,1,5,3,6,4]" << endl;
    cout << "Output: " << solution.maxProfit(prices1) << endl; // Ожидается 7
    cout << endl;

    // Тест кейс 2
    vector<int> prices2 = { 1, 2, 3, 4, 5 };
    cout << "Input: [1,2,3,4,5]" << endl;
    cout << "Output: " << solution.maxProfit(prices2) << endl; // Ожидается 4
    cout << endl;

    // Тест кейс 3
    vector<int> prices3 = { 7, 6, 4, 3, 1 };
    cout << "Input: [7,6,4,3,1]" << endl;
    cout << "Output: " << solution.maxProfit(prices3) << endl; // Ожидается 0

    return 0;
}