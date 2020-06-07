#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, length;
};

Edge edge[15010];
int parent[1010];
int size[1010];
int hubs = 0;
int n, m;
int cabels;

bool compare (Edge a, Edge b) {
    return a.length < b.length;
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
    hubs ++;
}

int find_set(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        hubs --;
    }   
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        make_set(i);
    }
    
    for(int i = 0; i < m; i++) {
		Edge e;
        cin >> e.a >> e.b >> e.length;
        edge[i] = e;
    }
    
    sort(edge, edge + m, compare);
    
    for(int i = 0; i < m; i++) {
        if(hubs != 1) {
            union_set(edge[i].a, edge[i].b);
        }
        if(hubs == 1) {
            cout << edge[i].length << endl;
            cabels = i + 1;
            cout << cabels << endl;
            break;
        }
    }
    
    for(int i = 0; i < cabels; i++) {
        cout << edge[i].a << " " << edge[i].b << endl;
    }
    return 0;
}
