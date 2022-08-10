// 1818:红与黑
// http://noi.openjudge.cn/ch0205/1818/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
// 你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

// 输入
// 包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。
// 在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
// 1）‘.’：黑色的瓷砖；
// 2）‘#’：红色的瓷砖；
// 3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
// 当在一行中读入的是两个零时，表示输入结束。
// 输出
// 对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
// 样例输入
// 6 9 
// ....#. 
// .....# 
// ...... 
// ...... 
// ...... 
// ...... 
// ...... 
// #@...# 
// .#..#. 
// 0 0
// 样例输出
// 45
// 来源
// 1979

#include<bits/stdc++.h>
using namespace std;
int sum;
char pic[25][25];
bool visit[25][25];
void dfs(int i, int j) {
	visit[i][j] = 1;//标记这个点走过
	//四个方向，满足条件（为‘.’ 且第一次经过）则进入dfs。
	if (pic[i][j + 1] == '.' && visit[i][j + 1] == 0) { sum++; dfs(i, j + 1); }
	if (pic[i][j - 1] == '.' && visit[i][j - 1] == 0) { sum++; dfs(i, j - 1); }
	if (pic[i + 1][j] == '.' && visit[i + 1][j] == 0) { sum++; dfs(i + 1, j); }
	if (pic[i - 1][j] == '.' && visit[i - 1][j] == 0) { sum++; dfs(i - 1, j); }
}
int main() {
	while (1) {
		int row, col; cin >> row >> col;
		if (row == 0 && col == 0) break;
		memset(pic, 0, sizeof(pic));
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= col; i++) {
			for (int j = 1; j <= row; j++) {
				cin >> pic[i][j];
			}
		}
		sum = 0;//全局变量的计数器
		for (int i = 1; i <= col; i++) {
			for (int j = 1; j <= row; j++) {
				if (pic[i][j] == '@') {//进入搜索
					sum++; dfs(i, j);
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}