#include <iostream>
#include <vector>

using namespace std;

void printMat(vector<vector<int> >& matrix);
bool rightSearch();
bool downSearch();
bool searchMatrix(vector<vector<int> >& matrix, int target);

void printMat(vector<vector<int> >& matrix){
	for(size_t i = 0; i < matrix.size(); i++){
		for(size_t j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << "   ";
		cout << endl;
	}
}

bool binarySearch(const vector<vector<int> >& matrix,size_t row, size_t col,int target, size_t rlower, size_t rupper);
bool binarySearch(const vector<vector<int> >& matrix,size_t row, size_t col,int target, size_t rlower, size_t rupper){

	if(matrix[row][col] == target)
		return true;
	if(matrix[row][col] < target){
		if(col < (matrix[row].size() - 1) && row == rlower)
			if(binarySearch(matrix, row, col+1, target, rlower, rupper))
					return true;
		if( row < (rupper -1))
			if(binarySearch(matrix, row+1, col, target, rlower, rupper))
					return true;
		if(row == rupper - 1){
			return false;
		}
	}
	cout << "row:" << row <<  "    col: " << col << endl;
	cout << matrix[row][col] << endl;
	return false;
}

bool searchMatrix(vector<vector<int> >& matrix, int target){
	vector<size_t> start_pos(2, 0);
	size_t start_row = 0;
	size_t end_row_add_1 = matrix.size();
	for(size_t i = 0; i < matrix.size(); i++){
		if(matrix[i].back() > target && start_row == 0){
			start_row = i;
		}
		if(matrix[i][0] > target && end_row_add_1 == matrix.size()){
			end_row_add_1 = i;
			break;
		}
	}
	cout << start_row << "   " << end_row_add_1 << endl;
	return binarySearch(matrix, start_row, 0, target, start_row, end_row_add_1);
}


int main(){
	size_t row = 10;
	vector<int> row_elem;
	vector< vector<int> > matrix(10);	
	for(size_t i = 0; i < matrix.size(); i++){
		for(size_t j = 0; j < row; j++)
			row_elem.push_back( 11*i+(3*j));
		matrix[i]	= row_elem;
		row_elem.clear();
	}

 	if(searchMatrix(matrix, 113))
		cout << "Goood!!!!" << endl;

	printMat(matrix);

	return 0;
}
