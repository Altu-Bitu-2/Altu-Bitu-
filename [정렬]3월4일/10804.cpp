#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void change(int arr[], int a, int b) {
	while (true) {
		swap(arr[a], arr[b]);
		if (b - a == 0 || b - a == 1)
			break;
		a++;
		b--;
	}
}//��ȯ����

int main() {
	int arr[21];
	int start, end;

	for (int i = 1; i < 21; i++) {
		arr[i] = i;
	}
	//�Է¹���
	for (int i = 0; i < 10; i++) {
		cin >> start >> end;
		change(arr, start, end);
	}
	//���
	for (int i = 1; i < 21; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
