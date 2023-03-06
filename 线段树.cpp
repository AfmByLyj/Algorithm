// 线段树模板（区间加法求和）
int n, m;
int w[N];  

struct Node{
    int l, r;
    LL sum, add;
}tr[N * 4];

// 维护
void pushup(int u){
    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
}
 
// 懒标记下传， 视情况而定
void pushdown(int u){
    auto &root = tr[u], &left = tr[u * 2], &right = tr[u * 2 + 1];
    if(root.add){
        left.add += root.add;
        left.sum += (LL)(left.r - left.l + 1) * root.add;
        right.add += root.add;
        right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

// 区间修改 d 为增量, 视情况而定
void modify(int u, int l, int r, int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(l <= mid) modify(u * 2, l, r, d);
    if(mid + 1 <= r) modify(u * 2 + 1, l, r, d);
    pushup(u);
}

// 查询
LL query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;

    LL sum = 0;
    if(l <= mid) sum += query(u * 2, l, r);
    if(mid + 1 <= r) sum += query(u * 2 + 1, l, r);
    return sum;
}

// 建树
void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, w[r], 0};
        return;
    }
    tr[u] = {l, r};
    int mid = (l + r) >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    pushup(u);
}