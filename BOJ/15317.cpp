#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int N, M, X;
vector<int> cost;
vector<int> budget;

bool calc(int n) {
	int xx = 0;
	for (int i = 0; i < n; i++) {
		if (cost[i] > budget[M - n + i]) {
			xx += cost[i] - budget[M - n + i];
		}
	}
	return X >= xx;
}

int main() {
	
	cin >> N >> M >> X;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		cost.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		budget.push_back(temp);
	}
	sort(cost.begin(), cost.end());
	sort(budget.begin(), budget.end());

	int s, e;
	s = 0;
	e = min(N, M);

	while (e - s > 5) {
		int m = (s + e) / 2;
		if (calc(m)) {
			s = m;
		}
		else {
			e = m - 1;
		}
	}
	for (int i = e; i >= s; i--) {
		if (calc(i)) {
			cout << i;
			break;
		}
	}
	cout << -1;
}