/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
const int MAX = 100000;
pair<int, int> tree[4 * MAX];
int index = 1;

void build(int v, int l, int r) {
    if(l == r) {
        tree[v] = make_pair(1, index++);
        return;
    }
    int md = (l + r) / 2;
    build(2 * v, l, md);
    build((2 * v) + 1, md + 1, r);
    tree[v].first = tree[2 * v].first + tree[(2 * v) + 1].first;
    tree[v].second = -1;
}

int query(int v, int l, int r, int k) {
    if(l == r) {
        tree[v].first --;
        return tree[v].second;
    }
    tree[v].first --;
    int md = (l + r) / 2;
    if(tree[2 * v].first >= k) {
        return query(2 * v, l, md, k);
    }
    else {
        return query((2 * v) + 1, md + 1, r, k - tree[2 * v].first);
    }
}

int main()
{
    build(1, 1, MAX);
    int n, k;
    cin >> n >> k;
    int cur_k = k;
    for(int i = 0; i < n; i++) {
        int res = query(1, 1, MAX, cur_k);
        cout << res << " ";
        
        if(i == n - 1) break;
        
        cur_k = (cur_k - 1 + k) % (n - 1 -  i);
        
        if(cur_k == 0) {
            cur_k = n - 1 - i;
        }
    }

    return 0;
}
