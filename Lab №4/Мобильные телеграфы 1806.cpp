#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 50000;
const int ten = 10;
int cost[ten];

struct Node {
    vector<pair<int, Node*>> v;
    Node* parent;
    int d;
    bool visited;
};

unordered_map<long long, Node*> vertices;
Node nodes[N];
long long degree[ten];



long long setD(long long tel_num, int i) {
    return tel_num / degree[i] % ten;
}


int prefix(long long tel_num_1, long long tel_num_2) {
    int counter = 0;
    for(int i = ten - 1; i >= 0; i--) {
        if(setD(tel_num_1, i) == setD(tel_num_2, i)) {
            counter ++;
        } else {
            
            break;
        }
    }
    //cout << "----------- " << counter << " ---------------------\n";
    return counter;
}

long long change_D(long long tel_num, int i, int j) {
    return tel_num - ((long long) setD(tel_num, i)) * degree[i] + j * degree[i];
}

void add_to_graph(long long tel_num_1, int id) {
    vector<pair<int, Node*>> t_vertices;
    
    for(int i = 0; i < ten; i++) {
        for(int j = 0; j < ten; j++) {
            long long tel_num_2 = change_D(tel_num_1, i, j);
            auto v_tel_num_2 = vertices.find(tel_num_2);
            if(v_tel_num_2 != vertices.end()) {
                int t_cost = cost[prefix(tel_num_1, tel_num_2)];
                //cout << "----------- " << t_cost << " ---------------------\n";
                t_vertices.push_back({t_cost, (*v_tel_num_2).second});
            }
        }
    }
    
    for(int i = 0; i < ten; i++) {
        for(int j = i + 1; j < ten; j++) {
            int k_i = setD(tel_num_1, i);
            int k_j = setD(tel_num_1, j);
            long long tel_num_2 = change_D(change_D(tel_num_1, j, k_i), i, k_j);
            auto v_tel_num_2 = vertices.find(tel_num_2);
            if(v_tel_num_2 != vertices.end()) {
                int t_cost = cost[prefix(tel_num_1, tel_num_2)];
                t_vertices.push_back({t_cost, (*v_tel_num_2).second});
            }
        }
    }
    
    vertices[tel_num_1] = &nodes[id];
    
    for(auto p : t_vertices) {
        p.second -> v.push_back({p.first, &nodes[id]});
        nodes[id].v.push_back({p.first, p.second});
    }
}

void Dijkstra(Node* first, int N) {
    const long long INF = 500000000;
    using cost_node = pair<int, Node*>;
    priority_queue<cost_node, vector<cost_node>, greater<cost_node>> p_queue;
    
    for(int i = 0; i < N; i++) {
        nodes[i].d = INF;
        nodes[i].visited = false;
    }
    first -> d = 0;
    p_queue.push({0, first});
    while(!p_queue.empty()) {
        auto present = p_queue.top();
        p_queue.pop();
        auto node = present.second;
        if(node -> visited) {
            continue;
        }
        node -> visited = true;
        for(auto iter = node -> v.begin(); iter < node -> v.end(); iter++) {
            auto nod = iter -> second;
            int nod_cost = iter -> first;
            
            if(!nod -> visited && nod -> d > node -> d + nod_cost) {
                nod -> parent = node;
                nod -> d = node -> d + nod_cost;
                p_queue.push({nod -> d, nod});
            }
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    
    long long k = 1;
    for(int i = 0; i < ten; i++) {
        degree[i] = k;
        k *= 10;
    }
    
    for(int i = 0; i < ten; i++) {
        cin >> cost[i];
        //cout << cost[i] << " ";
    }
    cout << "\n";
    
    for(int i = 0; i < n; i++) {
        long long tel_num;
        cin >> tel_num;
        add_to_graph(tel_num, i);
    }
    
    Dijkstra(&nodes[0], n);
    
    if(!nodes[n - 1].visited) {
        cout << - 1 << "\n";
        return 0;
    }
    cout << nodes[n - 1].d << "\n";
    vector<Node*> finish;
    for(Node *node = &nodes[n - 1]; node; node = node -> parent) {
        finish.push_back(node);
    }
    cout << finish.size() << "\n";
    for(auto iter = finish.rbegin(); iter < finish.rend(); iter++) {
        cout << (1 + (*iter - nodes)) << " ";
    }
}