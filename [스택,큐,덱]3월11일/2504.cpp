#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
	stack<char> st;
	map<char, int> num; //��ȣ ��
	map<char, char> bracket; //��ȣ ��

	//��ȣ �ְ� �� ����
	bracket[')'] = '(';
	bracket[']'] = '[';
	num['('] = 2; //()�� ��=2
	num['['] = 3; //[]�� ��=3

	int ans = 0, temp = 1;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) { //s�� i��° ����
		case '(': case '[': //���� ��ȣ�� ���
			st.push(s[i]); //push
			temp *= num[s[i]]; // ���ϱ� ����
			break;
		case ')': case ']': //�ݴ� ��ȣ�� ���
			if (st.empty() || st.top() != bracket[s[i]]) { //������ ����ְų� ������ ���κ��� ���� ���� ���� ��� 
				return 0; //0���
			}
			if (s[i - 1] == bracket[s[i]]) { //¦�� ������
				ans += temp; //���ϱ� ����
			}
			temp /= num[bracket[s[i]]]; //�̹� ���� ���� ����̹Ƿ� ������
			st.pop(); //���ÿ� pop
			break;
		}
	}
	if (st.empty()) { //�ùٸ� ��ȣ���
		return ans; //ans return
	}
	return 0;
}

/**
 * "�й��Ģ"�� Ȱ��!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   �ӽú�����:  2   6 2     4  12   4   2   1
 * =>                        ����:        +6           +12        = 18
 *
 * ����, �켱 ���� ��ȣ�� ������ ��ȣ�� ���� ������
 * �ݴ� ��ȣ��, ���� ���ڰ� ���� ��ȣ�� ��� ���ݱ��� ���� ���� ������ (���� �ߺ����� �������� ���� �����ϱ� ���� ���� ���ڰ� ���� ��ȣ���� �� üũ!)
 *            �� ��ȣ�� ���� ������ �������Ƿ� (���ϱ� ����) �ٽ� ��ȣ ���� �����༭ ���� ����
 */

int main() {
	string s;

	//�Է�
	cin >> s; //s�� �Է�
	//���� & ���
	cout << calc(s); //calc(s)�� ���
	return 0;
}