//官方答案一：暴力法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, prices[j]-prices[i]);
            }
        }
        return ans;
    }
};


//官方答案二：记录minprice
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};