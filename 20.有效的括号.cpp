#include <map>
#include <vector>
using namespace std;

//使用vector
class Solution{
public:
	bool isValid(string s){
		int n = s.size();
		if(n%2) return false;
		unordered_map<char, char> pairs{
			{')','('},
			{']','['},
			{'}','{'}
		};
		vector<char> vec;
		for(char& ch: s){
			if(pairs.count(ch)){
				if(vec.empty() || vec.back()!=pairs[ch]){
					return false;
				}
			}else{
				vec.pop_back();
			}
		}
		return vec.empty();
	}
};

//使用stack
class Solution{
public:
	bool isValid(string s){
		int n = s.size();
		if(n%2) return false;
		unordered_map<char, char> pairs{
			{')','('},
			{']','['},
			{'}','{'}
		};
		stack<char> stk;
		for(char& ch: s){
			if(pairs.count(ch)){
				if(stk.empty() || stk.top() != pairs[ch]) return false;
				stk.pop();
			}else{
				stk.push(ch);
			}
		}
		return stk.empty();
	}
};

//左括号作为键
class Solution{
public:
	bool isValid(string s){
		int n = s.size();
		if(n%2) return false;
		unordered_map<char, char> pairs{
			{'(',')'},
			{'[',']'},
			{'{','}'}
		};
		stack<char> stk;
		for(char& ch: s){
			if(pairs.count(ch)){
				stk.push(ch);
			}else{
				if(stk.empty() || pairs[stk.top()] != ch) return false;
				stk.pop();
			}
		}
		return stk.empty();
	}
};