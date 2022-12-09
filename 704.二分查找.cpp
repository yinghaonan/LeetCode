// 线性查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i=0;i<size;++i){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};

// 二分查找
class Solution{
public:
    int search(vector<int>& nums, int target){
        int n = nums.size()/2;
        if(nums[n]<target){
            for(int i=n;i<nums.size();i++){
                if(nums[i]==target){
                    return i;
                }
            }
        }else if(nums[n]>target){
            for(int i=0;i<n;i++){
                if(nums[i]==target){
                    return i;
                }
            }
        }else{
            return n;
        }
        return -1;
    }
};

// 二分查找——官方解法
class Solution{
public:
    int search(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            // int mid = (right - left)/2 + left;
            // 位运算代替除法，提升性能
            int mid = ((right - left) >> 1) + left;
            int num = nums[mid];
            if(num == target){
                return mid;
            }else if(num > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};

// 二分查找某个数的左边界
int search(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size()-1;
    while(left<right){
        int mid = left+((right-left)>>1);
        if(nums[mid]<target){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return nums[left] == target ? left : -1
}

// 二分查找右边界
int search(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left < right){
        int mid = left + ((right - left)>>1) + 1;
        if(nums[mid] <= target){
            left = mid;
        }else{
            right = mid - 1;
        }
    }
    return nums[right] == target ? right : -1;
}

// 二分查找左右边界
vector<int> searchRange(vector<int>& nums, int target){
    // 存储左右边界，ans[0]: 左边界，ans[1]: 有边界
    vector<int> ans{-1,-1};
    if(nums == nullptr || nums.size() == 0) return ans;
    //寻找左边界
    int left = 0;
    int right = nums.size() - 1;
    while(left < right) {
        int mid = ((left+right)>>1);
        if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    ans[0] = nums[left] == target ? left : -1;

    // 如果左边界是最后一个数的下标或者该数没有重复只存在一个，那么可以直接令右边界=左边界
    if(ans[0] != -1){
        if(left == nums.size()-1 || nums[left+1] != target){
            ans[1] = left;
        } else {
            //寻找右边界
            right = nums.size()-1;
            while(left<right){
                int mid = ((left+right)>>1) + 1;
                if(nums[mid] > target){
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            ans[1] = nums[right] == target ? right : -1;
        }
    }
    return ans;
}

// 二分查找极值点
class Solution{
public:
    int search(vector<int>&nums){
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left+((right-left)>>1);
            // nums[mid]是极大值点
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                return mid;
            }else if(nums[mid] > nums[mid+1]){
                // 极值点在mid左边
                right = mid - 1;
            }else{
                // 极值点在mid右边
                left = mid + 1;
            }
        }
    }
    return -1;
};