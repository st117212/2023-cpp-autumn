//Задание 3. Класс Matrix

#include<iostream>
#include<vector>

class Matrix
{
private:
	std::vector <std::vector<double>> a;
public:
	int row() const; // число строк
	int col() const; // число столбцов
	Matrix() : a() {};
	Matrix(int n, int m) // конструктор 
	{
		a.clear();
		a.resize(n, std::vector<double>(m, 0.0)); // пересоздает массив нужных размеров
	}
	// n - число строк, m - число столбцов

	double& operator () (int i, int j);
	// обращение к элементу матрицы
	// (перегруженная операция вызова функции)
	const double& operator () (int i, int j) const;
	// для константных объектов

	Matrix(const Matrix&) = default;
	// конструктор копирования
	// компилятор строит сам, исходя из копирования поля а
	Matrix& operator=(const Matrix&) = default;
	// присваивание матриц
	// компилятор строит сам, исходя из присваивания поля а

	~Matrix() = default; // деструктор
	// компилятор строит сам, исходя из деструктора поля а

	friend Matrix operator*(const Matrix& m1, const Matrix& m2);
	friend Matrix operator&(const Matrix& m1, const Matrix& m2);
	friend std::istream& operator>>(std::istream& in, Matrix& m);
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix B;
	std::cin >> B;

	int n = 3;
	Matrix A(n, n);

	A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
	A(1, 0) = 0; A(1, 1) = 1; A(1, 2) = 4;
	A(2, 0) = 0; A(2, 1) = 0; A(2, 2) = 1;

	Matrix C = A & B;


	for (int i = 0; i < C.row(); i++)
	{
		for (int j = 0; j < C.col(); j++)
		{
			std::cout << C(i, j) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}

int Matrix::row() const
{
	return a.size();
}

int Matrix::col() const
{
	if (a.empty())
	{
		return 0;
	}

	return a[0].size();
}

double& Matrix::operator()(int i, int j)
{
	if (i < 0 || i >= a.size() || j < 0 || j >= a[i].size())
	{
		throw std::out_of_range("Index out of bounds");
	}

	return a[i][j];
}

const double& Matrix::operator()(int i, int j) const
{
	if (i < 0 || i >= a.size() || j < 0 || j >= a[i].size())
	{
		exit(1);
	}

	return a[i][j];
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	if (m1.col() != m2.row())
	{
		exit(1);
	}

	int row_c = m1.row();
	int col_c = m2.col();
	int col_m1 = m1.col(); // Количество столбцов в m1 и строк в m2

	Matrix c(row_c, col_c); // Матрица размером: (кол-во строк в m1)x(кол-во столбцов в m2)

	for (int i = 0; i < row_c; ++i) // Смотрим на i-строку m1
	{
		for (int j = 0; j < col_c; ++j) // Смотрим на j-столбец m2
		{
			double sum = 0.0;
			for (int k = 0; k < col_m1; ++k)
			{
				sum += m1(i, k) * m2(k, j);  // проходимся по эл-там i-строки и j-столбца
			}

			c(i, j) = sum;
		}
	}

	return c;
}

Matrix operator&(const Matrix& m1, const Matrix& m2)
{
	if (m1.col() != m2.col())
	{
		exit(1);
	}

	int rows1 = m1.row();
	int rows2 = m2.row();
	int cols = m1.col();

	Matrix c(rows1 + rows2, cols);

	for (int i = 0; i < rows1; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			c(i, j) = m1(i, j); // просто копируем m1
		}
	}

	for (int i = 0; i < rows2; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			c(i + rows1, j) = m2(i, j); // копируем m2 с отступом row1
		}
	}

	return c;
}

std::istream& operator>>(std::istream& in, Matrix& m)
{
	std::cout << "Введите количество строк и столбцов матрицы: " << std::endl;
	int row = 0;
	int col = 0;
	std::cin >> row >> col;
	// Проверка на корректность размеров
	if (row <= 0 || col <= 0)
	{
		exit(1);
	}

	m = Matrix(row, col); // Создаем матрицу нужного размера
	std::cout << "Введите элементы матрицы: " << std::endl;
	// Читаем элементы матрицы
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			double value = 0.0;
			std::cin >> value;

			m(i, j) = value;
		}
	}
	std::cout << std::endl;

	return in;
}

