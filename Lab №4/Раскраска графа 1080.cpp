#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int color[100];
vector<int> graph[100];

bool reverse(int color) {
    if(color == 0) {
        return 1;
    } else {
        return 0;
    }
}

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int i = 0; i < graph[current].size(); i++) {
            int neighbour = graph[current][i];
            if(color[neighbour] == -1) {
                color[neighbour] = reverse(color[current]);
                q.push(neighbour);
            } else {
                if(color[neighbour] == color[current]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
		color[i] = -1;
	}
	int x;
    for(int i = 0; i < n; i++) {
        while(cin >> x) {
            if(x != 0) {
                graph[i].push_back(x - 1);
                graph[x - 1].push_back(i);
            } else {
                break;
            }
        }
    }
    color[0] = 0;
    bool flag = bfs(0);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            color[i] = 0;
            flag = flag && bfs(i);
        }
    }
    if(flag) {
        for(int i = 0; i < n; i++) {
            cout << color[i];
        }
    } else {
        cout << -1;
    }
    
    return 0;
}
