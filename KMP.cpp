#include<iostream>
using namespace std;

class KMP{
    // 初始下标从 1 开始
    #define N 10010
    #define M 100010

    // s 为主串 , p 为模式串 , n 为 模式串p 的长度 , m 为 主串s 的长度
    int n, m;
    char p[N], s[M];
    int ne[N];
public:

    void init(){
        cin>> n >> p + 1 >> m >> s + 1;
    }

    void build_next(){
        for(int i = 2, j = 0; i <= n; i++){
            while(j && p[j + 1] != p[i]) j = ne[j];
            if(p[i] == p[j + 1]) j++;
            ne[i] = j;
        }
    }

    void kmp_search(){
        for(int i = 1, j = 0; i <= m; i++){
            while(j && s[i] != p[j + 1]) j = ne[j];
            if(s[i] == p[j + 1]) j++;
            if(j == n){
                // 匹配成功 输出部分
                cout<< i - j << " "; // 匹配成功起始点

                j = ne[j];
            }
        }
    }

private:
    void KMP_set_from0idx(){
        cin >> m >> p >> n >> s; // 读入

        // next数组
        ne[0] = -1;
        for (int i = 1, j = -1; i < m; i ++ )
        {
            while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
            if (p[j + 1] == p[i]) j ++ ;
            ne[i] = j;
        }

        // KMP
        for (int i = 0, j = -1; i < n; i ++ )
        {
            while (j != -1 && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) j ++ ;
            if (j == m - 1)
            {
                cout << i - j << ' ';
                j = ne[j];
            }
        }
    }
};

