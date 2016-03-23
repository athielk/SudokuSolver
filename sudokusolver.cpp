// sudokusolver.cpp
// Alex Thielk Kevin Chang 10/15/14

#include <iostream>
using namespace std;

#include "sudokugrid.h"
#include "gridio.h"

// mandatory function to define below main:
void solve(SudokuGrid &);
// do not change main
int main() {
    int problem[9][9];

    if ( !getProblem(problem) ) {
        cout << "bad input grid; terminating" << endl;
        return 1;
    }

    try {
        SudokuGrid grid(problem); // object, not pointer this time

        cout << "Problem:" << endl;
        display(&grid);           // so pass address to display
        cout << endl;

        solve(grid);

        if (grid.isSolved())
            cout << "Success! Solution:" << endl;
        else
            cout << "Not successful. Best effort:" << endl;

        display(&grid);
    }

    catch(GridException e) {
        cout << "exception: " << e << endl;
    }

    return 0;
}

// attempt to solve the problem using simple logic rules
void solve(SudokuGrid &grid) {
	int changes = 2;
	while(changes!=0){
		changes=0;
		for(int r=0; r<=8; r++){
			for (int c=0;c<=8;c++){
				int numcand = 0;
				int candidate = 0;
				for(int n=1;n<=9;n++){
					if(grid.getNumber(r,c)==0){
						if (grid.isCandidate(n,r,c)==true){
							candidate=n;
							numcand++;
						}
					}
				}
				if (numcand==1){
					grid.setNumber(candidate,r,c);
					changes++;
				}
			}
		}
		for(int r=0; r<=8; r++){
			for(int n=1;n<=9;n++){
				if(grid.occursInRow(n,r)==false){
					int slot;
					int numOfCanid=0;
					for(int c=0; c<=8;c++){
						if(grid.getNumber(r,c)==0){
							if (grid.isCandidate(n,r,c)==true){
								slot=c;
								numOfCanid++;
							}
						}
					}
					if (numOfCanid==1){
						grid.setNumber(n,r,slot);
						changes++;
					}
				/*if(onlych==1){
					for(int n = 1; n>=9; n++){
						if(grid.occursInRow(n,r)==false){
							grid.setNumber(n,r,c);
								changes++;
						}
					}*/	
				}
			}
		}
		for(int c=0; c<=8; c++){
			for(int n=1;n<=9;n++){
				if(grid.occursInColumn(n,c)==false){
					int slot;
					int numOfCanid=0;
					for(int r=0; r<=8;r++){
						if(grid.getNumber(r,c)==0){
							if (grid.isCandidate(n,r,c)==true){
								slot=r;
								numOfCanid++;
							}
						}
					}
					if (numOfCanid==1){
						grid.setNumber(n,slot,c);
						changes++;
					}
				}
			}
		}
		/*for(int c=0; c<=8; c++){
			int onlych=0;
			for(int r=0; r<=8; r++){
				if(grid.getNumber(r,c)==0){
					onlych++;
				}
				if(onlych==1){
					for(int n=1;n>=9;n++){
						if(grid.occursInColumn(n,c)==false){
							grid.setNumber(n,r,c);
							changes++;
						}
					}
				}
			}
		}*/
	cout<<changes<<"\n";
	}				
    // TYPE (MOST OR ALL OF) YOUR SOLUTION HERE
    // DECLARE UTILITY FUNCTIONS (IF ANY) HERE OR ABOVE, BUT DEFINE THEM BELOW
}


