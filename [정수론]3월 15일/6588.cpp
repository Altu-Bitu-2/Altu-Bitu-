#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1e6;

//�����佺�׳׽��� ü, �̸� SIZE������ �Ҽ� �Ǵ�
vector<bool> isPrime() {
	vector<bool> is_prime(SIZE + 1, true); //�Ҽ� �Ǵ� ���� ����

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= SIZE; i++) {
		if (!is_prime[i]) { //�Ҽ��� �ƴ϶��
			continue;
		}
		//i�� �Ҽ����
		for (int j = i * i; j <= SIZE; j += i) {
			is_prime[j] = false; //i�� ��� ����
		}
	}
	return is_prime;
}

//�������� ���� �Ǵ� �Լ�
int checkGoldbach(int n, vector<bool> &is_prime) {
	for (int i = 3; i <= n / 2; i += 2) { //Ȧ���� �˻�, n/2 �̻��� ���� ������ n-i�� ���� �˻�ǹǷ� n/2���� �˻�
		if (is_prime[i] && is_prime[n - i]) { //�� Ȧ�� ��� �Ҽ���� (�������� ������ ���� ���)
			return i; //�� Ȧ�� �Ҽ� �� ���� �� ����
		}
	}
	return 0; //�������� ������ Ʋ�� ���
}

/**
 * "�������� ����"
 * 4���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� �ִ�. -> �̸� �����ϴ� ����
 * -> �����佺�׳׽��� ü�� Ȱ���Ͽ� �̸� SIZE ������ �Ҽ� �Ǻ�
 * -> �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� �ִ��� �Ǵ�
 */

int main() {
	//����� �ӵ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<bool> is_prime = isPrime(); //�Ҽ� �Ǵ� ���� ����

	while (true) {
		//�Է�
		cin >> n;
		if (n == 0)
			break;

		//����
		int prime = checkGoldbach(n, is_prime); //�������� ������ �´��� üũ
		if (prime) //�´ٸ� -> �� Ȧ�� �Ҽ� �� ���� �� ���Ϲ��� ���
			cout << n << " = " << prime << " + " << n - prime << '\n';
		else //Ʋ���ٸ� -> 0 ���Ϲ��� ���
			cout << "Goldbach's conjecture is wrong.\n";

	}

	return 0;
}