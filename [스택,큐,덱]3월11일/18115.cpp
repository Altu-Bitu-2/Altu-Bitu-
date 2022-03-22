#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

deque<int> cardGame(int n, vector<int> &cmd) {
	deque<int> dq; //�� ����

	for (int i = 1; i <= n; i++) { //���� �ִ� ���� ī����� �˻� 1, ..., n
		switch (cmd[i]) {
		case 1:
			dq.push_front(i); //�� �տ� i���� �߰�
			break;
		case 2: { //!����! c++���� switch-case ���� ���� ���� �� {} �ʼ�!
			int x = dq.front(); //���� �� �� ���� 
			dq.pop_front(); //�� �� ���� ����
			dq.push_front(i); //�� �� ���� �߰�
			dq.push_front(x); //�� �� x�߰�
			break;
		}
		case 3:
			dq.push_back(i); //�� �ڿ� i���� �߰�
			break;
		}
	}
}

/**
 * ������� ���� ó�� ���� -> ����� ��� �ݴ�� ����!
 * 1. ���� ���� ī�� �ٴڿ� �������� ->
 *    �ٴڿ� �������� ī�带 �ٽ� ���� ->
 *    ���� ���� ī�� �տ� �ֱ�
 * 2. ������ �� ��° ī�� �ٴڿ� �������� ->
 *    �ٴڿ� �������� ī�� ������ �� ��°�� �ֱ� ->
 *    ���� ���� ī�� �տ��� �ι�°�� �ֱ�
 * 3. ���� �ؿ� �ִ� ī�� �ٴڿ� �������� ->
 *    �ٴڿ� �������� ī�� �ؿ� �ֱ� ->
 *    ���� ���� ī�� �ڿ� �ֱ�
 */

int main() {
	int n;

	//�Է�
	cin >> n; //n�� �Է�
	vector<int> cmd(n + 1, 0);
	for (int i = 1; i <= n; i++) { 
		cin >> cmd[i]; //�迭 cmd �� �Է¹���
	}

	//����
	reverse(cmd.begin() + 1, cmd.end()); //���� ���� ī����� �˻��ϱ� ���� ��� ������ �ݴ��
	deque<int> dq = cardGame(n, cmd);

	//���
	while (!dq.empty()) { //���� ���Ұ� ���� ��� �ݺ�
		cout << dq.front() << ' '; //dq.front�� ���
		dq.pop_front(); //�� �տ� �ִ� �� ����
	}
	return 0;
}