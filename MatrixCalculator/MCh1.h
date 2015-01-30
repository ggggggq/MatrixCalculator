#ifndef Matrix_CALCULATOR_20141205
#define Matrix_CALCULATOR_20141205

#include <iosfwd>
#include <vector>

class Matrix
{
public:
	Matrix(const std::vector<std::vector<double>> obj);
	Matrix(const Matrix& obj);
	~Matrix();
	Matrix& operator = (const Matrix& obj);
	Matrix& operator += (const Matrix& obj);
	Matrix& operator -= (const Matrix& obj);
	Matrix& operator *= (const Matrix& obj);
	
	void transposition();

private:
	int m_height; //N, количество строк
	int m_length; //M, количество столбцов
	std::vector<std::vector<double>> m_vectorOfVectors;
};
Matrix operator + (const Matrix& lhs, const Matrix& rhs);
Matrix operator - (const Matrix& lhs, const Matrix& rhs);
Matrix operator * (const Matrix& lhs, const Matrix& rhs);
#endif