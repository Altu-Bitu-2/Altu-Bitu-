#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, num;
	string cmd;
	vector<bool> s(SIZE, false);

	cin >> m; //m 입력
	while (m--) { //반복문
		cin >> cmd; //명령 입력
		if (cmd == "all") { //명령이 all이면
			s.assign(SIZE, true); //배열에 있는 모든 원소 있다고 바꿈
			continue; //다음 명령 
		}
		if (cmd == "empty") { //명령이 empty면
			s.assign(SIZE, false); //배열에 있는 모든 원소 없다고 바꿈
			continue; //다음 명령
		}

		cin >> num; //num입력 받음
		if (cmd == "add") { //명령이 add면
			s[num] = true; //해당 원소 있다고 바꿈
			continue; //다음 명령
		}
		if (cmd == "remove") { //명령이 remove면
			s[num] = false; //해당 원소 없다고 바꿈
			continue; //다음 명령
		}
		if (cmd == "check") { //명령이 check이면
			cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
			continue; //다음 명령
		}
		if (cmd == "toggle") { //명령이 toggle이면
			s[num] = !s[num]; //not 명령어로 바꿈
			continue; //다음 명령
		}
	}
	return 0;
}