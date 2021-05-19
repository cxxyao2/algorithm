// 一个n*n棋盘，可以放n个皇后，互相不再攻击位置，即不在互相的上下左右及对角线上
#include<iostream>  
#include <cstring>

#include <vector>
using namespace std;

class Solution {
  public:
  vector<vector<string> > solveNQueens(int n) {
  vector<vector<string> > solve;
  vector<vector<int> > attack;
  vector<string> queen;



   for(int i=0;i<n;i++){
     attack.push_back((std::vector<int>()));
    for(int j=0;j<n;j++) {
        attack[i].push_back(0);
      } 
      queen.push_back("");
      queen[i].append(n,'.'); 
    } 

    backtrack(0,n,queen,attack,solve);
    return solve;
  }


  void put_queen(int x, int y, vector<vector<int> > &attack) {

    static const int dx[] = {-1,1,0,0,0,-1,-1,1,1} ;
    static const int dy[] = {0,0,-1,1,-1,1,-1,1};
    attack[x][y]=1;

   // 通过两层循环，把该皇后可能攻击到的位置设置为1
   for(int i=1;i <attack.size(); i++){
     for(int j=0;j<8;j++) {
       int nx = x + i*dx[j]; 
       int ny = y + i*dy[j];

       if(nx >0 && nx <attack.size() && ny >=0 && ny <= attack.size()) {
         attack[nx][ny] = 1;
       }
     }

   }

  }
  // 回溯法求解N皇后的递归函数
  // K表示当前处理的行
  // n表示N皇后问题
  // queen 存储皇后的位置, .Q..之类
  // attack标记皇后的攻击位置
  // solve存储N皇后的全部解法
  void backtrack(int k, int n, vector<string> &queen, vector<vector<int> > &attack,
  vector<vector<string> > &solve) {
  
  if( k == n ) {   // 找到解答
    solve.push_back(queen);
    return;
  }

  for(int i=0; i<n; i++) {
    if(attack[k][i] == 0) { //判断是否可以放皇后，为0就是可以，为1就是不可以
      vector<vector<int> > tmp = attack; // 备份attack数组
      queen[k][i] = 'Q';
      put_queen(k,i,attack);
      backtrack(k+1, n, queen, attack, solve);// 递归试探k+1行的皇后位置
      attack = tmp; // 恢复attack数组
      queen[k][i]='.'; // 恢复queen数组
    }
  }

  }
};

int main() {
  vector<vector<string> > result;
  Solution solution;
  result = solution.solveNQueens(3);

   for(int i=0; i<result.size(); i++) {
    printf("i=%d\n", i);
    for(int j=0;i<result[i].size();j++) {
      printf("%s\n", result[i][j].c_str());
    }
    printf("\n");
  } 
  return 0;
}