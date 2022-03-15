#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * ver1. set�� �̿��� Ǯ���Դϴ�.
 * ������ �� �ʿ䰡 ����, ���԰� �˻��� �Ͼ�� �����Դϴ�.
 * �Է��� ���� �ִ� 1,000,000���� ���԰� Ž���� ���� �Ͼ�ϴ�.
 * ����, O(log N)�� set�� �ƴ϶� O(1)�� unordered_set�� ����ؼ� Ǯ��� �մϴ�.
 * */

int main() {
	// ����� ó�� �ӵ� ����� ���� �ڵ�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է�
	int t; 
	cin >> t; //t�� �Է� �޴´�
	while (t--) {
		int n, m, input;
		unordered_set<int> note1;

		// ��ø1�� �ش�Ǵ� ���ҵ��� unordered_set�� ����
		cin >> n; //n�� �Է� �޴´�
		while (n--) {
			cin >> input; // input�� �Է� �޴´�
			note1.insert(input); //��ø1�� �ش�Ǵ� ���ҵ��� unordered_set�� ����
		}
		cin >> m; //m�� �Է� �޴´�
		while (m--) {
			cin >> input; //input�� �Է� �޴´�
			// �ݺ��ڸ� �̿��ؼ� ���Ұ� �¿� ���ԵǾ� �ִ��� Ȯ��
			auto iter = note1.find(input);
			if (iter == note1.end()) { //iter=note1.end()�̸� 0�� ���
				cout << "0\n";
			}
			else { //iter=note1.end()�� �ƴϸ� 1�� ���
				cout << "1\n";
			}
		}
	}
	return 0;
}