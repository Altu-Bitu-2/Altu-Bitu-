#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * ver1. set을 이요한 풀이입니다.
 * 정렬을 할 필요가 없이, 삽입과 검색만 일어나는 문제입니다.
 * 입력의 수가 최대 1,000,000으로 삽입과 탐색이 많이 일어납니다.
 * 따라서, O(log N)의 set이 아니라 O(1)인 unordered_set을 사용해서 풀어야 합니다.
 * */

int main() {
	// 입출력 처리 속도 향상을 위한 코드
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	int t; 
	cin >> t; //t를 입력 받는다
	while (t--) {
		int n, m, input;
		unordered_set<int> note1;

		// 수첩1에 해당되는 원소들을 unordered_set에 삽입
		cin >> n; //n을 입력 받는다
		while (n--) {
			cin >> input; // input을 입력 받는다
			note1.insert(input); //수첩1에 해당되는 원소들을 unordered_set에 삽입
		}
		cin >> m; //m을 입력 받는다
		while (m--) {
			cin >> input; //input을 입력 받는다
			// 반복자를 이용해서 원소가 셋에 포함되어 있는지 확인
			auto iter = note1.find(input);
			if (iter == note1.end()) { //iter=note1.end()이면 0을 출력
				cout << "0\n";
			}
			else { //iter=note1.end()이 아니면 1을 출력
				cout << "1\n";
			}
		}
	}
	return 0;
}