#include <vector>
using namespace std;

//官方解法，和我的思路一样
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //m记录行，n记录列
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    //表示i行和j列是有0的
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //i行和j列只要有一个有0
                //就让那一行和那一列都变为0
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};