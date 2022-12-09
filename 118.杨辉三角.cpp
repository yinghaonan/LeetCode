#include <vector>
using namespace std;

//官方解法：数学
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};

//巧妙的解法
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> a, b;
        while(numRows--) {
            a = b;
            for(int i=1; i<a.size(); i++)
                b[i] = a[i-1]+a[i];
            b.push_back(1);
            ans.push_back(b);
        }
        return ans;
    }
};