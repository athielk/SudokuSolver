// sudokugrid.cpp
// Alex Thielk Kevin Chan 10/13/2014
#include "gridio.h"
#include "sudokugrid.h"
using namespace std;

// IMPLEMENT CONSTRUCTOR AND 7 MEMBER FUNCTIONS AS SPECIFIED IN "sudokugrid.h"
SudokuGrid::SudokuGrid(const int problem[9][9]){
	for(int column=0; column<=8; column++){
		for(int row=0; row<=8; row++){
			if(problem[row][column]<0 or problem[row][column]>9){
				throw GridException(DATA);
			}
			array[row][column].number= problem[row][column];
			if(array[row][column].number!=0){
				array[row][column].fixed=true;
			}
			else{
				array[row][column].fixed=false;
			}	
		}
	}
}
int SudokuGrid::getNumber(int row, int column)const{
	if(row<0 or column<0 or row>8 or column>8){
		throw GridException(INDEX);
	}
	return (array[row][column].number);
}
void SudokuGrid::setNumber(int number, int row, int column){
	if(row<0 or column<0 or row>8 or column>8){
		throw GridException(INDEX);
	}
	if (number<0 or number >9){
		throw GridException(DATA);
	}
	if (array[row][column].fixed== true){
		throw GridException(RULE);
	}
	if (array[row][column].fixed==false){
		array[row][column].number=number;
	}
}
bool SudokuGrid::occursInRow(int number, int row)const{
	if(row<0 or row>8){
		throw GridException(INDEX);
	}
	for (int i =0;i<=8;i++){
		if (array[row][i].number==number){
			return true;
		}
	}
	return false;
}
bool SudokuGrid::occursInColumn(int number, int column)const{
	if(column<0 or column>8){
		throw GridException(INDEX);
	}
	for (int i=0;i<=8;i++){
		if (array[i][column].number==number){
			return true;
		}
	}
	return false;
}
bool SudokuGrid::occursInBox(int number, int row, int column)const{
	if(row<0 or column<0 or row>8 or column>8){
		throw GridException(INDEX);
	}
	if (row>=0 and row<=2){
		for(int i=0;i<=2;i++){
			if(column>=0 and column<=2){
				for (int j=0;j<=2;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
		
			if(column>=3 and column<=5){
				for (int j=3;j<=5;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
			if(column>=6 and column<=8){
				for (int j=6;j<=8;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
		}
	}
	if (row>=3 and row<=5){
		for(int i=3;i<=5;i++){
			if(column>=0 and column<=2){
				for (int j=0;j<=2;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
		
			if(column>=3 and column<=5){
				for (int j=3;j<=5;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
			if(column>=6 and column<=8){
				for (int j=6;j<=8;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
		}
	}
	if (row>=6 and row<=8){
		for(int i=6;i<=8;i++){
			if(column>=0 and column<=2){
				for (int j=0;j<=2;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
		
			if(column>=3 and column<=5){
				for (int j=3;j<=5;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
			if(column>=6 and column<=8){
				for (int j=6;j<=8;j++){
					if (array[i][j].number==number){
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool SudokuGrid::isCandidate(int number, int row,int column)const{
	if(row<0 or column<0 or row>8 or column>8){
		throw GridException(INDEX);
	}
	if(number<0 or number>9){
		return false;
	}
	if(SudokuGrid::occursInRow(number, row)==false and SudokuGrid::occursInColumn(number, column)==false and SudokuGrid::occursInBox(number, row, column)==false){
		return true;
	}
	return false;
}
bool SudokuGrid::isSolved()const{
	int right=0;
	for(int number=1;number<=9;number++){
		for(int row=0;row<=8;row++){
			for(int column=0;column<=8;column++){
				if(SudokuGrid::occursInRow(number, row)==false and SudokuGrid::occursInColumn(number,column)== false and SudokuGrid::occursInBox(number, row, column==false)){
					right++;
				}
			}
		}
	}
	if (right==0){
		return true;
	}
	return false;
}
