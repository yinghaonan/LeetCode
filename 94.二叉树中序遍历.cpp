#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// 递归
class Solution{
public:
	void introOrder(TreeNode* root, vector<int>& ans){
		if(root==nullptr) return;
		introOrder(root->left, ans);
		ans.emplace_back(root->ans);
		introOrder(root->right, ans);
	}
	vector<int> inorderTravelsal(TreeNode* root){
		vector<int> ans;
		introOrder(root, ans);
		return ans;
	}
};