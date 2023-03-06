#include<iostream>
using namespace std;

class Queue{
    int queue[100010],pre,post;
public:
    // pre <= post 为 队列有数据, 否则为空

    // 初始化
    void init(){

        // 队列为空标记
        // pre 为队列前端下标, post 为队列尾端下标
        pre = 0;
        post = -1;
    }

    // 压入数据
    void push(int x){
        queue[++post]=x;
    }

    // 返回队列前部数据
    int front(){
        return queue[pre];
    }

    // 弹出数据
    void pop(){
        if(pre <= post) pre++;
    }

    // 返回队列大小
    int size(){
        return post - pre + 1;
    }

    // 判断队列是否为空
    bool empty(){
        return pre > post;
    }
};