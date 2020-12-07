#include <iostream>
#include "time.h"
#include "windows.h"
#pragma warning (disable : 4996)

int** dynamic(int SIZE);
void generate(int** mass, int SIZE);
void print(int** mass, int SIZE);
int otojd(int** mass, int SIZE);
void circle_sum(int** mass_A, int** mass_B, int** mass_res, int SIZE);
void dekart_mul(int** mass_A, int** mass_B, int** mass_res, int count, int count_dynamic);
void del(int** mass, int SIZE);
int stag(int** mass, int SIZE);
void unionn(int** mass_A, int** mass_B, int** mass_res, int SIZE);
void cross(int** mass_A, int** mass_B, int** mass_res, int SIZE);



void cross(int** mass_A, int** mass_B, int** mass_res, int SIZE) {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass_res[i][j] = mass_A[i][j] & mass_B[i][j];

		}

	}

}


void unionn(int** mass_A, int** mass_B, int** mass_res, int SIZE) {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass_res[i][j] = mass_A[i][j] | mass_B[i][j];

		}

	}

}

int stag(int** mass, int SIZE) {
	int point_1, point_2;
	printf("\n Введите номера вершин, которые вы хотели бы стянуть (в порядке возрастания) : ");
	scanf("%d%*c%d", &point_1, &point_2);

	if (point_1 > point_2) return SIZE;

	point_1--;
	point_2--;

	if (mass[point_1][point_2] == 0) {

		printf("\n Введенные вершины невозможно отождествить.\n");

		return SIZE;

	}

	for (int i = 0; i < SIZE; i++) {

		if (mass[point_1][i] == 1 || mass[point_2][i] == 1) {

			mass[point_1][i] = 1;
			mass[i][point_1] = 1;

		}

	}
	for (int i = point_2; i < SIZE - 1; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass[i][j] = mass[i + 1][j];

		}

	}

	for (int i = point_2; i < SIZE - 1; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass[j][i] = mass[j][i + 1];

		}

	}
	mass[point_1][point_1] = 0;
	printf(" (в результирующей матрице номера вершин начинная с %d-ой уменьшаются на единицу)\n", point_2 + 2);
	SIZE--;
	return SIZE;
}
void del(int** mass, int SIZE) {
	bool g = true;
	int point_1;
	printf("\n Введите номер вершины, которую вы хотете расщепить: ");
	scanf("%d", &point_1);

	int arr[20];
	for (int i = 0; i < SIZE - 1; i++) {

		arr[i] = mass[i][point_1 - 1];

	}

	for (int i = 0; i < SIZE; i++) {
		mass[SIZE - 1][i] = 0;
		mass[i][SIZE - 1] = 0;

	}
	for (int i = 0; i < SIZE - 1; i++) {

		mass[point_1 - 1][i] = 0;
		mass[i][point_1 - 1] = 0;

	}
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] != 0 && g == true) {
			mass[point_1 - 1][i] = 1;
			mass[i][point_1 - 1] = 1;
			g = false;
		}
		else if (arr[i] != 0) {
			mass[SIZE - 1][i] = 1;
			mass[i][SIZE - 1] = 1;
			g = true;
		}
	}
	mass[SIZE - 1][point_1 - 1] = 1;
	mass[point_1 - 1][SIZE - 1] = 1;
	mass[SIZE - 1][SIZE - 1] = 0;

}

int** dynamic(int SIZE) {

	int** mass;
	mass = (int**)malloc(SIZE * sizeof(int*));
	for (int i = 0; i < SIZE; i++) mass[i] = (int*)malloc(SIZE * sizeof(int));

	return mass;

}

void generate(int** mass, int SIZE) {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			if (j > i) {

				mass[i][j] = rand() % 2;
				mass[j][i] = mass[i][j];

			}

			else if (i == j) mass[i][j] = 0;

		}

	}

}

void print(int** mass, int SIZE) {

	printf(" ");

	for (int k = 1; k <= SIZE; k++) printf(" %d", k);

	printf("\n   -----------\n");

	for (int i = 0; i < SIZE; i++) {

		printf("%d |", i + 1);

		for (int j = 0; j < SIZE; j++) {

			printf("%d ", mass[i][j]);

		}

		printf("\n");

	}

}

