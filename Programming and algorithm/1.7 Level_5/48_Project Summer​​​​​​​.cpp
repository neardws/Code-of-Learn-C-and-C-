// Project Summer游戏
// 小 I 和小 B 最近沉迷一款叫做《Project Summer》的游戏，小 I 扮演这个游戏中需要逃生的无辜者（Innocent)， 
// 小 B 扮演这个游戏中抓住无辜者，阻止其逃生的背叛者（Betrayer）。 
// 这个游戏的地图是一个 N 行 M 列 的矩形，每个格点表示一个位置。 '#' 表示地图中的障碍物，'.' 表示地图中的空地，
// 此外，地图中还有只有背叛者才能使用的传送门，用小写字母 'a' - 'z' 标记，它们在地图上成对出现。 
// 角色可以花费 1 单位的时间从一个格子走到上下左右相邻的 4 个空地中的另一个格子（不可以走出地图边界或者走到障碍物上）。 
// 此外，当小 B 扮演的背叛者走到一个传送门上时，他可以花费 1 单位的时间从当前格子传送到与当前格子相同字母的另一个传送门处
// （他也可以选择不传送，此时没有花费任何时间，待在原地不动）。
// 传送是双向的。比如，现在小 B 走到了标记为 'a' 的格子上，那么他可以选择花费一单位的时间传送到另一个标记为 'a' 的格子上，
// 也可以选择不传送，那么他就待在原地不动。
// 现在，小 I 被小 B 的陷阱困住了，无法移动。给出地图上小 B 和小 I 所在的格子（他们都站在空地上），
// 求小 B 最少需要花费多少时间才能走到小 I 所在的格子抓住他。如果小 I 无法抓住小 B，输出 -1
// 时间限制：1000
// 内存限制：65536
// 输入
// 第一行一个数字 T, 表示数据组数。 接下来描述 T 组数据，每组数据最开始是两个正整数 N, M 表示地图是 N 行 M 列的矩形。 
// 接下来 N 行，每行 M 个字符，表示地图。在地图上，用 '.' 表示空地，'#' 表示障碍物，'a'-'z' 表示传送门，'B' 表示小 B 的初始位置，
// 'I' 表示小 I 的初始位置。 对于每组数据，保证在地图上标记相同的传送门恰好出现两次。 T,N,M <= 100
// 输出
// T 行，第 i 行输出 'Case #i: t', 表示第 i 组数据的答案是 t. 小 B 最少需要 t 单位时间才能走到小 I 所在的格子。
// 如果小 I 无法抓住小 B，输出 -1
// 样例输入
// 3
// 5 5
// Bx#..
// #a.#.
// .....
// ##..#
// .x.aI
// 5 5
// BIa.a
// x#.x.
// .#.##
// .....
// #####
// 2 2
// B#
// #I
// 样例输出
// Case #1: 4
// Case #2: 1
// Case #3: -1
// 提示
// 对于第一组数据，假设行从上到下标号 1 到 5，列从左到右标号 1 到 5，
// 小 B 初始在 (1, 1)。小 B 的最优路线是： (1, 1) -> (1, 2) -> (2, 2) -> (5, 4) -> (5, 5)。
// 也就是走到标记为 x 的传送门时忽略传送门，走到标记为 a 的传送门时使用传送门。
// 对于第二组数据，小 B 直接花费 1 单位时间向右走一格就可以抓住小 I, 故输出 1。 
// 对于第三组数据，小 B 无法走到小 I 所在的位置上，故输出 -1。

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T, N, M;
int ii, jj;
int directs[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char a[100][100];
int visited[100][100];

struct Data
{
    int i, j, t;
    Data(int _i, int _j, int _t) : i(_i), j(_j), t(_t) {}
};

Data gogogo(const Data &d)
{
    char c = a[d.i][d.j];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (a[i][j] == c && !(d.i == i && d.j == j))
            {
                return Data(i, j, d.t + 1);
            }
        }
    }
    return d;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'B')
                {
                    ii = i;
                    jj = j;
                }
            }
        }
        queue<Data> q;
        memset(visited, -1, sizeof(visited));
        q.push(Data(ii, jj, 0));
        visited[ii][jj] = 0;
        bool flag = 0;
        while (!q.empty())
        {
            Data cur = q.front();
            if (a[cur.i][cur.j] == 'I')
            {
                flag = 1;
                break;
            }
            q.pop();
            int ni, nj, nt;
            for (int d = 0; d < 4; ++d)
            {
                ni = cur.i + directs[d][0];
                nj = cur.j + directs[d][1];
                nt = cur.t + 1;
                if (ni >= 0 && ni < N && nj < M && nj >= 0 && a[ni][nj] != '#' && (visited[ni][nj] == -1 || nt < visited[ni][nj]))
                {
                    visited[ni][nj] = nt;
                    q.push(Data(ni, nj, nt));
                }
            }
            if (a[cur.i][cur.j] <= 'z' && a[cur.i][cur.j] >= 'a')
            {
                Data nd = gogogo(cur);
                if (visited[nd.i][nd.j] == -1 || nd.t < visited[nd.i][nd.j])
                {
                    visited[nd.i][nd.j] = nd.t;
                    q.push(nd);
                }
            }
        }
        cout << "Case #" << t << ": " << ((flag) ? q.front().t : -1) << endl;
    }
    return 0;
}
