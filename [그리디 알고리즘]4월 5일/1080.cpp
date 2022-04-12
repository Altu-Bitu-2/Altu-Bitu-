#include <iostream>
#include <vector>

using namespace std;

//�κ� ��� ���� ������ �Լ�
void reverseMtx(int row, int col, vector<string> &matrix_a) {
	for (int i = row; i < row + 3; i++) { // ���� ����� 3��°����
		for (int j = col; j < col + 3; j++) { //3��° ������
			if (matrix_a[i][j] == '1') { //1�̸�
				matrix_a[i][j] = '0'; //0���� �ٲٱ�
			}
			else { //0�̸�
				matrix_a[i][j] = '1'; //1�� �ٲٱ�
			}
		}
	}
}

//���������� A == B���� Ȯ���ϴ� �Լ�
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix_a[i][j] != matrix_b[i][j]) { //���� ������ �����
				return false; //false�� ����
			}
		}
	}
	return true; //��� ������ true ����
}

/**
 * [���]
 *
 * (0, 0) �ε������� �κ������ ���� �� �ִ� ������ �ε������� �˻��ϸ� �׸����ϰ� Ǫ�� ����
 * A, B ����� ���� �ε��� ���� ���� �ٸ��ٸ� A ��Ŀ��� ���� �ε����� '����'�ϴ� 3x3 ũ�⸸ŭ�� �κ� ��� ���� ������
 * �˻簡 ��� ���� ��, A�� B�� ���� �ٸ��ٸ� �ٲ� �� ���� �����
 * !����! �Է��� ������� �־����Ƿ� string���� ����
 */

int main() {
	int n, m;

	//�Է�
	cin >> n >> m; //���ũ�� �Է� ����
	vector<string> matrix_a(n); //���A
	vector<string> matrix_b(n); //���B
	for (int i = 0; i < n; i++) {
		cin >> matrix_a[i]; //���A �Է� ����
	}

	for (int i = 0; i < n; i++) {
		cin >> matrix_b[i]; //���B �Է� ����
	}

	//����
	int ans = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)���Ұ� ���� �ٸ��ٸ�
				reverseMtx(i, j, matrix_a); //a���� �ٲٱ�
				ans++; //ans �� ���ϱ�
			}
		}
	}

	//���
	if (!isPossible(n, m, matrix_a, matrix_b)) { //���� ������
		ans = -1; //ans = -1
	}
	cout << ans;
	return 0;
}