#include <vector>
using namespace std;

class Solution{
public:
	bool isValidSudoku(vector<vector<char>>& board){
		//C++数组需要初始化赋值，否则C++会自动填入一些随机数值，影响后续判断
		int row[9]={0}; int col[9]={0}; int v[9]={0};
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]=='.'){
					continue;
				}
				//位移到当前数字存储为
				//num=[0,0,0,0,0,0,0,0,0]
				//遇到几，就在几号位上标1，即位移到几号位
				int num = 1<<(board[i][j]-'0');
				//(i/3,j/3)是board中的元素所在的3x3矩阵块在整个矩阵块中的索引
				//a=i/3, b=j/3, (a,b)表示小矩阵的索引，而a*3+b表示将9个小矩阵。flatten到一维数组上的索引
				int b = (i/3)*3+(j/3);
				//用 & (and) 进行判断
				if((row[i] & num) !=0 || (col[j] & num) !=0 || (v[b] & num) != 0){
					return false;
				}
				row[i] |= num;
				col[j] |= num;
				v[b] |= num;
			}
		}
		return true;
	}
};

class Solution{
public:
	bool isValidSudoku(vector<vector<char>>& board){
		int row[9][10] = {0};
		int col[9][10] = {0};
		int box[9][10] = {0};
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]=='.') continue;
				int curNumber = board[i][j]-'0';
				if(row[i][curNumber]) return false;
				if(col[j][curNumber]) return false;
				if(box[(i/3)*3+(j/3)][curNumber]) return false;

				row[i][curNumber] = 1;
				col[j][curNumber] = 1;
				box[(i/3)*3+(j/3)][curNumber] = 1;
			}
		}
		return true;
	}
};

class Solution{
public:
	//将9行，9列，9块都放在一个二维数组中。二维数组每行9个数，用于存放按行、列、块中的9个数据
	short int v[27][9] = {0};
	bool isValidSudoku(vector<vector<char>>& board){
		int x,y = '.'-'1';
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				x=board[i][j]-'1';
				if(x!=y){
					if(++v[i][x]>1) return 0;
					if(++v[9+j][x]>1) return 0;
					if(++v[18+i/3*3+j/3][x]>1) return 0;
				}
			}
		}
		return 1;
	}
};