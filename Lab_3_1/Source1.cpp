#include <iostream>
#include <cstdlib>
#include <malloc.h>
using namespace std;

void iden(int** M1, int** M3, int N, int n, int m)
{
	int MAS[100];
	if (n > m) {
		int temp;
		temp = m;
		m = n;
		n = temp;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{

			M3[i][j] = M1[i][j];
		}
	}
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (i != m) {
			MAS[k] = M1[i][m];
			k++;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = m + 1; j < N; j++)
		{
			M3[i][j - 1] = M1[i][j];
		}
	}

	for (int i = m + 1; i < N; i++)
	{
		for (int j = 0; j < m; j++)
		{
			M3[i - 1][j] = M1[i][j];
		}
	}

	for (int i = m + 1; i < N; i++)
	{
		for (int j = m + 1; j < N; j++)
		{
			M3[i - 1][j - 1] = M1[i][j];

		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		if (M3[i][n] == 0) {
			M3[i][n] = MAS[i];
			M3[n][i] = MAS[i];
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		int j = i;
		M3[i][j] = 0;
	}


	cout << endl;
	cout << "    Результат:" << endl;
	cout << endl;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			cout << "  " << M3[i][j];
		}cout << endl;
	}cout << endl; cout << endl;

}


int main()
{
	setlocale(LC_ALL, "Rus");
	int N;
	cout << " Введите размер матриц" << endl;
	cin >> N;

	int** M1; int** M2; int** M3; int** M4;
	int n, m;
	M1 = (int**)malloc(N * sizeof(int));
	M2 = (int**)malloc(N * sizeof(int));
	M3 = (int**)malloc((N - 1) * sizeof(int));
	M4 = (int**)malloc((N + 1) * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
		M2[i] = (int*)malloc(N * sizeof(int));
		if (i < (N - 1))M3[i] = (int*)malloc((N - 1) * sizeof(int));
	}
	for (int i = 0; i < N + 1; i++)
	{
		M4[i] = (int*)malloc((N + 1) * sizeof(int));
	}

	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			M4[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				int t = rand() % 2;
				int t2 = rand() % 2;
				M1[i][j] = t;
				M1[j][i] = t;
				M2[i][j] = t2;
				M2[j][i] = t2;

			}
			else {
				M1[i][j] = 0;
				M1[j][i] = 0;
				M2[i][j] = 0;
				M2[j][i] = 0;

			}
		}
	}
	cout << " Матрица M1:" << endl;
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "  " << M1[i][j];
		}cout << endl;
	}
	cout << endl;
	cout << " 1) Отождествление вершин матрицы M1" << endl;
	cout << "    Введите номера вершин:" << endl;
	cin >> n >> m;
	n--; m--;
	iden(M1, M3, N, n, m);




	cout << " 2) Стягивание ребра матрицы M1:" << endl;
	cout << "    Введите номера вершин:" << endl;
	cin >> n >> m;
	n--; m--;
	while (M1[n][m] != 1)
	{
		cout << "    Введите корректные номера вершин :" << endl;
		cin >> n >> m;
		n--;
		m--;
	}
	iden(M1, M3, N, n, m);



	cout << " 3) Расщепление вершины матрицы M1:" << endl;
	cout << "    Введите номер вершины:" << endl;
	cin >> n;
	n--;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			M4[i][j] = M1[i][j];
		}
	}
	int mas[100][100] = { 0 };
	int K = 0;
	for (int i = 0; i < N; i++)
	{
		if (M1[n][i] == 1)
		{
			mas[K][i] = 1;
			K++;
		}
		M4[n][i] = 0;
		M4[i][n] = 0;
	}
	int T = K;
	T = T / 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < T; j++)
		{
			if (mas[j][i] == 1)
			{
				M4[n][i] = mas[j][i];
				M4[i][n] = mas[j][i];
			}
		}

	}
	for (int i = 0; i < N; i++)
	{
		for (int j = T; j < K; j++)
		{
			if (mas[j][i] == 1)
			{
				M4[N][i] = mas[j][i];
				M4[i][N] = mas[j][i];
			}
		}

	}
	M4[n][N] = 1;
	M4[N][n] = 1;

	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			cout << "  " << M4[i][j];
		}cout << endl;
	}





	int m1[2][100]; int** Mat1; int** Mat2; int** Mat3;  int MAX = 0;
	cout << " 2)  Обьединение/Пересечение матриц Mat1 и Mat2 в матрицу Mat3" << endl;
	cout << "    Введите размер матрицы Mat1" << endl;
	cin >> n;
	cout << "    Введите номера вершин матрицы Mat1 " << endl;
	cout << "    Пример 1 2 3 (количество вершин - равно размеру матрицы) " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> m1[0][i];
		if (m1[0][i] > MAX)MAX = m1[0][i];
	}
	Mat1 = (int**)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		Mat1[i] = (int*)malloc(n * sizeof(int));
	}
	cout << "    Введите размер матрицы Mat2" << endl;
	cin >> m;
	cout << "    Введите номера вершин матрицы Mat2 " << endl;
	cout << "    Пример 4 5 6 (количество вершин - равно размеру матрицы) " << endl;

	for (int i = 0; i < m; i++)
	{
		cin >> m1[1][i];
		if (m1[1][i] > MAX)MAX = m1[1][i];
	}
	Mat2 = (int**)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++)
	{
		Mat2[i] = (int*)malloc(m * sizeof(int));
	}
	Mat3 = (int**)malloc(MAX * sizeof(int));

	for (int i = 0; i < MAX; i++)
	{
		Mat3[i] = (int*)malloc(MAX * sizeof(int));
	}
	cout << endl;


	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i < n && j < n)
			{

				int t2 = rand() % 2;
				Mat1[i][j] = t2;
				Mat1[j][i] = t2;
				if (i == j)Mat1[j][i] = 0;
			}
			if (i < m && j < m)
			{
				int t1 = rand() % 2;
				Mat2[i][j] = t1;
				Mat2[j][i] = t1;
				if (i == j)Mat2[j][i] = 0;
			}
			Mat3[i][j] = 0;
			Mat3[j][i] = 0;
		}
	}
	cout << "   Матрица Mat1:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "  " << Mat1[i][j];
		}cout << endl;
	}
	cout << endl;
	cout << "   Матрица Mat2:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "  " << Mat2[i][j];
		}cout << endl;
	}cout << endl;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t = m1[0][i] - 1;
			Mat3[t][j] = Mat1[i][j];

		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t = m1[1][i] - 1;
			if (Mat3[t][j] == 0)
			{
				Mat3[t][j] = Mat2[i][j];
			}
		}
	}

	cout << "Объединение матриц\n";

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << " " << Mat3[i][j];
		}cout << endl;
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			Mat3[i][j] = 0;
		}cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t = m1[0][i] - 1;
			Mat3[t][j] = Mat1[i][j];

		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t = m1[1][i] - 1;
			if (Mat3[t][j] == 1)
			{
				Mat3[t][j] = Mat2[i][j];
			}
		}
	}
	cout << "Пересечение матриц\n";

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << " " << Mat3[i][j];
		}cout << endl;
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			Mat3[i][j] = 0;
		}cout << endl;
	}
	
	if (n > m) {

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Mat3[i][j] = Mat1[i][j];

				if (j < m && i < m && Mat1[i][j] != Mat2[i][j]) {

					Mat3[i][j] = 1;
				}

				if (j < m && i < m && Mat1[i][j] == Mat2[i][j]) {
					Mat3[i][j] = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Mat3[i][j] = Mat2[i][j];

				if (j < n && i < n && Mat1[i][j] != Mat2[i][j]) {

					Mat3[i][j] = 1;
				}

				if (j < n && i < n && Mat1[i][j] == Mat2[i][j]) {
					Mat3[i][j] = 0;
				}
			}
		}
	}
	cout << "Кольцевая сумма\n";

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << " " << Mat3[i][j];
		}cout << endl;
	}
	return 0;
}

