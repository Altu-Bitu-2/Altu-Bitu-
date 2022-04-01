#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * [����] - �ܼ� ���� ����
 *
 * ver1. �迭 ��� Ǯ��
 * set()�� ����ؼ� �Ź� ������ �ϸ� �ð��� ������ ���� �ɷ���.
 * �ԷµǴ� x�� ���� 1~20���� ������ �ſ� �۱� ������, �� ���ڰ� ���տ� ����ִ� ���θ� �����ϴ� �迭�� �̿��մϴ�.
 *
 * 1. ���տ��� 1~20�� ���ڸ� �Է� or ���ŵ� (=true or false)
 * 2. ũ�� 21�� bool �迭�� ����
 * 3. �Է��� true ó��, ���Ŵ� false ó��
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, num;
	string cmd;
	vector<bool> s(SIZE, false);

	cin >> m; //m �Է�
	while (m--) { //�ݺ���
		cin >> cmd; //��� �Է�
		if (cmd == "all") { //����� all�̸�
			s.assign(SIZE, true); //�迭�� �ִ� ��� ���� �ִٰ� �ٲ�
			continue; //���� ��� 
		}
		if (cmd == "empty") { //����� empty��
			s.assign(SIZE, false); //�迭�� �ִ� ��� ���� ���ٰ� �ٲ�
			continue; //���� ���
		}

		cin >> num; //num�Է� ����
		if (cmd == "add") { //����� add��
			s[num] = true; //�ش� ���� �ִٰ� �ٲ�
			continue; //���� ���
		}
		if (cmd == "remove") { //����� remove��
			s[num] = false; //�ش� ���� ���ٰ� �ٲ�
			continue; //���� ���
		}
		if (cmd == "check") { //����� check�̸�
			cout << s[num] << '\n'; //bool ���� ����ϸ� true: 1, false: 0���� ���
			continue; //���� ���
		}
		if (cmd == "toggle") { //����� toggle�̸�
			s[num] = !s[num]; //not ��ɾ�� �ٲ�
			continue; //���� ���
		}
	}
	return 0;
}