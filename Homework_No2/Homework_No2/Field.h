#pragma once
class Field{
private:
	size_t N, M;
	size_t size;
	char** matrix;
public:
	Field() :matrix(nullptr), N(0), M(0){}
	Field(size_t n, size_t m){
		N = n;
		M = m;
		size = N*M;
		matrix = new char*[N*M];
	}
	~Field(){
		for (size_t i = 0; i < size; ++i){
			delete matrix[i];
		}
		delete[] matrix;
	}
public:
	void GenerateField();
};

/*void Field::GenerateField(){
	for (){
		for (){

		}
	}
}*/