#include "Field.h"
void Field::GenerateField(){
	for (size_t row = 0; row < N; ++row)
	{
		matrix[row] = new char[M];
		for (size_t col = 0; col < M; ++col)
		{
			std::cin >> matrix[row][col];
		}
	}
}