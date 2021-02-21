#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	int x = 3; int y = 1;
	int *p = &x;
	int *q = &y;
	int a[3] = {2, 4, 6};
	printf("memory of x: %d | memory of y: %d \n",(int) &x, (int) &y);
	printf("memory of *p: %d | memmory of *q: %d \n", (int) &p,(int) &q);
	printf("memory of array: %d %d %d \n", (int) &a[0], (int) &a[1], (int) &a[2]);

	*p -= 1;
	p--;
	*p += 3;
	printf("p: %d x: %d y: %d \n", (int)p, x, y);

	q = &a[2];
	printf("q: %d \n", (int) q);
	*q = 5;
	p = q--;
	printf("p: %d q: %d a[2]: %d\n", (int) p, (int) q, a[2]);

	*p = 8;
	*q = 7;
	printf("a[0]: %d a[1]: %d a[2]: %d \n", a[0], a[1], a[2]);
}