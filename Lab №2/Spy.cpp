// 1322 - Spy

#include <iostream>

using namespace std;

void DWT(int N, int M, int k, string s) {
    int *count = new int[M];
    int *t = new int[M];
    char *result = new char[N];
    int sum = 0;
    for (int i = 0; i < M; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        count[s[i]]++;
    }
    for (int i = 0; i < M; i++) {
        sum = sum + count[i];
        count[i] = sum - count[i];
    }
    for (int i = 0; i < N; i++) {
        t[count[s[i]]] = i;
        count[s[i]]++;
    }
    int x = t[k];
    for (int i = 0; i < N; i++) {
        result[i] = s[x];
        x = t[x];
    }

    for (int i = 0; i < N; i++) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int n;
    string s;

    cin >> n >> s;

    DWT(s.length(), 125, n - 1, s);

    return 0;
}

