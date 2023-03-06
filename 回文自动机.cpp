class Pam{
    #define N 100010
public:
    int len[N]; // 回文串的长度
    int fa[N]; // 回文串的最长回文后缀代表的节点
    int tran[N][26]; // 转移函数，自动机必备的东西，回文串的两端加上某一字符之后的回文串
    int num[N]; // 回文串的回文后缀个数
    int L[N]; // 原字符串以 i 结尾的回文后缀长度
    int size[N]; // 回文串的数量
    int tot; // 节点数
    int last; // 上次插入操作后的最长回文后缀长度

    /*
    维护了上面的这些东西。回文自动机可以求下面的东西：
    1.求前缀字符串中的本质不同的回文串种类（就是节点数）
    2.求每个本质不同回文串的个数（size数组）
    3.以下标i为结尾的回文串长度（L数组）
    */

    void init(){
        len[0] = 0;
        fa[0] = 1;
        len[1] = -1;
        fa[1] = 0;
        tot = 1; 
        last = 0; 
        memset(tran[1], 0, sizeof tran[1]);
        memset(tran[0], 0, sizeof tran[0]);
    }

    int new_node(int x){
        int now = ++tot;
        memset(tran[tot], 0, sizeof tran[tot]);
        len[now] = x;
        return now;
    }

    // c代表当前插入的字符， n代表当前插入字符在原串中的下标
    void ins(int c, int n){
        int u = last;
        while(s[n - len[u] - 1] != s[n]) u = fa[u]; // 寻找以当前位置为结尾的最长回文串

        // 判断以当前位置为结尾的回文串是否已经出现过，如果出现过直接维护一些值结束
        // 没出现过
        if(tran[u][c] == 0){
            /*
            如果没有出现过，我们新建一个节点就行了
            但是我们还要维护一些量，比如新建节点的最长回文后缀
            所以我们接着进行第一个 while
            差不多的工作——寻找以当前位置为结尾的第二长回文串后缀。来作为新建节点的最长回文后缀
            找到之后再维护一些量就行了
            */
            int now = new_node(len[u] + 2);
            int v = fa[u];
            while(s[n - len[v] - 1] != s[n]) v = fa[v];
            fa[now] = tran[v][c];
            tran[u][c] = now;
            num[now] = num[fa[now]] + 1;
        }
        // 出现过
        last = tran[u][c];
        size[last]++;
        L[n] = len[last];
    }
};