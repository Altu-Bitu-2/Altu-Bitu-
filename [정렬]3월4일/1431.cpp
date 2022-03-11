#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���ڿ��� ��� �ڸ��� ���� ���ϴ� �Լ�
int sumNum(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) { //����(char)�� ���� �������� �Ǻ��ϴ� �Լ�
			sum += str[i] - '0'; //char -> int�� �ٲٴ� ��� (�ƽ�Ű �ڵ忡 ���� �˾ƺ�����)
		}
	}
	return sum;
}

//���Լ�
bool cmp(const string &s1, const string &s2) {
	if (s1.size() != s2.size()) { //�� ���ڿ��� ���̰� �ٸ��ٸ� ª�� ���ڿ��� ���� ������
		return s1.size() < s2.size();
	}
	if (sumNum(s1) != sumNum(s2)) { //�� ���ڿ��� ���� ���� �ٸ��ٸ� ���� ���� ���ڿ��� ���� ������
		return sumNum(s1) < sumNum(s2);
	}
	return s1 < s2; //������
}

int main() {
	int n;
	vector<string> serial_num;

	//�Է�
	cin >> n; //�� �� �Է¹����� 
	serial_num.assign(n, "");
	for (int i = 0; i < n; i++) {
		cin >> serial_num[i]; //�迭�� �� �ø��� ��ȣ �Է¹���
	}

	//����
	sort(serial_num.begin(), serial_num.end(), cmp);//cmp��� ���� 

	//���
	for (int i = 0; i < n; i++) {
		cout << serial_num[i] << '\n'; //serial_num ���
	}
	return 0;
}