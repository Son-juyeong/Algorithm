#include<stdio.h>

void sort(int a[], int n){
	int i, tmp=0, k=0;
	for (i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) {
			tmp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = tmp;
			k++;
		}
	}
	if (k)
		sort(a, n - 1);
}

int main() {
	int n, num=0, i;
	int A[50];
	int B[50];
	int preT[50];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &A[i], &B[i]);
		if (n %2!=0) {
			printf("1");
			return 0;
		}
		preT[i] = B[i] - A[i];
	}

	sort(preT, n);

	num = preT[n / 2] - preT[n / 2 - 1] + 1;
	if (num < 0)
		num = -num;

	printf("%d", num);

	return 0;
}