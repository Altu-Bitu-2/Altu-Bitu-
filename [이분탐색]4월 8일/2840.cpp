#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//Ư�� ȭ��ǥ���� ������ ����� ���� ����
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
	string ans = "";//������ ���� ���ڵ��� ���ڿ��� ǥ���ϱ� ���� ans ����
	int start = arrow_point; //�Ѱܹ��� ������ idx�� �������� 
	do {
		ans += wheel[arrow_point]; //���� ȭ��ǥ�� ����Ű�� ���ں��� ans �߰�
		arrow_point = (arrow_point + 1) % n; //ȭ��ǥ �� ĭ�� ������
	} while (arrow_point != start); //ȭ��ǥ�� ó������ ���ƿ��� ���߱�
	return ans;//������ ���� ���ڿ� ����
}

//����� ���� ���ϴ� �Լ�
string makeWheel(int n, vector<ci> &record) { 
	vector<char> wheel(n, '?'); //������ ����
	vector<bool> is_available(26, false); //���ĺ� �ߺ� üũ

	int idx = 0; //ȭ��ǥ�� ����Ű�� �ε���
	for (int i = 0; i < record.size(); i++) {//record ũ�� ��ŭ �ݺ�
		int rot = record[i].first; //record�� ���� ���� ���� Ƚ���� rot�� ����
		char alpha = record[i].second; //record�� ���� ���� ���ڸ� alpha�� ����
		idx = (idx - rot % n + n) % n; //ȭ��ǥ ��ġ ����
		if (wheel[idx] == alpha) { //idx ����Ű�� ���� ���� ���ڰ� alpha�� ������
			continue; //�ݺ�
		}
		if (wheel[idx] != '?' || is_available[alpha - 'A']) { //idx�� ����Ű�� ���� �̹� alpha�� �ٸ� ���ڰ� �����ְų� �ٸ� ���� ���� ���ڸ�
			return "!"; //!����
		}
		wheel[idx] = alpha;//idx��ġ�� alpha �ֱ�
		is_available[alpha - 'A'] = true; //alpha ����ߴٰ� Ȯ��
	}
	return arrowStartWheel(idx, n, wheel);
}

/**
 * [����� ����]
 *
 * ������ ���ư� �ʿ� X
 * ȭ��ǥ�� ����Ű�� �ε����� ȸ�� ������ ���� �ٲ���
 *
 * 1. ȭ��ǥ�� ����Ű�� ĭ�� �������� �ʾ����� ���ĺ��� ������ ���´�.
 * 2. �̹� ���ĺ��� �� �ִ� ���, ���� ���ĺ��� �ƴ� ��� ���ǿ� �ش��ϴ� ���� ���� �� ����.
 * 3. ������ �����ִ� ���ĺ��� �ߺ����� �����Ƿ� ������ ���ĺ��� ���� �ڸ��� ���� �� ����.
 */

int main() {
	int n, k;

	//�Է�
	cin >> n >> k; //n,k �Է� ����
	vector<ci> record(k, { 0, 0 }); //���� ȸ�� ���
	for (int i = 0; i < k; i++) { //k�� �ݺ�
		cin >> record[i].first >> record[i].second;

	//���� & ���
	cout << makeWheel(n, record); //���
	return 0;
}