// 7218:献给阿尔吉侬的花束
// http://noi.openjudge.cn/ch0205/7218/
// 总时间限制: 100ms 内存限制: 65536kB
// 描述
// 阿尔吉侬是一只聪明又慵懒的小白鼠，它最擅长的就是走各种各样的迷宫。
// 今天它要挑战一个非常大的迷宫，研究员们为了鼓励阿尔吉侬尽快到达终点，就在终点放了一块阿尔吉侬最喜欢的奶酪。
// 现在研究员们想知道，如果阿尔吉侬足够聪明，它最少需要多少时间就能吃到奶酪。

// 迷宫用一个R×C的字符矩阵来表示。字符S表示阿尔吉侬所在的位置，字符E表示奶酪所在的位置，字符#表示墙壁，字符.表示可以通行。
// 阿尔吉侬在1个单位时间内可以从当前的位置走到它上下左右四个方向上的任意一个位置，但不能走出地图边界。

// 输入
// 第一行是一个正整数T（1 <= T <= 10），表示一共有T组数据。
// 每一组数据的第一行包含了两个用空格分开的正整数R和C（2 <= R, C <= 200），表示地图是一个R×C的矩阵。
// 接下来的R行描述了地图的具体内容，每一行包含了C个字符。字符含义如题目描述中所述。保证有且仅有一个S和E。
// 输出
// 对于每一组数据，输出阿尔吉侬吃到奶酪的最少单位时间。若阿尔吉侬无法吃到奶酪，则输出“oop!”（只输出引号里面的内容，不输出引号）。
// 每组数据的输出结果占一行。
// 样例输入
// 3
// 3 4
// .S..
// ###.
// ..E.
// 3 4
// .S..
// .E..
// ....
// 3 4
// .S..
// ####
// ..E.
// 样例输出
// 5
// 1
// oop!

#include<bits/stdc++.h>
using namespace std;
int R,C,T,BeginX,BeginY,EndX,EndY;
char Map[205][205];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int visited[205][205];
struct node
{
    int x,y,step;
    node(int xx=0,int yy=0,int ss=0):x(xx),y(yy),step(ss){}
};
queue <node> q;
void Bfs()
{
    q.push( node( BeginX, BeginY, 0) );
    visited[BeginX][BeginY] = 1;
    while( !q.empty() )
    {
        node now = q.front();
        q.pop();
        int NowX = now.x; int NowY = now.y; int NowStep = now.step;
        if( NowX == EndX && NowY == EndY )
        {
            cout << NowStep << endl;
            return;
        }
        for( int i = 0; i < 4; i++ )
        {
            int NextX = NowX + dx[i]; int NextY = NowY + dy[i];
            if( !visited[NextX][NextY] && Map[NextX][NextY] != '#' )
                {
                    q.push( node( NextX, NextY, NowStep + 1));
                    visited[NextX][NextY] = 1;
                }
        }
    }
    cout << "oop!" << endl;
}
int main()
{
    cin >> T;
    while( T-- )
    {
        cin >> R >> C;
        memset(Map, 0, sizeof(Map));
        memset(visited, 0, sizeof(visited));
        for( int i = 1; i <= R; i++ )
            for( int j = 1; j <= C; j++ )
            {
                cin >> Map[i][j];
                if( Map[i][j] == 'S' )
                {
                    BeginX = i;
                    BeginY = j;
                }
                if( Map[i][j] == 'E' )
                {
                    EndX = i;
                    EndY = j;
                }
            }
        for( int i = 0; i <= R+1; i++ )
            for( int j = 0; j <= C+1; j++ )
                if( i==0 || j==0 || i==R+1 || j==C+1 )
                    Map[i][j] = '#';
        while( !q.empty() )
            q.pop();
        Bfs();
    }
    return 0;
}
