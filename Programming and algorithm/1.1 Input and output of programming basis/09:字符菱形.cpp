/****************************************************
09:字符菱形

总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符，用它构造一个对角线长5个字符，倾斜放置的菱形。

输入
输入只有一行， 包含一个字符。
输出
该字符构成的菱形。
样例输入
*
样例输出
  *
 ***
*****
 ***
  *
来源
http://noi.openjudge.cn/ch0101/09/
*****************************************************/

#include<bits/stdc++.h>
using namespace std;
int main(){
    char a;
    cin>>a;
    cout<<"  "<<a<<endl;
    cout<<" "<<a<<a<<a<<endl;
    cout<<a<<a<<a<<a<<a<<endl;
    cout<<" "<<a<<a<<a<<endl;
    cout<<"  "<<a<<endl;
    return 0;
}
