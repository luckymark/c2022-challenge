#include"wuziqi.h"
//depth表示层数  color表示AI的颜色 a是下界 b是上界 
int min_max_dfs(int depth, int player,int color,  int a, int b){
	//player=1表示接下来是对手下棋来进入下一层 player=-1表示自己下棋来进入下一层 
	int key; //返回值
	int v;
	
	if (depth == DEPTH + 1){ 
		return Settled_Situation(color);
	} //到到最深层时 即叶子节点时 估值


	//对于min层，任意子节点的值都比父节点的上界大，则父节点直接返回其上界；
	if (player==1) key = b; //即当前节点的父节点是Max层 返回值初始化为父节点的上界 即已知的最小的上界值
	else key = a;    //即当前节点的父节点是min层 返回值初始化为父节点的下界 即已知的最大的下界值

	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (board[i][j] == 0 && vision[i][j] != 0){
				if (player == -1){
					//父节点是min层 当前层是Max层 下一层是min层（叶子节点）时的情况
					//最终目的：试图更新父节点的上界值
					//从下一层中的返回值更新自己的下界值，即找到更大的下界值
					//并最终把自己的下界值作为返回值返回父节点
					//每一个子节点找完之后尝试更新自己的下界值 并以这个新的上下限区间作为下一个子节点的初始区间
					board[i][j] = color;
					Neighbor_Location(i, j, 1);
					v = min_max_dfs(depth + 1, 1,color, a, b); //dfs 如果到了最低层则返回估值
					if (v > a){//如果当前估值大于当前层取值的下界a 更新下界a的值 即实现min_Max基本功能
						a = v;
						if (a >= b){//下界大于上界时 显然出错 该分支树作废 停止接下来的遍历（子节点） 向第上一层即min层返回一个无用的极大正数 即减枝
							board[i][j] = 0;
							Neighbor_Location(i, j, -1);
							return 1e9;
						}
						key = v; //返回更新的下界值 亦是所有子节点里最大的下界值
					}
					board[i][j] = 0;
					Neighbor_Location(i, j, -1);
				}
				else
				{
					//父节点是Max层 当前层是min层 下一层是Max层时的情况
					//最终目的：试图更新父节点的下界值
					//从下一层中的返回值更新自己的上界值，即找到更小的上界值
					//并最终把自己的上界值作为返回值返回父节点
					board[i][j] = -color;
					Neighbor_Location(i, j, 1);//dfs 如果到了最低层则返回估值
					v = min_max_dfs(depth + 1, -1,color, a, b);
					if (v < b){//如果当前估值小于当前层取值的上界b 更新上界b的值 即实现min_Max基本功能
						b = v;
						if (a >= b){//减枝 向第上一层即Max层返回一个无用的极大负数
							board[i][j] = 0;
							Neighbor_Location(i, j, -1);
							return -1e9;
						}
						key = v; //返回更新的上界值 亦是所有子节点里最小的上界值
					}
					board[i][j] = 0;
					Neighbor_Location(i, j, -1);
				}
			}
		}
	}
	return key; //返回这个节点最终的估值
	//父节点是Max层 返回值为已知的最小的上界值
	//父节点是min层 返回值为已知的最大的下界值
}

