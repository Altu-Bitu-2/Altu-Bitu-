#include <iostream>
#include <map>

using namespace std;

/**
 * 같은 종류의 옷이 각각 몇 벌 있는지만 알면 됨
 */

int main() {
	int t, n;
	string outfit, kind;

	cin >> t; //t를 입력받음
	while (t--) {
		map<string, int> m; //map선언

		//입력
		cin >> n; //n을 입력받음
		while (n--) {
			cin >> outfit >> kind; //outfit,kind입력 받음
			m[kind]++;  //m[kind] 수 증가
		}

		//연산
		int result = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++) { 
			result *= (iter->second + 1); //해당 종류의 옷을 입기(iter->second) + 안 입기(1)
		}

		//출력
		//알몸인 경우 제외
		cout << result - 1 << '\n'; //결과값-1(알몸일 경우) 출력
	}
}