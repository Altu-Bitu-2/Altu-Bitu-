#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//�׶��忡 �ִ� ī�带 ������ �ű�� �Լ�
void moveCard(deque<int> &deck, deque<int> &ground) {
	while (!ground.empty()) { //�׶��尡 ������������� ��ħ
		deck.push_back(ground.back()); //�׶��� �������� �ִ� �� ���� ��ħ
		ground.pop_back(); //�ڿ��� ���� ��
	}
}

//������ �����ϴ� �Լ�
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
	bool turn = false; //�������� ����

	while (m--) { //m�� ���� ����
		//�̹� ���� ����� ī�� ����� �׶��忡 �÷�����
		int card = deck[turn].front(); //ù��° ���� �ޱ�
		ground[turn].push_front(card); //�׶��忡 ù��° ī�带 �տ� �ֱ�
		deck[turn].pop_front(); //���� �ִ� ù��° ī�带 ���ֱ�

		if (deck[turn].empty()) { //���� ���̻� ī�尡 ���� ���
			break; //����
		}

		//�̹��� ���� ĥ ���
		int bell = -1; 
		if (card == 5) {  //�׶��忡 �ִ� ī�尡 5�̸� ������ ���� ħ
			bell = 0; 
		}
		else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) {
			bell = 1; //�׶��忡 �� �� ī�尡 �ְ� �׶��忡 �ִ� ī���� ���� 5�� ��� �����̰� ���� ħ
		}

		if (bell != -1) { //���� �� �� �� ���� ĥ ���
			moveCard(deck[bell], ground[!bell]); //������ �׶��忡 �ִ� ī�带 �ڽ��� ���� ��ħ
			moveCard(deck[bell], ground[bell]); //�ڽ��� �׶����� ī�带 �ڽ��� ���� ��ħ
		}
		turn = !turn; //���� �ٲٱ�
	}
	return make_pair(deck[0].size(), deck[1].size());
}

/**
 * [���� �Ҹ����� ����] - �ùķ��̼� ����
 * - ī�� ���� �׶����� ī�带 �����ϱ� ���� �� ���
 *
 * 1. ���ʰ� �Ǹ�, ��� ī�带 �׶��忡 ���´�.
 * 2. �������� ī�� ���� ��� ��� ���� ����
 * 3. ���� ġ��, ������ �׶��� ī�带 ����� ī�� ������ �ؿ� �ִ´�.
 */

int main() {
	int n, m, num1, num2;
	vector<deque<int>> deck(2), ground(2);

	cin >> n >> m; //������ �����̰� ������ ���� ������ ���� ���� Ƚ���� �Է¹���
	while (n--) { //n�� �ݺ�
		cin >> num1 >> num2; //num1,num2 �Է¹���
		deck[0].push_front(num1); // ������ ��
		deck[1].push_front(num2); //������ ��
	}

	pair<int, int> result = playGame(m, deck, ground); //������ ������� �޾� ����

	if (result.first == result.second) { //���� ���� ���� ���� ���
		cout << "dosu\n"; //���
	}
	else if (result.first > result.second) { //������ ���� ���� ���� ���
		cout << "do\n"; //������ �¸�
	}
	else if (result.first < result.second) { //������ ���� ���� ���� ���
		cout << "su\n"; //���� �¸�
	}
	return 0;
}