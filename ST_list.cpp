/*
*  dp[i][j] 表示以i为起点，长度为（1<<j）的区间
*  ST表主要用途为   快速询问查找 （须符合 f(a,a)==a 如：min,max,lcm,gcd）   ST表为稀疏静态表
*  时间复杂度为 O(mlogn)
*  类似于线段树
*
*  若查找范围为[l,r]: 定义j  = (int)log2(r - l + 1);
*  则返回的dp范围为 max([l,j],[r-(1<<j)+1,j])
*
*  递推公式： O(nlogn + m)
*  dp[i][0]=arr[i] 长度为0代表本身
*  dp[i][j]=max(dp[i][j-1],dp[i+(1<<j-1)][j-1]) 分段取？值
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}//最大公约数

int lcd(int a, int b) {
    int tmp = gcd(a, b);
    return a * b / tmp;
}//最小公倍数

int main() {
    vector<int> arr = { 5, -2, 10, -1, 4 };
    const int n = 5;
    vector<vector<int>> dp(n, vector<int>((int)log2(n) + 1, 0));

    //构造ST表
    for (int i = 0; i < n; i++) dp[i][0] = arr[i];
    for (int j = 1; j <= log2(n); j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            dp[i][j] = gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);//改变取值方式
        }
    }

    cout << "-----原数组-----" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";//输出原数组arr

    cout << endl << "-----ST  表-----" << endl;

    //输出ST表
    for (int j = 0; j <= log2(n); j++) {
        for (int i = 0; i < n; i++) {
            printf("%3d ", dp[i][j]);
        }
        cout << endl;
    }

    cout << "-----输入查询区间-----" << endl;
    int l, r;
    while (cin >> l >> r) {
        int j = (int)log2(r - l + 1);
        cout << gcd(dp[l][j], dp[r - (1 << j) + 1][j]) << endl;//改变取值方式
    }
    return 0;
}
