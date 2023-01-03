//============================================================================
// Name        : Assignment1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "header.h"

using namespace std;

int main(int argc, char** argv) {

	// ********************************************************
	//GETTING COMMAND LINE ARGUMENTS
	int keymap_size;
	int matrix_size_row;
	int matrix_size_col;
	string matrix_txt = argv[3];
	string keymatrix_txt = argv[4];
	string output_txt = argv[5];

	stringstream test(argv[1]);
	string segment;
	vector<std::string> seglist;
	while(std::getline(test, segment, 'x'))
	{
		seglist.push_back(segment);
	}
	stringstream geek(seglist.at(0));
	geek >> matrix_size_row;
	stringstream geek2(seglist.at(1));
	geek2 >> matrix_size_col;


	const char* keymap_size_str =  argv[2] ;
	sscanf(keymap_size_str, "%d", &keymap_size);

	//**********************************************************

	int** matrix = createMatrix(matrix_size_row, matrix_size_col);
	int** key_matrix = createMatrix(keymap_size,keymap_size);
	vector<int> outputs = readFromTxt(matrix_txt);
	vector<int> key_outputs = readFromTxt(keymatrix_txt);
	cout<<key_outputs.at(2);
	fillMatrix(outputs, matrix, matrix_size_row, matrix_size_col);
	fillMatrix(key_outputs, key_matrix, keymap_size, keymap_size);
	//drawMatrix(matrix, matrix_size_row, matrix_size_col);
	//drawMatrix(key_matrix, keymap_size, keymap_size);
	fstream myFile;
	myFile.open(output_txt.c_str(), ios::out);
	search(matrix, key_matrix, matrix_size_row, matrix_size_col, keymap_size, 0, 0,myFile);
	myFile.close();
	//deleteMatrix(matrix, matrix_size_row);
	//deleteMatrix(key_matrix, keymap_size);

	return 0;
}




