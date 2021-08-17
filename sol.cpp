#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, x;
		cin >> n >> m >> x;
		vector<int> a(n), id(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// store the indices in a separate list
			id[i] = i;
		}
		// sort the indicies based on their value in list 'a'
		sort(id.begin(), id.end(), [&](const int& i, const int& j) -> bool {
			return a[i] > a[j];
		});
		set<int> s;
		for (int i = 0; i < n; i++) {
			// check if the current value is greater than or equal to 'm' or if 'x' is not 0
			if (a[id[i]] >= m || x > 0) {
				// if yes, then store the indices in a set
				s.emplace(id[i] + 1);
				// decrement 'x'
				x--;
			}
		}
		cout << (int) s.size() << " ";
		for (auto y : s) {
			cout << y << " ";
		}
		cout << '\n';
	}
	return 0;
}
