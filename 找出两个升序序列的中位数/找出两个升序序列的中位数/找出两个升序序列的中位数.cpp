#include<stdio.h>
#include<stdlib.h>
int M_Search(int A[], int B[], int n) {  //传入两个一样长的升序序列和他们的长度n
	int s1, d1, m1, s2, d2, m2;
	s1 = 0; d1 = n - 1;
	s2 = 0; d2 = n - 1;
	while (s1 != d1 && s2 != d2) {
		m1 = (s1 + d1) / 2; //分别取A和B各自的中位数
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2]) {
			return A[m1];
		}
		if (A[m1] < B[m2]) {
			if ((d1-s1+1) % 2 == 0) { //如果序列长度为偶数
				s1 = m1 + 1; //删除A中小于中位数的前半部分，和B中大于中位数的后半部分
				d2 = m2; //且要求删除的长度相等
			}
			else {
				s1 = m1;
				d2 = m2;
			}
		}
		if (A[m1] > B[m2]) {
			if ((d1-s1+1) % 2 == 0) { //如果序列长度为偶数
				s2 = m2 + 1; //删除B中小于中位数的前半部分，和A中大于中位数的后半部分
				d1 = m1; //且要求删除的长度相等
			}
			else {
				s2 = m2;
				d1 = m1;
			}
		}
	}
	return (A[s1] < B[s2]) ? A[s1] : B[s2];
}

int main()
{
	int A[] = { 11,13,15,17,19 };
	int B[] = { 2,4,6,8,20 };
	int n = 5;
	printf("%d\n", M_Search(A, B, n));
	system("pause");
	return 0;
}