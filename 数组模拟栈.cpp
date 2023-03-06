#include<iostream>
using namespace std;


/*
 * 数组模拟栈
 * 由 下标idx 控制
 */
class Stack{
    int stack[100010], idx;
public:
    // 初始化, 一定要调用
    void init(){
        // 初始下标为 -1, 表示 栈为空
        idx = -1;         
    }

    // 压入操作
    void push(int x){
        // 更新 下标idx 和 数组对应的值, 表示 压入数据
        stack[++idx] = x;
    }

    // 弹出操作
    void pop(){
        // 下标idx 减1, 表示弹出
        --idx;
    }
    
    // 返回栈的大小
    int size(){
        return idx + 1;
    }

    // 判断栈是否为空
    bool empty(){
        // 当 下标idx 为 -1 时, 代表栈为空
        return idx == -1;
    }

    // 返回栈顶数据
    int top(){
        // 返回当前 下标idx 指向的数据
        return stack[idx];
    }
};





