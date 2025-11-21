#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 1; i <= rowIndex; i++) {
            // Обновляем справа налево чтобы не перезаписывать значения
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};

int main3() {
    Solution solution;

    // Тест кейс 1
    int rowIndex1 = 3;
    vector<int> result1 = solution.getRow(rowIndex1);
    cout << "Input: rowIndex = " << rowIndex1 << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl; // Ожидается [1,3,3,1]
    cout << endl;

    // Тест кейс 2
    int rowIndex2 = 0;
    vector<int> result2 = solution.getRow(rowIndex2);
    cout << "Input: rowIndex = " << rowIndex2 << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl; // Ожидается [1]
    cout << endl;

    // Тест кейс 3
    int rowIndex3 = 1;
    vector<int> result3 = solution.getRow(rowIndex3);
    cout << "Input: rowIndex = " << rowIndex3 << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl; // Ожидается [1,1]

    return 0;
}