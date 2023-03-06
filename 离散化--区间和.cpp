#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;// n:下标和值的个数，m:查询区间的个数
int a[N], s[N];// a:每个下标 抽象代表 离散化后的下标，存储 增加的数值；s:前缀和

vector<int> alls;// 保存题目给的 所有 下标，相当于辅助 存储 离散化下标，再通过查找离散化下标方式找到数值下标，最后映射到a数组上
vector<PII> add;// 保存题目给的 非查询 下标和值
vector<PII> query;// 保存题目给的 查询区间

int find(int x)// 二分查找 返回 x在数组中 出现的 第一次下标
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});// 记录下标和数值

        alls.push_back(x);// 记录下标
    }

    for (int i = 0; i < m; i ++ )
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});// 记录查询区间

        // 记录下标
        alls.push_back(l);
        alls.push_back(r);
    }

    
    sort(alls.begin(), alls.end());// 排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());// 去重

    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first);// 通过二分 将原先存储的下标 转化为 离散化下标
        a[x] += item.second;// 离散化下标 增加数值
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];

    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);// 将 查询区间原下标 转化为 离散化下标
        cout << s[r] - s[l - 1] << endl; 
    }

    return 0;
}