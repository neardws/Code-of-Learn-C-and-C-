// 323:棋盘问题
// http://noi.openjudge.cn/ch0205/323/
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
// 要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
// 请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
// 输入
// 输入含有多组测试数据。
// 每组数据的第一行是两个正整数，n k，用一个空格隔开，
// 表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
// 当为-1 -1时表示输入结束。
// 随后的n行描述了棋盘的形状：每行有n个字符，
// 其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
// 输出
// 对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
// 样例输入
// 2 1
// #.
// .#
// 4 4
// ...#
// ..#.
// .#..
// #...
// -1 -1
// 样例输出
// 2
// 1
// 来源
// 蔡错@pku

#include<bits/stdc++.h>
using namespace std;
char map[10][10];
int n, k, ans, vis[10];
void dfs(int have, int index) {  // 还拥有的棋子，第几层
    if (have == 0)  // 棋子数为0，不再深搜
        ans++;
    for (int j = index; j < n; j++) // j 为地图第几行
        for (int i = 0; i < n; i++)    // i 为地图第几列
            if (map[j][i] == '#' && !vis[i]) {  // 棋盘区域，且未访问
                vis[i] = 1; 
                dfs(have - 1, j + 1);   // 棋子 -1，层数 +1 
                vis[i] = 0; //回溯
            }
}
int main() {
    while (cin >> n >> k && n != -1 && k != -1) {
    // 输入棋盘大小 和 旗子数量， -1，-1 表示输入结束
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];   // 输入地图信息
        ans = 0;   // 棋子摆放方案初始化为0
        dfs(k, 0);  // 还拥有的棋子数量 和 当前层数
        cout << ans << endl;    // 输出方案数
    }
    return 0;
}
