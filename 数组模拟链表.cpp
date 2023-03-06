/*
* 1）数组模拟单链表
*    1.邻接表：存储 图、树
*
* 2）数组模拟双链表
*    1.优化某些问题
*/

#include<iostream>
using namespace std;
const int N = 100010;

//  1），定义 链表值、next指针 数组, 由 下标 关联
class SingleList {
    /*
     * head 为头节点下标
     * e[i] 为节点i的值
     * ne[i] 为节点i的next指针指向的节点
     * idx 表示当前节点下标
     */
    int head, e[N], ne[N], idx;
public:

    // 初始化
    void init() {
        // 初始化 头节点 下标为 -1, 代表 虚拟头节点
        // [虚拟头节点][虚拟next指针]-> (-1)  ----链表初始状态
        head = -1;
        idx = 0;
    }

    // 在头节点后面插入新节点
    void add_head(int x) {
        e[idx] = x; // 储存节点值
        ne[idx] = head; // next指针 指向 头节点的下一个节点
        head = idx; // 更新头节点下一个节点
        idx++;
    }

    // 在指定节点后面插入新节点
    void add(int x, int k) {
        e[idx] = x; //存储节点值
        ne[idx] = ne[k]; // next指针 指向 k节点的下一个节点
        ne[k] = idx;  // 更新k节点下一个节点
        idx++;
    }

    //删除指定节点
    void dele(int k) {
        ne[k] = ne[ne[k]]; // 删除 k节点的下一个节点
    }

    void output() {
        for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    }
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// 2）链表值、l 和 r 指针 数组, 由 下标idx 关联
class DoubleList {
    /*
     * e[i] 为节点i的值
     * l[i] 为节点i左指针指向的节点
     * r[i] 为节点i右指针指向的节点
     */
    int e[N], l[N], r[N], idx;
public:

    // 初始化
    void init() {
        // 下标0 维护 最左端点，下标1 维护 最右端点
        r[0] = 1;
        l[1] = 0;
        // [][0][] <-> [][1][] ----链表初始状态

        idx = 2;//因为 下标0 和 下标1 被占用, idx 从 下标2 开始
    }

    // k节点 右端添加
    void add(int x, int k) {
        e[idx] = x;

        // 新节点 链接2边节点
        l[idx] = k;
        r[idx] = r[k];

        // 下面 2行 不能换位
        // 2边 指针 归位
        l[r[k]] = idx;
        r[k] = idx;


        idx++;
    }

    // 删除 k节点
    void del(int k) {
        // [][ l[k] ][] <-> [][ k ][] <->[][ r[k] ][]  ----函数执行前
        // [][ l[k] ][] <-> [][ r[k] ][]               ----函数执行后
        r[l[k]] = r[k];
        l[r[k]] = l[k];
    }

    void output() {
        for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    }

};

