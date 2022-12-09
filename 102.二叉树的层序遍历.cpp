#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

// 层序遍历 迭代
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        vector<int> t1;
        vector<TreeNode*> t2;
        // 将头结点的
        t1.emplace_back(root->val);
        ans.emplace_back(t1);
        t1.clear();
        t2.emplace_back(root);
        while(!t2.empty()){
        	int currentLevelSize = t2.size();
        	for(int i=1;i<=currentLevelSize;++i){
	            root = t2.front();
	            t2.erase(t2.begin());
	            if(root->left != nullptr){
	                t2.emplace_back(root->left);
	                t1.emplace_back(root->left->val);
	            }
	            if(root->right != nullptr){
	                t2.emplace_back(root->right);
	                t1.emplace_back(root->right->val);
	            }
	        }
	        ans.emplace_back(t1);
	        t1.clear();
        }
        return ans;
    }
};

class Solution{
public:
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> ans;
		if(root==nullptr) return ans;
		// 用于存放结点
		queue<TreeNode*> q;
		vector<int> temp;
		q.emplace(root);
		while(!q.empty()){
			int currentLevelSize = q.size();
			for(int i=0;i<currentLevelSize;++i){
				root = q.front(); q.pop();
				temp.emplace_back(root->val);
				if(root->left!=nullptr) q.emplace(root->left);
				if(root->right!=nullptr) q.emplace(root->right);
			}
			ans.emplace_back(temp);
			temp.clear();
		}
		return ans;
	}
};

// BFS
class Solution{
public:
	vector<int> levelOrder(TreeNode* root){
		vector<int> ans;
		if(root==nullptr) return ans;
		queue<TreeNode*> q;
		q.emplace(root);
		while(!q.empty()){
			root = q.front(); q.pop();
			while(root!=nullptr){
				ans.emplace_back(root->val);
				if(root->left!=nullptr) q.emplace(root->left);
				if(root->right!=nullptr) q.emplace(root->right);
			}
		}
		return ans;
	}
};

// DFS 递归实现层序遍历的效果
class Solution{
public:
	void dfs(int index, TreeNode* root, vector<vector<int>> ans){
		if(ans.size()<index){
			ans.emplace_back(vector<int> ());
		}
		ans[index-1].emplace_back(root->val);
		if(root->left!=nullptr) dfs(index+1, root->left, ans);
		if(root->right!=nullptr) dfs(index+1, root->right, ans);
	}

	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> ans;
		if(root==nullptr) return ans;
		dfs(1, root, ans);
		return ans;
	}
};

class Solution{
public:
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> ans;
		if(!root) return ans;
		queue<TreeNode*> q;
		q.emplace(root);
		while(!q.empty()){
			int currentLevelSize = q.size();
			ans.emplace_back(vector<int> ());
			for(int i = 1;i<=currentLevelSize; ++i){
				TreeNode* node = q.front(); q.pop();
				ans.back().emplace_back(node->val);
				if(node->left) q.emplace(node->left);
				if(node->right) q.emplace(node->right);
			}
		}
		return ans;
	}
};

class Solution {
public:
    void level(TreeNode* root, int lev) {
        if(!root) return;
        if (lev >= ret.size()) {
            ret.emplace_back(vector<int>());
        }
        ret[lev].emplace_back(root -> val);
        level(root -> left, lev + 1);
        level(root -> right, lev + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> ret;
        level(root, 0);
        return ret;
    }
};