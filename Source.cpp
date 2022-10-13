#include <iostream>
#include <fstream>

using namespace std;

int** read_array(string path)
{
	ifstream fin;
	fin.open(path);
	int row, col = 0;
	fin >> row >> col;
	if (!fin || row == 0 || col == 0)
	{
		cout << "Bad file" << endl;
	}

	int** A = new int* [row];
	for (int i = 0; i < row; i++)
	{
		A[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fin >> A[i][j];
		}
	}
	fin.close();
	return A;
}

int* size_arr(string path)
{
	ifstream fin;
	fin.open(path);
	int n, m = 0;
	fin >> n >> m;
	fin.close();
	int A[] = { n,m };
	return A;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int** A = read_array("D:\\1.txt");
	int** B = read_array("D:\\2.txt");
	int* Size_A = size_arr("D:\\1.txt");
	int row1 = Size_A[0];
	int col1 = Size_A[1];
	int* Size_B = size_arr("D:\\2.txt");
	int row2 = Size_B[0];
	int col2 = Size_B[1];

	if (col1 != row2)
	{
		cout << " Умножение невозможно! ";
		cin.get();
		return 0;
	}


	clock_t start;
	start = clock();
	int** C = new int* [row1];
	for (int i = 0; i < row1; i++)
	{
		C[i] = new int[col2];
	}
	for (int i = 0; i < col2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < col1; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	cout << "Время: " << double(clock() - start / CLOCKS_PER_SEC) << "мс" << endl;

	ofstream fout;
	fout.open("D:\\res.txt");
	if (fout.is_open())
	{
		fout << "Время: " << double(clock() - start / CLOCKS_PER_SEC) << "мс" << "\n" << "Размер результирующей матрицы: [" << row1 << "," << col2 << "]" << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				fout << C[i][j] << " ";
			}
			fout << "\n";
		}
	}
	fout.close();

	return 0;
}