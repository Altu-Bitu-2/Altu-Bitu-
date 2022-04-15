#include <iostream>
#include <map>

using namespace std;

/**
 * [IF�� �� ��� ����]
 *
 * ��� ĳ���Ϳ� Īȣ�� ��Ī�ϴ� ���Ʈ ������ ����ϱ⿣ �ִ� ���� Ƚ�� 10^5 * 10^5 -> 100��!
 * Ư�� ������ '����'���� �ش��ϴ� Īȣ�� ���� �� ����
 * -> �̺� Ž��
 *
 * �ʰ� ���� ���Ҹ� ���ĵ� ���·� �����ϱ� ������ �˰��� ��� ���� ��ü������ �̺� Ž�� �Լ��� ����� �� ����
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, string> title; //Īȣ�� �� Īȣ�� ������ ���Ѱ�

	int n, m, power;//nĪȣ ����, mĳ���� ����, power������ ���Ѱ�
	string name;//Īȣ

	//�Է�
	cin >> n >> m; //n,m �Է� �ޱ�
	while (n--) { //n�� �ݺ�
		cin >> name >> power; //Īȣ�� �̸��� �ش� Īȣ�� ������ ���Ѱ� �Է¹ޱ�
		if (title[power].empty()) { //power�� �ش��ϴ� Īȣ�� �������� �ʴ� ���
			title[power] = name; //Īȣ �����ϱ�
		}
	}

	//���
	while (m--) { //m�� �ݺ�
		cin >> power; //������ �Է� ����
		cout << title.lower_bound(power)->second << '\n'; //�ش���ġ Īȣ�� ���
	}
}