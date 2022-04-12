#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int temp = 0;
	sort(people.begin(), people.end(), less<int>());

	for (int i = 0; i < people.size(); i++) {
		if (people[i] == 0) continue;
		temp = 0;
		answer++;
		for (int j = i; j < people.size(); j++) {
			if (temp == limit || temp + people[people.size() - 1] > limit) break;
			if (temp + people[j] <= limit) {
				temp += people[j];
				people[i] = 0;
			}
		}
	}
	return answer;
}

int main() {
	solution({ 70,50,80,50 }, 100);
}

#endif