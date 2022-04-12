#if 0

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	stack<pair<int,int>> st;
	vector<pair<int, int>> res;

	st.push({ prices[0], 0 });
	for (int i = 1; i < prices.size(); i++) {
		while (!st.empty() && st.top().first > prices[i]) {
			res.push_back({ st.top().second, i - st.top().second });
			st.pop();
		}
		st.push({prices[i], i});
	}
	while (!st.empty()) {
		res.push_back({ st.top().second, prices.size() -1 - st.top().second });
		st.pop();
	}
	sort(res.begin(), res.end());
	for (auto i : res) {
		answer.push_back(i.second);
	}
	return answer;
}

int main() {
	solution({ 1, 2, 3, 2, 3 });
}

#endif