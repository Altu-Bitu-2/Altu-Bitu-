#include <iostream>
#include <map>

using namespace std;

/**
 * ���� ������ ���� ���� �� �� �ִ����� �˸� ��
 */

int main() {
	int t, n;
	string outfit, kind;

	cin >> t; //t�� �Է¹���
	while (t--) {
		map<string, int> m; //map����

		//�Է�
		cin >> n; //n�� �Է¹���
		while (n--) {
			cin >> outfit >> kind; //outfit,kind�Է� ����
			m[kind]++;  //m[kind] �� ����
		}

		//����
		int result = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++) { 
			result *= (iter->second + 1); //�ش� ������ ���� �Ա�(iter->second) + �� �Ա�(1)
		}

		//���
		//�˸��� ��� ����
		cout << result - 1 << '\n'; //�����-1(�˸��� ���) ���
	}
}