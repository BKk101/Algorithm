#if 0

#include <string>
#include <vector>

using namespace std;

int ranks[101][101];

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	for (auto r : results) {
		ranks[r[0]][r[1]] = 1;
		ranks[r[1]][r[0]] = 2;
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ranks[i][j] != 0 || i == j) continue;
			for (int k = 1; k <= n; k++) {
				if (ranks[i][k] == 1 && ranks[k][j] == 1) ranks[i][j] = 1;
				else if (ranks[i][k] == 2 && ranks[k][j] == 2) ranks[i][j] = 2;
			}
		}
	}*/ //틀린방법 k를 가장 바깥 루프에 넣어야함
	for (int i = 1; i <= n; i++) {
		int j;
		for (j = 1; j <= n; j++) {
			if (i == j) continue;
			if (ranks[i][j] == 0) break;
		}
		if (j == n) answer++;
	}
	return answer;
}

int main() {
	solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}

#endif
