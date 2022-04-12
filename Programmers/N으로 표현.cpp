#if 0

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> dp(8);

int calc(int N, int idx) {
	int res = N;
	for (int i = 0; i < idx; i++) {
		res = res * 10 + N;
	}
	return res;
}

int solution(int N, int number) {
	int answer = 0;

	dp[0].insert(N);
	for (int i = 1; i < 8; i++) {
		dp[i].insert(calc(N, i));

		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				if (j + k != i-1) continue;
				for (int s : dp[j]) {
					for (int e : dp[k]) {
						dp[i].insert(s + e);
						dp[i].insert(s*e);
						if (s - e > 0)
							dp[i].insert(s - e);
						if (e != 0)
							dp[i].insert(s / e);
					}
				}
			}
		}
		if (dp[i].find(number) != dp[i].end())
			return i + 1;
	}

	return -1;
}

int main() {
	solution(5, 12);
}

#endif