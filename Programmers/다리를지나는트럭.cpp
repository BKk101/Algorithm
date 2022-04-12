#if 0

#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

queue<pair<int, int>> que;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int tot = 0;
	int idx = 0;
	int time = 0;

	while (!que.empty() || idx < truck_weights.size()) {
		if (!que.empty() && time == que.front().second + bridge_length) {
			tot -= que.front().first;
			que.pop();
		}
		if (idx < truck_weights.size() && tot + truck_weights[idx] <= weight) {
			que.push({ truck_weights[idx], time });
			tot += truck_weights[idx];
			idx++;
			if (idx<truck_weights.size() && tot + truck_weights[idx] <= weight) time += 1;
			else time = min(time + bridge_length, que.front().second + bridge_length);
		}
		else time++;
	}

	return time;
}

int main() {
	solution(2, 10, { 7, 4, 5, 6 });
}

#endif