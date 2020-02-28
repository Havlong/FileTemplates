template<typename T, typename F = binary_function<T, T, T>>
class SegmentTree {
private:
    int size;
    vector<T> tree;
    F up;
public:
    SegmentTree(int size, F mapper) : size(size) {
        tree.resize(4 * size);
    }

    SegmentTree(const vector<int> &toBuildFrom, F mapper) : size(toBuildFrom.size()) {
        tree.resize(4 * size);
        build(toBuildFrom);
    }

    void build(const vector<int> &vector, const int ql, const int qr, const int pos = 1) {
        if (ql == qr) {
            tree[pos] = vector[ql];
            return;
        }
        int mid = (ql + qr) / 2;
        build(vector, ql, mid, pos * 2);
        build(vector, mid + 1, qr, pos * 2 + 1);
        tree[pos] = up(tree[pos * 2], tree[pos * 2 + 1]);
    }

    void update(const int &i, const T &x, const int ql, const int qr, const int pos = 1) {
        if (ql == qr) {
            tree[pos] = x;
            return;
        }
        int mid = (ql + qr) / 2;
        if (i <= mid)
            update(i, x, ql, mid, pos * 2);
        else
            update(i, x, mid + 1, qr, pos * 2 + 1);
        tree[pos] = up(tree[pos * 2], tree[pos * 2 + 1]);
    }


    T query(const int &l, const int &r, const int ql, const int qr, const int pos = 1) {
        if (ql >= l && qr <= r)
            return tree[pos];
        int mid = (ql + qr) / 2;
        if (mid >= qr) {
            return query(l, r, ql, mid, pos * 2);
        }
        if (mid < ql) {
            return query(l, r, mid + 1, qr, pos * 2 + 1);
        }
        auto lVal = query(l, r, ql, mid, pos * 2);
        auto rVal = query(l, r, mid + 1, qr, pos * 2 + 1);
        return up(lVal, rVal);
    }

    template<typename Q = function<void(T)>>
    void query(const int &l, const int &r, const int ql, const int qr, Q queryMapper, const int pos = 1) {
        if (ql >= l && qr <= r) {
            queryMapper(tree[pos]);
            return;
        }
        int mid = (ql + qr) / 2;
        if (mid >= qr) {
            query(l, r, ql, mid, queryMapper, pos * 2);
            return;
        }
        if (mid < ql) {
            query(l, r, mid + 1, qr, queryMapper, pos * 2 + 1);
            return;
        }
        query(l, r, ql, mid, queryMapper, pos * 2);
        query(l, r, mid + 1, qr, queryMapper, pos * 2 + 1);
    }
};
