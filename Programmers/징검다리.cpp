#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gap[50001];
int Num;

int check(int dis) {
	int cur = 0;
	int rock = 0;
	for (int i = 0; i <= Num; i++) {
		cur += gap[i];
		if (cur < dis) {
			++rock;
		}
		else {
			cur = 0;
		}

	}
	return rock;
}

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	int num = rocks.size();
	Num = num;
	sort(rocks.begin(), rocks.end());

	gap[0] = rocks[0];
	for (int i = 1; i < num; i++) {
		gap[i] = rocks[i] - rocks[i - 1];
	}
	gap[num] = distance - rocks[num - 1];

	int s = 1;
	int e = distance;
	int mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (check(mid) > n) {
			e = mid - 1;
		}
		else if (check(mid) <= n) {
			s = mid + 1;
		}
		// else {
		//     answer = mid;
		//     break;
		// }
	}
	answer = mid;

	return answer;
}

int main() {
	solution(25, { 2, 14, 11, 21, 17 }, 2);
}