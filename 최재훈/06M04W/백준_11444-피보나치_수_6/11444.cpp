#include <iostream>
#include <vector>

using namespace std;

// global
typedef long long VERYLONG;
typedef vector<vector<VERYLONG>> MATRIX;

const VERYLONG N_MAX = 1000000000000000000;
const VERYLONG MODULER = 1000000007;

MATRIX A_Matrix;

// method
MATRIX CalcPibo(MATRIX& src, VERYLONG exp);
MATRIX MultiMatrix(MATRIX& lhs, MATRIX& rhs);

int main()
{
	/*
	* ref : https://st-lab.tistory.com/252
	* [ F_n+2 ] = [ 1  1 ] [ F_n+1 ]
	* [ F_n+1 ] = [ 1  0 ] [ F_n   ]
	*/

	// init
	std::ios::sync_with_stdio(false);

	vector<VERYLONG> aRow = { 1, 1 };
	A_Matrix.push_back(aRow);
	aRow = { 1, 0 };
	A_Matrix.push_back(aRow);

	// input
	VERYLONG n = 0;
	(void)scanf("%lld", &n);

	if (0 == n)
	{
		printf("0\n");
		return 0;
	}
	else if (1 == n)
	{
		printf("1\n");
		return 0;
	}

	// calc
	MATRIX answer = CalcPibo(A_Matrix, n-1);

	// print
	printf("%lld\n", answer[0][0]);

	return 0;
}

MATRIX CalcPibo(MATRIX& src, VERYLONG exp)
{
	if (1 == exp)
		return src;

	MATRIX calcResult = CalcPibo(src, exp / 2);
	if (0 != exp % 2)
	{
		calcResult = MultiMatrix(calcResult, calcResult);
		calcResult = MultiMatrix(calcResult, A_Matrix);

		return calcResult;
	}

	calcResult = MultiMatrix(calcResult, calcResult);

	return calcResult;
}

MATRIX MultiMatrix(MATRIX& lhs, MATRIX& rhs)
{
	MATRIX retValue;

	const int matrixSize = lhs.size();
	for (int row = 0; row < matrixSize; row++)
	{
		vector<VERYLONG> rowList;
		
		for (int col = 0; col < matrixSize; col++)
		{
			VERYLONG data = 0;

			auto& lhsRow = lhs[row];
			int rhsRow = 0;
			
			for (auto& lhsVal : lhsRow)
			{
				data += (lhsVal * rhs[rhsRow][col]);
				rhsRow++;
				if (matrixSize <= rhsRow)
					rhsRow = 0;
			}
			data %= MODULER;
			rowList.push_back(data);
		}

		retValue.push_back(rowList);
	}

	return retValue;
}

/*
*
A^1 = [ 1, 1 ]
      [ 1, 0 ]
	  

A^2 = [ 1 1 ] [ 1 1 ]
      [ 1 0 ] [ 1 0 ]
	 
	= [ 1+1, 1+0 ]
	  [ 1+0, 1+0 ]
	 
	= [ 2, 1 ]
	  [ 1, 1 ]
	  
	
A^3 = [ 2, 1 ] [ 1 1 ]
      [ 1, 1 ] [ 1 0 ]
	  
	= [ 2+1, 2+0 ]
	  [ 1+1, 1+0 ]
	  
	= [ 3, 2 ]
	  [ 2, 1 ]
*/