int otojd(int** mass, int SIZE) {

	int point_1, point_2;
	printf("\n Введите номера вершин, которые вы хотели бы отождествить (в порядке возрастания) : ");
	scanf("%d%*c%d", &point_1, &point_2);

	if (point_1 > point_2) return SIZE;

	point_1--;
	point_2--;

	if (mass[point_1][point_2] == 0) {

		printf("\n Введенные вершины невозможно отождествить.\n");

		return SIZE;

	}

	//mass[point_1][point_2] = 0;

	//mass[point_2][point_1] = 0;

	for (int i = 0; i < SIZE; i++) {

		if (mass[point_1][i] == 1 || mass[point_2][i] == 1) {

			mass[point_1][i] = 1;
			mass[i][point_1] = 1;

		}

	}

	for (int i = point_2; i < SIZE - 1; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass[i][j] = mass[i + 1][j];

		}

	}

	for (int i = point_2; i < SIZE - 1; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass[j][i] = mass[j][i + 1];

		}

	}

	printf(" (в результирующей матрице номера вершин начинная с %d-ой уменьшаются на единицу)\n", point_2 + 2);
	SIZE--;
	return SIZE;

}

void circle_sum(int** mass_A, int** mass_B, int** mass_res, int SIZE) {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			mass_res[i][j] = mass_A[i][j] ^ mass_B[i][j];

		}

	}

}

void dekart_mul(int** mass_A, int** mass_B, int** mass_res, int count, int count_dynamic) {

	int poryadok_low, poryadok_high;
	int mas_ind1 = 0, mas_ind2 = 0;

	for (int i = 0; i < count * count_dynamic; i++) {

		for (int j = 0; j < count * count_dynamic; j++) {

			mass_res[i][j] = 0;

		}

	}

	if (count > count_dynamic) {

		poryadok_low = count_dynamic;
		poryadok_high = count;

	}

	else {

		poryadok_low = count;

		poryadok_high = count_dynamic;

	}

	for (int i = 0; i < poryadok_high; i++) {

		for (int j = 0; j < poryadok_low; j++) {

			mas_ind2 = 0;

			for (int k = 0; k < poryadok_high; k++) {

				for (int l = 0; l < poryadok_low; l++) {

					//if (k == i && l == j) mass_res[mas_ind1][mas_ind2] = 0;

					//else 
					{

						if (l == j && mass_A[k][i] == 1) {

							mass_res[mas_ind1][mas_ind2] = 1;

						}

						if (k == i && mass_B[l][j] == 1) {

							mass_res[mas_ind1][mas_ind2] = 1;

						}

						//if (k != i && l != j) mass_res[mas_ind1][mas_ind2] = 0;

					}

					mas_ind2++;

				}

			}

			mas_ind1++;

		}

	}

}

int main()

{

	int count, count_dynamic, count_m1, countd = 6;
	int** mass1;
	int** mass2;
	int** mass3;
	int** masss;
	int** mass_res;
	int** mass_res_mul;
	int** mass4;


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	printf("Введите размер массива");
	scanf("%d", &count);
	mass1 = dynamic(count);
	mass2 = dynamic(count);
	masss = dynamic(count);
	mass_res = dynamic(count);
	generate(mass1, count);
	generate(mass2, count);
	printf(" Массив M1:\n\n");
	print(mass1, count);
	printf("\n Массив M2:\n\n");
	print(mass2, count);
	mass4 = dynamic(count + 1);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			mass4[i][j] = mass1[i][j];

		}
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			masss[i][j] = mass1[i][j];

		}
	}

	//A
	count_m1 = otojd(mass1, count);
	printf("\n Массив M1 после операции отождествления:\n\n");
	print(mass1, count_m1);
	//A

	//B
	count_m1 = stag(masss, count);
	printf("\n Результат стягивания вершин:\n\n");
	print(masss, count_m1);
	//B

	//C
	del(mass4, count + 1);
	print(mass4, count + 1);
	printf("\n Результат расщепления вершины:\n\n");
	//rashep
//C

//A2
	printf("\n Массив после операции обЪединения M1 и M2:\n\n");
	unionn(mass1, mass2, mass_res, count);
	print(mass_res, count);
	//A2

	//B2
	printf("\n Массив после операции пересечения M1 и M2:\n\n");
	cross(mass1, mass2, mass_res, count);
	print(mass_res, count);
	//B2


	//C3
	printf("\n Массив после операции кольццевой суммы M1 и M2:\n\n");
	circle_sum(mass1, mass2, mass_res, count);
	print(mass_res, count);
	//C3
	//dekart_mul
	printf("\n Введите порядок массива M3: ");
	scanf("%d", &count_dynamic);
	mass3 = dynamic(count_dynamic);
	generate(mass3, count_dynamic);
	printf("\n Массив M3:\n\n");
	print(mass3, count_dynamic);
	mass_res_mul = dynamic(count * count_dynamic);
	dekart_mul(mass2, mass3, mass_res_mul, count, count_dynamic);
	printf("\n Результат декартового произведения массивов M2 и M3:\n\n");

	for (int i = 0; i < count * count_dynamic; i++) {

		for (int j = 0; j < count * count_dynamic; j++) {

			printf("%d ", mass_res_mul[i][j]);

		}

		printf("\n");

	}
	//dekart_mul
}
