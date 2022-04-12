#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int len = citations.size();
	sort(citations.begin(), citations.end());
	for (int i = 0; i < len; i++) {
		if (len - i <= citations[i]) answer = max(len - i, answer);
	}
	return answer;
}

int main() {
	solution({3,0,6,1,5});
}

#endif