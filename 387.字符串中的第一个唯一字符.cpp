#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

//用哈希表存储频数
//时间复杂度:O(n)，需要两次遍历字符串s。
//空间复杂度:O(|Σ|)，|Σ|表示字符集，因为s中只包含小写字母，所以|Σ|<=26。
class Solution {
public:
    int firstUniqChar(string s) {
        int length = s.size();
        unordered_map<char,int> m;
        for(char& c:s){
            ++m[c];
        }
        for(int i=0;i<length;i++){
            if(m[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

//用哈希表存储索引
//时间复杂度:O(n)，一次遍历字符串s，一次遍历哈希表。
//空间复杂度:O(|Σ|)，|Σ|表示字符集，s只包含小写字母，所以|Σ|<=26。
class Solution {
public:
    int firstUniqChar(string s){
        unordered_map<char, int> position;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(position.count(s[i])){
                position[s[i]] = -1;
            }else{
                position[s[i]] = i;
            }
        }
        int first = n;
        //pos<first 是为了找出最小索引
        for(auto [_, pos]: position){
            if(pos!=-1 && pos<first){
                first = pos;
            }
        }
        if(first == n) first = -1;
        return first;
    }
};

//队列
//队列具有[先进先出]的性质，很适合用来找第一个满足某条件的元素
//时间复杂度:O(n)
//空间复杂度:O(|Σ|)，其中|Σ|<=26.
class Solution {
public:
    int firstUniqChar(string s){
        unordered_map<char, int> position;
        //存储每一个字符，及其第一次出现的位置
        queue<pair<char, int>> q;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!position.count(s[i])){
                position[s[i]]=i;
                q.emplace(s[i],i);
            }else{
                position[s[i]]=-1;
                while(!q.empty() && position[q.front().first]==-1){
                    q.pop();
                }
            }
        }
        //如果队列为空，表示没有不重复值，返回-1；如果队列不为空，返回队列第一个元素的第二个值（即该元素的索引）
        return q.emplty() ? -1 : q.front().second;
    }
};
