#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int a, b;
    double r, c;
};

vector<Edge>edge;
int N, M, S;
double V;
double exchange[101];

int main() {
    cin >> N >> M >> S >> V;
    exchange[S] = V;

    for(int i = 0; i < M; i++) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        edge.push_back({a, b, rab, cab});
        edge.push_back({b, a, rba, cba});
    }
    
    // cout << "\n";
    // for (auto e : edge) {
    //     cout << e.a << " " << e.b << " " << e.r << " " << e.c << "\n";
    // }
    
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < edge.size(); j++) {
            if(exchange[edge[j].b] - ((exchange[edge[j].a] - edge[j].c) * edge[j].r) < 0.00000001) {
                exchange[edge[j].b] = (exchange[edge[j].a] - edge[j].c) * edge[j].r;
            };
        }
    }
    
    // cout << "\n";
    // for(int i = 0; i < 110; i++) {
    //     cout << exchange[i] << " ";
    // }
    
    for(int i = 0; i < edge.size(); i++) {
        if(((exchange[edge[i].a] - edge[i].c)*edge[i].r) - exchange[edge[i].b] > 0.00000001) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}