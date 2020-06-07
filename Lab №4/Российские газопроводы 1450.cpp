#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    long long a, b, cost;
};

int n, m;
long long INF = 1247500000;
long long d[510];
Edge edge[124760];


void FordBelman() {
    for(; ;) {
        bool any = false;
        for(int j = 0; j < m; j++) {
            if(d[edge[j].a] < INF) {
                if(d[edge[j].b] > d[edge[j].a] + edge[j].cost) {
                    d[edge[j].b] = d[edge[j].a] + edge[j].cost;
                    any = true;
                }
            }
        }
        if(!any) {
            break;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        d[i] = INF;
    }
    
    int a, b, cost; 
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> cost;
        edge[i].a = a - 1;
        edge[i].b = b - 1;
        edge[i].cost = -cost;
    }
    int s, f;
    cin >> s >> f;
    s --;
    f --;
    d[s] = 0;
    FordBelman();
    if(d[f] != INF) {
        cout << - d[f];
    } else {
        cout << "No solution\n";
    }
    
    return 0;
}
