// 1726 - Who goes to visit ...

#include <iostream>

using namespace std;

bool compare(long long a, long long b) {
    return a < b;
}

void quick_sort(long long *points, int first, int last) {
    long long mid;
    int f = first;
    int l = last;
    mid = points[(f + l) / 2];
    do {
        while (compare(points[f], mid)) f++;
        while (compare(mid, points[l])) l--;
        if (f <= l) {
            swap(points[f], points[l]);
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quick_sort(points, first, l);
    if (f < last) quick_sort(points, f, last);
}

int main() {
    long long n;
    cin >> n;
    long long x[n];
    long long y[n];
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    quick_sort(x, 0, n - 1);
    quick_sort(y, 0, n - 1);

    for (long long i = 0; i < n - 1; ++i) {
        sum += (x[i + 1] - x[i]) * (i + 1) * (n - i - 1);
        sum += (y[i + 1] - y[i]) * (i + 1) * (n - i - 1);
    }

    sum = 2 * sum / (n * (n - 1));

    cout << sum << endl;
    return 0;
}