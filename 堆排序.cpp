#include<iostream>
#include<algorithm>
#define N 100010
using namespace std;
int m, n;
int heap[N], s;

// 下沉
void down(int k) {
    int tmp = k;
    if (k * 2 <= s && heap[k * 2] < heap[tmp]) tmp = k * 2;
    if (k * 2 + 1 <= s && heap[k * 2 + 1] < heap[tmp]) tmp = k * 2 + 1;
    if (k != tmp) {
        swap(heap[k], heap[tmp]);
        down(tmp);
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
    }

    s = n;

    /**
     *因为堆 没有左右节点的根节点 的个数为 n / 2 + 1 
     *所以可以从 n / 2 开始执行下沉操作
     */
    for (int i = n / 2; i >= 1; i--) down(i); 

    while (m--) {
        cout << heap[1] << " ";
        heap[1] = heap[s--];
        down(1);
    }
    
    return 0;
}