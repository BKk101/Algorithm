#if 0

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> root;

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int Find(int node) {
	int res = root[node];
	while (root[node] != node) {
		res = root[node];
		node = root[node];
	}
	return res;
}

void Union(int a, int b) {
	int p1 = Find(a);
	int p2 = Find(b);

	if (p1 < p2) root[p2] = p1;
	else root[p1] = p2;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		root.push_back(i);
	}
	
	sort(costs.begin(), costs.end(), cmp);
	

	for (auto i : costs) {
		if (Find(i[0]) != Find(i[1])) {
			Union(i[0], i[1]);
			answer += i[2];
		}
	}

	return answer;
}

int main() {
	solution(4, { {0, 1, 1},{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} });

}


#endif
