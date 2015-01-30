#include "MCh1.h"

using namespace std;

int main()
{
	//Test of initialazing by vector of vectors(2,3)
	vector<vector<double>> sampleVofV(2);
	for (int i = 0; i < 2; ++i)
	{
		sampleVofV[i].resize(3);
	}
	sampleVofV = { {0,1,2}, {3,4,5}};
	Matrix byVector(sampleVofV);

	//Test of initialazing by obj(2,3)
	Matrix byObj(byVector);

	//Test of operator =
	sampleVofV[0][0] = 9;
	sampleVofV[1][2] = 9;
	byObj = *(new Matrix(sampleVofV));
	byVector = byObj;

	//Test of operator +=
	byObj += byVector;

	//Test of operator -=
	byObj -= byVector;

	//Test of operator *=
	vector<vector<double>> toMultiply(3);
	for (int i = 0; i < toMultiply.size(); ++i)
	{
		toMultiply[i].resize(2);
	}
	toMultiply = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	Matrix toMultiplyMatrix(toMultiply);
	byObj *= toMultiply;
	//Test of transposition
	byObj.transposition();

}