#include<stdio.h>
int Main_Num(int A[], int n) {
	int candidate = -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			candidate = A[i];
			count = 1;
		}
		else if (A[i] == candidate) {
			count++;
		}
		else count--;
	} //筛选主元素的可能候选者
	count = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == candidate)count++;
	}
	if (count > n / 2)return candidate;
	else return -1;
}
int main() {
	int A[] = { 0,5,5,3,5,1,5,7 };
	printf("%d\n", Main_Num(A, 8));
}