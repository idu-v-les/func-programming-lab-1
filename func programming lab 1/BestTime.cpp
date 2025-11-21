#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Обновляем минимальную цену
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Рассчитываем потенциальную прибыль и обновляем максимум
            else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};

int main4() {
    Solution solution;

    // Тест кейс 1
    vector<int> prices1 = { 7, 1, 5, 3, 6, 4 };
    cout << "Input: [7,1,5,3,6,4]" << endl;
    cout << "Output: " << solution.maxProfit(prices1) << endl; // Ожидается 5
    cout << endl;

    // Тест кейс 2
    vector<int> prices2 = { 7, 6, 4, 3, 1 };
    cout << "Input: [7,6,4,3,1]" << endl;
    cout << "Output: " << solution.maxProfit(prices2) << endl; // Ожидается 0

    return 0;
}