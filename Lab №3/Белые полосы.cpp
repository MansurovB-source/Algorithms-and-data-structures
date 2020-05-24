#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> xy;


bool compare_x(xy a, xy b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

bool compare_y(xy a, xy b) {
	if (a.second != b.second) return a.second<b.second;
	return a.first<b.first;
}


int main() {
    long n, m, k, ans;
	cin >> n >> m >> k;
	xy coordinate[180000];
    set <xy> white_one;
	for (long i = 0, x, y; i < k; i++) {
		cin >> x >> y;
		coordinate[i] = make_pair(x, y);
	}
	
	for (long i = 1; i <= m; i++) {
		coordinate[k++] = make_pair(0, i);
		coordinate[k++] = make_pair(n + 1, i);
	}
	for (long i = 1; i <= n; i++) {
		coordinate[k++] = make_pair(i, 0);
		coordinate[k++] = make_pair(i, m + 1);
	}

	sort(coordinate, coordinate + k, compare_x);
	for (int i = 0; i+1 < k ; i++) {
		int diff = coordinate[i + 1].second - coordinate[i].second;
		if (coordinate[i].first == coordinate[i + 1].first && diff >= 2) {
			if (diff == 2) white_one.insert(make_pair(coordinate[i].first, coordinate[i].second + 1));
			else ans++;
		}
	}

	sort(coordinate, coordinate + k, compare_y);
	for (int i = 0;i + 1<k;i++) {
		int diff = coordinate[i + 1].first - coordinate[i].first;
		if (coordinate[i].second == coordinate[i + 1].second && diff >= 2) {
			if (diff == 2) {
				if (white_one.find(make_pair(coordinate[i].first + 1, coordinate[i].second)) != white_one.end()) {
				    ans++;
				}
			} else {
			    ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}