#if 0
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Pair {
	int s, t;
}Pair;

struct cmp {
	bool operator()(Pair a, Pair b) {
		return a.t > b.t;
	}
};

priority_queue<Pair, vector<Pair>, cmp> pq;

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int time = 0;
	int idx = 0;

	sort(jobs.begin(), jobs.end());
	while (idx < jobs.size() || !pq.empty()) {
		if (idx < jobs.size() && jobs[idx][0] <= time) {
			pq.push({ jobs[idx][0],jobs[idx][1] });
			idx++;
			continue;
		}
		if (!pq.empty()) {
			Pair temp = pq.top();
			pq.pop();
			time += temp.t;
			answer += time - temp.s;
		}
		else {
			time = jobs[idx][0];
		}

	}
	answer /= jobs.size();

	return answer;
}

int main() {
	solution({ {0,3},{2,6},{1,100} });
}


#endif