#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define vec 3
int main() {
	int multi = 0, rang = 0;
	int a_c = 0, b_c = 0, c_c = 0;
	int* a = (int*)malloc(vec * sizeof(int));
	int* b = (int*)malloc(vec * sizeof(int));
	int* c = (int*)malloc(vec * sizeof(int));
	//ввод
	printf(" input your vector a (x y z) :\n");
	scanf_s("%d %d %d", &a[0],&a[1],&a[2]);
	printf(" input your vector ab (x y z) :\n");
	scanf_s("%d %d %d", &b[0], &b[1], &b[2]);
	printf("input your vector c (x y z) :\n");
	scanf_s("%d %d %d", &c[0], &c[1], &c[2]);
	//компланарность
	multi = a[0] * b[1] * c[2] + a[2] * b[0] * c[1] + a[1] * b[2] * c[0] - a[2] * b[1] * c[0] - a[1] * b[0] * c[2] - a[0] * b[2] * c[1];
	if (multi == 0) {
		printf("YES, kompl\n");
	}
	else printf("NO kompl\n");
	//коллинеарность
	if (((a[1] * b[2] - a[2] * b[1]) == 0) && ((a[0] * b[2] - a[2] * b[0]) ==0) && ((a[0] * b[1] - a[1] * b[0]) ==0)) {
		printf("VEC A, B - collinearn\n");
		a_c = 1;
	}
	if (((a[1] * c[2] - a[2] * c[1]) == 0) && ((a[0] * c[2] - a[2] * c[0]) == 0) && ((a[0] * c[1] - a[1] * c[0]) ==0)) {
		printf("VEC A, C - collinearn\n");
		b_c = 1;
	}
	if (((b[1] * c[2] - b[2] * c[1]) == 0) && ((b[0] * c[2] - b[2] * c[0]) == 0) && ((b[0] * c[1] - b[1] * c[0]) == 0)) {
		printf("VEC B, C - collinearn\n");
		c_c = 1;
	}
	// поиск ранга системы
	rang = a_c + b_c + c_c;
	if (rang == 3) {
		printf("Rang = 1\n");
	}
	if (rang == 2) {
		printf("Rang = 2\n");
	}
	if (rang == 0) {
		printf("Rang = 3\n");
	}
	if (a[0] ==0 && a[1] ==0 && a[2] == 0 &&  b[0] ==0 &&  b[1] == 0 && b[2] == 0 &&  c[0] == 0 && c[1] == 0 && c[2] == 0) {
		printf("Rang = 0\n");
	}
	return 0;
}
