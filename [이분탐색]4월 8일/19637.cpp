#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, string> title; //칭호와 그 칭호의 전투력 상한값

	int n, m, power;//n칭호 개수, m캐릭터 개수, power전투력 상한값
	string name;//칭호

	//입력
	cin >> n >> m; //n,m 입력 받기
	while (n--) { //n번 반복
		cin >> name >> power; //칭호의 이름과 해당 칭호의 전투력 상한값 입력받기
		if (title[power].empty()) { //power에 해당하는 칭호가 존재하지 않는 경우
			title[power] = name; //칭호 저장하기
		}
	}

	//출력
	while (m--) { //m번 반복
		cin >> power; //전투력 입력 받음
		cout << title.lower_bound(power)->second << '\n'; //해당위치 칭호를 출력
	}
}