/*
 * header.h
 *
 *  Created on: 23 Eki 2022
 *      Author: Admin
 */

#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


using namespace std;

int** createMatrix(int &row, int&col);
void deleteMatrix(int** &matrix, int &row);
vector<int> readFromTxt(string &matrix_txt);
void writeOutputFile(string &output, string x);
void fillMatrix(vector<int> &outputs, int** &matrix, int &row, int &col);
void drawMatrix(int** &matrix, int &row, int &col);
void search(int** &matrix, int** &keymatrix,int &matrix_row_size, int &matrix_col_size, int &keymatrix_size, int index_row, int index_col,fstream &outputfile);




#endif /* HEADER_H_ */
