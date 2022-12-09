#include <vector>
#include <map>
using namespace std;

//官方答案1：哈希表
/*
时间复杂度：O(m+n)，需要遍历两个数组（时间复杂度O(m+n)）对哈希表进行操作，
哈希表操作的时间复杂度是O(1)，因此总时间复杂度是O(1)*O(m+n)=O(m+n)

空间复杂度：O(min(m,n))，对较短的数组进行哈希表的操作，
哈希表的大小不会超过较短数组的长度，为返回值创建一个数组intersection。
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //非常巧妙，调用自身。
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        //统计nums1中每个数字出现的次数
        unordered_map <int, int> m;
        for (int num : nums1) {
            ++m[num];
        }
        vector<int> intersection;
        for (int num : nums2) {
            if (m.count(num)) {
                intersection.push_back(num);
                --m[num];
                if (m[num] == 0) {
                    m.erase(num);
                }
            }
        }
        return intersection;
    }
};

//官方答案2：双指针
//时间复杂度：O(mlogm+nlogn)
//空间复杂度：O(min(m,n))
class Solution{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 =0, index2=0;
        vector<int> intersection;
        while(index1<length1 || index2<length2){
            if(nums1[index1]<nums2[index2]){
                index1++;
            }else if(nums2[index2]<nums1[index1]){
                index2++;
            }else{
                intersection.push_back(nums[index1]);
                index1++;
                index2++;
            }
        }
        return intersection;
    }
};
/*
结语：如果nums2的元素存储在磁盘上，磁盘内存是有限的，
并且你不能一次加载所有的元素到内存中。那么无法高效地对nums2进行排序，
因此推荐释放方法一而不是方法二。在方法一种，nums2只关系到查询操作，
因此每次读取nums2的一部分数据，并进行处理即可。
*.