#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

void shell(int* items, int count) {
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; i++) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}


void qs(int* items, int left, int right) {
	int i, j, x, y;
	i = left; j = right;
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
int compare(const void* x1, const void* x2) {
	return(*(int*)x1 - *(int*)x2);
}


int main() {
	time_t end, start;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int n = 0;
	printf("Введите количество эл массива:");
	scanf_s("%d", &n);
	int* c = (int*)calloc(sizeof(int), n);
	int* d = (int*)calloc(sizeof(int), n);
	int* k = (int*)calloc(sizeof(int), n);

	printf("\nВремя сортировки : \n");
	printf("Массив случайных значений:\n");
	for (int i = 0; i < n; i++) {
		c[i] = rand() % 100 - 50;
		d[i] = rand() % 100 - 50;
		k[i] = rand() % 100 - 50;
	}
	start = clock();
	qsort(k, n, sizeof(int), compare);
	end = clock();
	double def = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм стандартной сортировки:%lf\n", def);

	start = clock();
	shell(c, n);
	end = clock();
	double dif = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм Шелла:%lf\n", dif);

	start = clock();
	qs(d, 0, (n - 1));
	end = clock();
	double dif1 = (double)(end - start) / (CLOCKS_PER_SEC);
	printf("Алгоритм быстрой сортировки:%lf\n", dif1);
	printf("\n---------------------------------------------------------\n");
	printf("Массив возрастающий:\n");
	for (int i = 0; i < n; i++) {
		k[i] = i + 21;
	}
	start = clock();
	qsort(k, n, sizeof(int), compare);
	end = clock();
	double def1 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм стандартной сортировки:%lf\n", def1);

	for (int i = 0; i < n; i++) {
		c[i] = i + 21;
	}
	start = clock();
	shell(c, n);
	end = clock();
	double dif2 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм Шелла:%lf\n", dif2);

	for (int i = 0; i < n; i++) {
		d[i] = i + 21;
	}
	start = clock();
	qs(d, 0, (n - 1));
	end = clock();
	double dif3 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм быстрой сортировки:%lf\n", dif3);
	printf("\n---------------------------------------------------------\n");
	printf("Массив убывающий:\n");
	for (int i = 0; i < n; i++) {
		k[i] = n - i;
	}
	start = clock();
	qsort(k, n, sizeof(int), compare);
	end = clock();
	double def2 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм стандартной сортировки:%lf\n", def2);

	for (int i = 0; i < n; i++) {
		c[i] = n - i;
	}

	start = clock();
	shell(c, n);
	end = clock();
	double dift = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм Шелла:%lf\n", dift);

	for (int i = 0; i < n; i++) {
		d[i] = n - i;
	}
	start = clock();
	qs(d, 0, (n - 1));
	end = clock();
	double dift1 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм быстрой сортировки:%lf\n", dift1);
	printf("\n---------------------------------------------------------\n");
	printf("Массив на половину возрастающий на половину убывающий:\n");
	for (int i = 0; i < n; i++) {
		if (i < (n / 2))
			k[i] = i + 21;
		else
			k[i] = i - 12;
	}
	start = clock();
	qsort(k, n, sizeof(int), compare);
	end = clock();
	double def3 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм стандартной сортировки:%lf\n", def3);

	for (int i = 0; i < n; i++) {
		if (i < (n / 2))
			c[i] = i + 21;
		else
			c[i] = i - 12;
	}
	start = clock();
	shell(c, n);
	end = clock();
	double dift2 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм Шелла:%lf\n", dift2);

	for (int i = 0; i < n; i++) {
		if (i < (n / 2))
			d[i] = i + 21;
		else
			d[i] = i - 12;
	}
	start = clock();
	qs(d, 0, (n - 1));
	end = clock();
	double dift3 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Алгоритм быстрой сортировки:%lf\n", dift3);
	free(c);
	free(d);
	free(k);
	_getch();
}
