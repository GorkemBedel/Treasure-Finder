#include "header.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//That function creates a 2D Array which uses dynamic memory allocation.
int** createMatrix(int &row, int &col){
	int** matrix; //Pointer of pointers.
	matrix = new int*[row];

	for(int i=0 ; i < row; i++){
		matrix[i] = new int[row]; // A table of pointers which holds the adresses of 1D arrays.(These are the rows of the matrix.)
		for(int j = 0; j < col; j++){
			matrix[i][j] = 0; // Firstly ı fill the matrix with 0's. Then ı will fill it with another function.
		}
	}
	return matrix;
}

//That function deletes the 1D arrays, their pointer table and the main pointer. So whenever tha game finishes, we clear all the memory.
void deleteMatrix(int** &matrix, int &row){
	 for(int i = 0; i < row; i++){
		 delete[] matrix[i]; // Firstly ı delete the 1D arrays with using their pointers.
	 }
	 delete matrix; //Then ı delete the main pointer. (pointer of pointers)
	 matrix = NULL;
}

//That function reads the mapmatrix.txt and keymatrix.txt. Then returns a vector that holds the integer values inside the txt.
vector<int> readFromTxt(string &matrix_txt){
	fstream newfile;
		std::vector<int> outputs;
		std::vector<int> Data;
		newfile.open(matrix_txt.c_str(),ios::in);
		if(newfile.is_open()){
			string tp;
			string str;
			while(getline(newfile,tp)){
				stringstream ss(tp);
				while(getline(ss,str,' ')){
					std :: stringstream geek(str);
					int x;
					geek >> x;
					outputs.push_back(x);
				}

			}

		}else{cout<<"file can not opened";}
		return outputs;
}


//That function takes the 2d Matrix, its sizes and the vector which readFromTxt returns as parameters. And it fill the matrix with the integers inside of vector.
void fillMatrix(vector<int> &outputs, int** &matrix, int &row, int &col){
	int x = 0;
	int size = row * col;
	while(x < size){
		for(int i=0 ; i < row; i++){
			for(int j = 0; j < col; j++){
				matrix[i][j] = outputs.at(x);
				x ++;
			}
		}
	}
}

// That function is not necessary for the assignment but ı coded it to clarify if ı fill the matrix correctly. Simply it draws the matrix to console.
void drawMatrix(int** &matrix, int &row, int &col){
	for(int i=0 ; i < row; i++){
			for(int j = 0; j < col; j++){
				cout<<matrix[i][j]<< " ";
			}
			cout<<endl;
		}
}

// That is the main function of the assignment. It recursively check the matrixes if they hold the hidden treasure or not. Firstly it finds the dot product, and
//check its mod of 5. Depending of the result it calls itself with another parameters or if the result is 0 it finishes the game.

void search(int** &matrix, int** &keymatrix,int &matrix_row_size, int &matrix_col_size, int &keymatrix_size, int index_row, int index_col,fstream &outputfile){
	int dotProduct = 0;
	for(int i = index_row; i < (index_row + keymatrix_size); i++){
		for(int j = index_col; j < (index_col + keymatrix_size); j++){
			dotProduct += matrix[i][j] * keymatrix[i%keymatrix_size][j%keymatrix_size];
		}
	}

	if(dotProduct < 0){
		while( dotProduct < 0){
			dotProduct += 5;
		}
	}


	int x = index_row + (keymatrix_size/2);
	int y = index_col+ (keymatrix_size/2);

	stringstream iks, ye,ze;
	iks << x;
	ye << y;
	ze << dotProduct;
	string s = iks.str() + "," + ye.str() + ":" + ze.str();

	if(outputfile.is_open()){
		outputfile<<s<<endl;
		}

	if( dotProduct % 5 == 0){
		cout<<"Game Over";
		outputfile<<"Game Over";
	}else if((dotProduct) % 5 ==1){
		if((index_row-keymatrix_size) >= 0){
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, (index_row-keymatrix_size), index_col, outputfile);
		}else{
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, (index_row+keymatrix_size), index_col, outputfile);
		}

	}else if((dotProduct % 5) ==2){
		if((index_row+keymatrix_size) < (matrix_row_size-keymatrix_size+1)){
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, (index_row+keymatrix_size), index_col,outputfile);
		}else{
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, (index_row-keymatrix_size), index_col,outputfile);

		}

	}else if((dotProduct) % 5 ==3){
		if( (index_col+keymatrix_size) < (matrix_col_size-keymatrix_size+1)){
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, index_row, (index_col+keymatrix_size) ,outputfile);

		}else{
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, index_row, (index_col-keymatrix_size) ,outputfile);

		}
	}else if((dotProduct) % 5 ==4){
		if((index_col-keymatrix_size) >= 0 ){
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, index_row, (index_col-keymatrix_size) ,outputfile);

		}else{
			search(matrix, keymatrix,matrix_row_size,matrix_col_size,keymatrix_size, index_row, (index_col+keymatrix_size) ,outputfile);

		}

	}
}

void writeOutputFile(string &output_txt, string x){
	fstream myFile;
	myFile.open(output_txt.c_str(), ios::out);
	if(myFile.is_open()){
		cout<<x;
		myFile.close();
	}
}





