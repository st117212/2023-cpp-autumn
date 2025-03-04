//������� 3. ����� Matrix

#include<iostream>
#include<vector>

class Matrix
{
private:
	std::vector <std::vector<double>> a;
public:
	int row() const; // ����� �����
	int col() const; // ����� ��������
	Matrix() : a() {};
	Matrix(int n, int m) // ����������� 
	{
		a.clear();
		a.resize(n, std::vector<double>(m, 0.0)); // ����������� ������ ������ ��������
	}
	// n - ����� �����, m - ����� ��������

	double& operator () (int i, int j);
	// ��������� � �������� �������
	// (������������� �������� ������ �������)
	const double& operator () (int i, int j) const;
	// ��� ����������� ��������

	Matrix(const Matrix&) = default;
	// ����������� �����������
	// ���������� ������ ���, ������ �� ����������� ���� �
	Matrix& operator=(const Matrix&) = default;
	// ������������ ������
	// ���������� ������ ���, ������ �� ������������ ���� �

	~Matrix() = default; // ����������
	// ���������� ������ ���, ������ �� ����������� ���� �

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
	int col_m1 = m1.col(); // ���������� �������� � m1 � ����� � m2

	Matrix c(row_c, col_c); // ������� ��������: (���-�� ����� � m1)x(���-�� �������� � m2)

	for (int i = 0; i < row_c; ++i) // ������� �� i-������ m1
	{
		for (int j = 0; j < col_c; ++j) // ������� �� j-������� m2
		{
			double sum = 0.0;
			for (int k = 0; k < col_m1; ++k)
			{
				sum += m1(i, k) * m2(k, j);  // ���������� �� ��-��� i-������ � j-�������
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
			c(i, j) = m1(i, j); // ������ �������� m1
		}
	}

	for (int i = 0; i < rows2; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			c(i + rows1, j) = m2(i, j); // �������� m2 � �������� row1
		}
	}

	return c;
}

std::istream& operator>>(std::istream& in, Matrix& m)
{
	std::cout << "������� ���������� ����� � �������� �������: " << std::endl;
	int row = 0;
	int col = 0;
	std::cin >> row >> col;
	// �������� �� ������������ ��������
	if (row <= 0 || col <= 0)
	{
		exit(1);
	}

	m = Matrix(row, col); // ������� ������� ������� �������
	std::cout << "������� �������� �������: " << std::endl;
	// ������ �������� �������
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

