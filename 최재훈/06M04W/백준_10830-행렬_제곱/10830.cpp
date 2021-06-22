#include <iostream>
#include <vector>

using namespace std;

// global
typedef unsigned long long VERYLONG;
typedef vector<vector<VERYLONG>> VECTOR;


// method
VECTOR CalcResult(VECTOR matrix, VERYLONG B, VERYLONG N);
VECTOR MultiMatrix(VECTOR A_Matrix, VECTOR B_Matrix, VERYLONG N);
void Moduler1000(VECTOR& matrix);

int main()
{
    // init
    std::ios::sync_with_stdio(false);

    // input
    VERYLONG N = 0;
    VERYLONG B = 0;
    (void)scanf("%lld %lld", &N, &B);

    VECTOR input_Matrix;
    for (int row = 0; row < N; row++)
    {
        vector<VERYLONG> rowList;
        for (int col = 0; col < N; col++)
        {
            VERYLONG input = 0;
            (void)scanf("%lld", &input);
            rowList.push_back(input);
        }
        input_Matrix.push_back(rowList);
    }

    // calc
    VECTOR answer = CalcResult(input_Matrix, B, N);

    // print
    for (auto rowList : answer)
    {
        for (VERYLONG value : rowList)
            printf("%lld ", value);
        printf("\n");
    }

    return 0;
}

VECTOR CalcResult(VECTOR matrix, VERYLONG B, VERYLONG N)
{
    if (1 == B)
    {
        Moduler1000(matrix);
        return matrix;
    }

    VECTOR vec = CalcResult(matrix, B / 2, N);
    if (0 != (B % 2))
    {
        vec = MultiMatrix(vec, vec, N);
        Moduler1000(vec);
        vec = MultiMatrix(vec, matrix, N);
        Moduler1000(vec);

        return vec;
    }

    vec = MultiMatrix(vec, vec, N);
    Moduler1000(vec);

    return vec;
}

VECTOR MultiMatrix(VECTOR A_Matrix, VECTOR B_Matrix, VERYLONG N)
{
    VECTOR result_Matrix;
    for (int row = 0; row < N; row++)
    {
        vector<VERYLONG> tempList;
        for (int col = 0; col < N; col++)
        {
            VERYLONG value = 0;

            auto rowList = A_Matrix[row];
            int cdx = 0;
            for (int idx = 0; idx < N; idx++)
            {
                value += (A_Matrix[row][idx] * B_Matrix[cdx][col]);
                cdx++;
                if (N <= cdx)
                    cdx = 0;
            }
            tempList.push_back(value);
        }
        result_Matrix.push_back(tempList);
    }

    return result_Matrix;
}

void Moduler1000(VECTOR& matrix)
{
    for (auto& rowList : matrix)
    {
        for (auto& value : rowList)
            value %= 1000;
    }
}