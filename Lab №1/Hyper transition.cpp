#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int time;

    cin >> n;
    vector<int> times(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> time;
        times[i] = time;
    }

    int result = times[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += times[i];
        result = max(result, sum);
        sum = max(sum, 0);
    }

    if (result < 0) {
        result = 0;
    }

    cout << result << endl;

    return 0;
}