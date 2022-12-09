//给你二叉树的根节点root，返回它节点值的前序遍历

//Definition for a binary tree node.
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), 
	left(left), right(right){}
};

//DFS 递归
class Solution {
public:
	void preorder(TreeNode* root, vector<int>& ans){
		if(root==nullptr){
			return;
		}
		ans.emplace_back(root->val);
		preorder(root->left, ans);
		preorder(root->right, ans);
	}

	vector<int> preorderTravelsal(TreeNode* root){
		vector<int> ans;
		preorder(root, ans);
		return ans;
	}
}

//DFS 迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};