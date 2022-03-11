#include <iostream>

using namespace std;

const int MINUTE = 60; //1�� �ʷ� ��Ÿ��
const int HOUR = 60 * MINUTE; //1�ð� �ʷ� ��Ÿ��
const int DAY = 24 * HOUR; //�Ϸ� �ʷ� ��Ÿ��

//��ȭ�ϴ� �� �� ����ؼ� �����ִ� �Լ�
int changeTime(int t, int c) {
	//������ �ʰ� �Ϸ纸�� ũ�ٸ� �Ϸ簡 �Ѿ�Ƿ� ��ⷯ ���� �� ����
	int change_value = c % DAY;
	if (t == 2) { //�ð� �ڷ�
		change_value = -change_value; //t�� 2�϶� c�� �Է����� �޾ƿͼ�, �ð踦 �ڷ� c�� ����
	}
	return change_value;
}

/**
 * �ܼ� ���� ����
 * �ð踦 ������ ������ +, �ڷ� ������ -
 * !����! ������ ���ư��ų� �������� �Ѿ �� �����Ƿ� �׻� ��ⷯ ������ �ϰ�,
 *       ������ �Ѿ�� ��� (������) �Ϸ縦 �����ִ°� �߿�
 */

int main() {
	//����� �ӵ� ���
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int h, m, s, q, t, c, second = 0; 
	//�Է�
	cin >> h >> m >> s; // h,m,s �� �Է°� ����
	cin >> q;  // q�� �Է°� ����
	//�ð� �ʱ�ȭ
	second = h * HOUR + m * MINUTE + s; //�Է¹��� �ð� �ʷ� ��ȯ�Ͽ� ��Ÿ��
	//�Է� & ���� & ���
	while (q--) {
		cin >> t; //t�� �Է¹���
		if (t == 3) { //�ð谡 ����Ű�� �ð� ���
			second %= DAY; //�Ϸ簡 �Ѿ�� �� �����Ƿ� ��ⷯ ����
			h = second / HOUR; //
			m = (second % HOUR) / MINUTE;
			s = (second % HOUR) % MINUTE;
			cout << h << ' ' << m << ' ' << s << '\n'; //h,m,s ���·� ���
		}
		else { //t=1, �ð� ������(+) / t=2, �ð� �ڷ�(-)
			cin >> c; //c �Է¹���
			second += changeTime(t, c); //��ȭ�ϴ� �� �� ����ؼ� �����ִ� �Լ�
			if (second < 0) //������ �Ѿ�ٸ�
				second += DAY; //�Ϸ� ���ؼ� ������ ��(s) �����
		}
	}
	return 0;
}