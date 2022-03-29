#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground) {
	while (!ground.empty()) { //그라운드가 비어있을때까지 겹침
		deck.push_back(ground.back()); //그라운드 마지막에 있는 것 부터 겹침
		ground.pop_back(); //뒤에서 부터 팝
	}
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
	bool turn = false; //도도부터 시작

	while (m--) { //m번 게임 진행
		//이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
		int card = deck[turn].front(); //첫번째 덱을 받기
		ground[turn].push_front(card); //그라운드에 첫번째 카드를 앞에 넣기
		deck[turn].pop_front(); //덱에 있던 첫번째 카드를 없애기

		if (deck[turn].empty()) { //덱에 더이상 카드가 없을 경우
			break; //멈춤
		}

		//이번에 종을 칠 사람
		int bell = -1; 
		if (card == 5) {  //그라운드에 있는 카드가 5이면 도도가 종을 침
			bell = 0; 
		}
		else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) {
			bell = 1; //그라운드에 둘 다 카드가 있고 그라운드에 있는 카드의 합이 5일 경우 수연이가 종을 침
		}

		if (bell != -1) { //종을 둘 중 한 명이 칠 경우
			moveCard(deck[bell], ground[!bell]); //상대방의 그라운드에 있는 카드를 자신의 덱에 합침
			moveCard(deck[bell], ground[bell]); //자신의 그라운드의 카드를 자신의 덱에 합침
		}
		turn = !turn; //차례 바꾸기
	}
	return make_pair(deck[0].size(), deck[1].size());
}

/**
 * [숫자 할리갈리 게임] - 시뮬레이션 문제
 * - 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 *
 * 1. 차례가 되면, 상단 카드를 그라운드에 놓는다.
 * 2. 누군가의 카드 덱이 비는 즉시 게임 종료
 * 3. 종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미의 밑에 넣는다.
 */

int main() {
	int n, m, num1, num2;
	vector<deque<int>> deck(2), ground(2);

	cin >> n >> m; //도도와 수연이가 가지는 덱의 개수와 게임 진행 횟수를 입력받음
	while (n--) { //n번 반복
		cin >> num1 >> num2; //num1,num2 입력받음
		deck[0].push_front(num1); // 도도의 덱
		deck[1].push_front(num2); //수연의 덱
	}

	pair<int, int> result = playGame(m, deck, ground); //게임의 결과값을 받아 저장

	if (result.first == result.second) { //만약 덱의 수가 같을 경우
		cout << "dosu\n"; //비김
	}
	else if (result.first > result.second) { //도도의 덱의 수가 많을 경우
		cout << "do\n"; //도도의 승리
	}
	else if (result.first < result.second) { //수연의 덱의 수가 많을 경우
		cout << "su\n"; //수연 승리
	}
	return 0;
}