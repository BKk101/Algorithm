#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int solution(vector<int> scoville, int K) {
	int answer = -1;
	int len = scoville.size();

	for (long long i : scoville) {
		pq.push(i);
	}
	int cnt = 0;
	while (!pq.empty()) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		if (a >= K) {
			answer = cnt;
			break;
		}
		cnt++;
		pq.push(a + 2 * b);
	}

	return answer;
}

int main() {
	solution({ 1, 2, 3, 9, 10, 12}, 7);
}