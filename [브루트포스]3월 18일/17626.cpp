#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMinNumber(int n, int num_size, vector<int> &square_num) {
	if (square_num[num_size - 1] == n) { //1���� ���� �� ���� ��� �ٷ� ����
		return 1;
	}
	for (int i = num_size - 1; i >= 0; i--) { //2���� ���� �� �ִ� ��� �˻�
		for (int j = num_size - 1; j >= 0; j--) { 
			if (square_num[i] + square_num[j] == n) { //���� i�� ���� j�� ���� ���� n�̸�
				return 2; //����
			}
		}
	}
	for (int i = num_size - 1; i >= 0; i--) { //3���� ���� �� �ִ� ��� �˻�
		for (int j = num_size - 1; j >= 0; j--) {
			for (int k = num_size - 1; k >= 0; k--) {
				if (square_num[i] + square_num[j] + square_num[k] == n) { //���� i�� ���� j�� ���� k�� ���� ���� n�̸�
					return 3; //����
				}
			}
		}
	}
	return 4;
}

/**
 * [Four Squares] - ���Ʈ���� Ǯ�� (8ms)
 * �ڿ��� n�� ���� �ּ� ��� �������� ������ ǥ���� �� �ִ��� ã�� ����
 * �̸� �ִ񰪱����� �������� ���س���, ����Ž��
 *
 * 1 ~ 3�� �������� �Ұ����� ���, ���� ������ 4�� �ȴ� -> 4���� ���� �õ��غ��� �ʾƵ� �ȴ�.
 *
 * sqrt(50000) = �� 223
 * ��ü ���� ��  < 223^2 + 223^3 = 11139296 <1�� -> ���Ʈ���� ����
 */

int main() {
	int n, num_size;
	vector<int> square_num; //���� ����

	//�Է�
	cin >> n; //n�Է�

	//����
	for (int i = 1; i <= sqrt(n); i++) { //�̸� ��Ʈ n ������ ������ ����
		square_num.push_back(i * i); 
	}
	num_size = square_num.size(); //������ ����

	//���
	cout << findMinNumber(n, num_size, square_num);
	return 0;
}