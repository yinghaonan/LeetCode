#include <vector>

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		int length = nums.size();
		for(int i=0;i<length-1;i++){
			for(int j=i+1;j<length;j++){
				if(nums[i] + nums[j] == target){
					return {i,j};
				}
			}
		}
        return {};
	}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};