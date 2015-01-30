#include "MCh1.h"
#include <vector>

Matrix::Matrix(const std::vector<std::vector<double>> obj)
{
	this->m_height = obj.size();
	this->m_length = obj[0].size();
	this->m_vectorOfVectors.resize(obj.size());
	for (int i = 0; i < obj.size(); ++i)
	{
		this->m_vectorOfVectors[i].resize(obj[i].size());
	}
	for (int i = 0; i < obj.size(); ++i)
	{
		for (int j = 0; j < obj[i].size(); ++j)
		{
			this->m_vectorOfVectors[i][j] = obj[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& obj)
{
	m_height = obj.m_height;
	m_length = obj.m_length;
	m_vectorOfVectors.resize(obj.m_vectorOfVectors.size());
	for (int i = 0; i < m_vectorOfVectors.size(); ++i)
	{
		m_vectorOfVectors[i].resize(obj.m_vectorOfVectors[i].size());
	}
	for (int i = 0; i < m_vectorOfVectors.size(); ++i)
	{
		for (int j = 0; j < m_vectorOfVectors[i].size(); ++j)
		{
			m_vectorOfVectors[i][j] = obj.m_vectorOfVectors[i][j];
		}
	}
}

Matrix::~Matrix()
{

}

Matrix&
Matrix::operator = (const Matrix& obj)
{
	m_height = obj.m_height;
	m_length = obj.m_length;
	m_vectorOfVectors.resize(obj.m_vectorOfVectors.size());
	for (int i = 0; i < m_vectorOfVectors.size(); ++i)
	{
		m_vectorOfVectors[i].resize(obj.m_vectorOfVectors[i].size());
	}
	for (int i = 0; i < m_vectorOfVectors.size(); ++i)
	{
		for (int j = 0; j < m_vectorOfVectors[i].size(); ++j)
		{
			m_vectorOfVectors[i][j] = obj.m_vectorOfVectors[i][j];
		}
	}

	return *this;
}

Matrix&
Matrix::operator += (const Matrix& obj)
{
	if (obj.m_height <= m_height && obj.m_length <= m_length)
	{
		for (int i = 0; i < obj.m_height; ++i)
		{
			for (int j = 0; j < obj.m_length; ++j)
			{
				m_vectorOfVectors[i][j] += obj.m_vectorOfVectors[i][j];
			}
		}
	}

	return *this;
}

Matrix&
Matrix::operator -= (const Matrix& obj)
{
	if (obj.m_height <= m_height && obj.m_length <= m_length)
	{
		for (int i = 0; i < obj.m_height; ++i)
		{
			for (int j = 0; j < obj.m_length; ++j)
			{
				m_vectorOfVectors[i][j] -= obj.m_vectorOfVectors[i][j];
			}
		}
	}

	return *this;
}

Matrix&
Matrix::operator *= (const Matrix& obj)
{
	if (m_length == obj.m_height)
	{
		int vec1_counter1(0);
		int vec1_counter2(0);
		std::vector<std::vector<double>>vec1;
		vec1.resize(m_height);
		for (int i = 0; i < m_height; ++i)
		{
			vec1[i].resize(obj.m_length);
		}
		for (int i = 0; i < m_height; ++i)
		{
			for (int g = 0; g < obj.m_length; ++g)
			{
				for (int j = 0; j < m_length; ++j)
				{
					vec1[vec1_counter1][vec1_counter2] += m_vectorOfVectors[i][j] * obj.m_vectorOfVectors[j][g];
				}
				vec1_counter2++;
				if (vec1_counter2 >= obj.m_length)
				{
					vec1_counter2 = 0;
					vec1_counter1++;
				}
			}
		}
		m_length = obj.m_length;
		for (int i = 0; i < m_height; ++i)
		{
			m_vectorOfVectors[i].resize(m_length);
		}
		for (int i = 0; i < m_height; ++i)
		{
			for (int g = 0; g < m_length; ++g)
			{
				m_vectorOfVectors[i][g] = vec1[i][g];
			}
		}
	}

	return *this;
}

void
Matrix::transposition()
{
	std::swap(m_length, m_height);
	std::vector<std::vector<double>> tempVectorForTransposition(m_height);
	for (int i = 0; i < m_height; ++i)
	{
		tempVectorForTransposition[i].resize(m_length);
	}
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_length; ++j)
		{
			tempVectorForTransposition[i][j] = m_vectorOfVectors[j][i];
		}
	}
	m_vectorOfVectors = tempVectorForTransposition;
}

Matrix 
operator + (const Matrix& lhs, const Matrix& rhs)
{
	Matrix sample(lhs);
	sample += rhs;

	return sample;
}

Matrix
operator - (const Matrix& lhs, const Matrix& rhs)
{
	Matrix sample(lhs);
	sample -= rhs;

	return sample;
}

Matrix
operator * (const Matrix& lhs, const Matrix& rhs)
{
	Matrix sample(lhs);
	sample *= rhs;

	return sample;
}

