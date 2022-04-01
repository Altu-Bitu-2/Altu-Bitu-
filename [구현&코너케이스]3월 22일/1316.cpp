#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
	char cur = NULL; //������ ����
	vector<bool> alphabet(26, false); //�� ���ĺ��� ���� ���θ� üũ

	for (int i = 0; i < str.size(); i++) { //i�� �������� str.size()ũ�� ��ŭ �ݺ�
		if (str[i] == cur) { //�����ؼ� ��Ÿ�� ����
			continue;
		}
		//������ ���ڿ� �ٸ� ���ڰ� ��Ÿ���� ��
		if (alphabet[str[i] - 'a']) { //������ �����ߴ� ���ڸ� �������� ��Ÿ�� ��
			return false; //�迭�� true�� �׷�ܾ� �ƴ�
		}
		cur = str[i]; //
		alphabet[str[i] - 'a'] = true;
	}
	return true;
}

/**
 * [�׷� �ܾ� üĿ] - �ܼ� ���� ����
 * - �̹� ������ ���ĺ��� �迭�� �ε���(���ĺ�)�� Ȱ���ؼ� ���� true/false�� ����
 * - set���� üũ�� ���� �ְ����� �˻�, ���� �ø��� O(logN)�� �ð����⵵�� �ɸ��Ƿ� �ε��� ������ ������ �迭�� ȿ����
 * - ó�� �����ϴ� ���ĺ��� �迭 ���� ������Ʈ �ϰ�, �������� �������µ� �̹� ������ ���ĺ��̸� �׷� �ܾ �ƴϴ�.
 */

int main() {
	int n, result = 0;

	//�Է�
	cin >> n; // �ܾ��� ���� �Է�
	while (n--) {
		string word; 
		cin >> word; //word �Է�

		//����
		if (isGroup(word)) { //�׷� �ܾ����� Ȯ��
			result++; //�׷� �ܾ� ������ ���� �߰�
		}
	}

	//���
	cout << result; //��� ���
	return 0;
}