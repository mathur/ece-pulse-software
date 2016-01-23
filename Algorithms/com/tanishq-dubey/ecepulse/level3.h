#include <stdio.h>
#include <assert.h>
#define true 1
#define false 0

void solve(int* solve);

//Solve helper method
int solver(int* maze);

//Solver helper methods
int is_val_valid(const int val, const int i, const int j, const int* maze);
int is_val_in_row(const int val, const int i, const int* maze);
int is_val_in_col(const int val, const int j, const int* maze);
int is_val_in_3x3_zone(const int val, const int i, const int j, const int* maze);
int is_val_in_diag(const int val, const int i, const int j, const int* maze);

void solve(int* solve) {
	solver(solve);
}

// Solve the given sudoku instance using backtracking
int solver(int* maze)
{
	//declare variables
	int i, j;
	int spaceLeft = false;
	int xSpace, ySpace;
	int num;

	//double for loop for moving through each square in the sudoku array
	for(i = 0; i < 9; i++) {
			for(j = 0; j < 9; j++) {
					//Check if current square is 0, if it is then it needs
					//to be filled
					if(maze[9 * i + j] == 0){
							//Mark the coordinates and mark that there is
							//space to be filled
							spaceLeft = true;
							xSpace = i;
							ySpace = j;

					}
			}
	}
	//If there is no more space left, return true and finish
	if(!spaceLeft){
			return true;
	}

	//Pick a number starting at 1 and going to 9
	for(num = 1; num <= 9; num++) {
			//Check if the value can be placed in the current square
			if(is_val_valid(num, xSpace, ySpace, maze)) {
					//If it can, place it and move to the next branch of
					//sudoku recursively
					maze[9 * xSpace + ySpace] = num;
					if(solver(maze)) {
							return true;
					}
					//If it can't be filled, set to zero
					maze[9 * xSpace + ySpace] = 0;
			}
	}
	//Returned when space can't be filled
	return false;
}


int is_val_valid(const int val, const int i, const int j, const int* maze) {
    //One line return to check if a value can be placed in a specific square.
    return !is_val_in_row(val, i, maze) && !is_val_in_col(val, j, maze) && !is_val_in_3x3_zone(val, i, j, maze);// && !is_val_in_diag(val, i, j, maze);
}


int is_val_in_row(const int val, const int i, const int* maze) {
        //Check if input is valid
        assert(i>=0 && i<9);

        //declare return variable and counter
        int exists = false;
        int j;

        //move through the whole row checking if the value exists
        for(j = 0; j < 9; j++) {
                if(val == maze[9 * i + j]) {
                        exists = true;
                }
        }

        //return if it exists or not
        return exists;
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int* maze) {
        //Check if input is valid
        assert(j>=0 && j<9);

        //declare return variable and counter
        int exists = false;
        int i;

        //move through the whole column checking if the value exists
        for(i = 0; i < 9; i++) {
                if(val == maze[9 * i + j]) {
                        exists = true;
                }
        }

        //return if it exists or not
        return exists;

}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
// Sections are labed as such:
//
//  1 2 3
//  4 5 6
//  7 8 9
int is_val_in_3x3_zone(const int val, const int i, const int j, const int* maze) {

        assert(i>=0 && i<9);
        assert(j>=0 && j<9);
        int exists = false;
        int x;
        int y;
        //There are 8 copies of this statement, they all do the same thing, but
        //with different bounds

        //Check where the current coords are located
        if((i < 3 && i >=0) && (j < 3 && j >=0)) {
                //Section 1

                //traverse the whole 3x3 square
                for(x = 0; x < 3; x++){
                        for(y = 0; y < 3; y++){
                                //check if value exists
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 6 && i >=3) && (j < 3 && j >=0)) {
                //Section 2
                for(x = 3; x < 6; x++){
                        for(y = 0; y < 3; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 9 && i >=6) && (j < 3 && j >=0)) {
                //Section 3
                for(x = 6; x < 9; x++){
                        for(y = 0; y < 3; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 3 && i >=0) && (j < 6 && j >=3)) {
                //Section 4
                for(x = 0; x < 3; x++){
                        for(y = 3; y < 6; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 6 && i >=3) && (j < 6 && j >=3)) {
                //Section 5
                for(x = 3; x < 6; x++){
                        for(y = 3; y < 6; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 9 && i >=6) && (j < 6 && j >=3)) {
                //Section 6
                for(x = 6; x < 9; x++){
                        for(y = 3; y < 6; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 3 && i >=0) && (j < 9 && j >=6)) {
                //Section 7
                for(x = 0; x < 3; x++){
                        for(y = 6; y < 9; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 6 && i >=3) && (j < 9 && j >=6)) {
                //Section 8
                for(x = 3; x < 6; x++){
                        for(y = 6; y < 9; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        } else if((i < 9 && i >=6) && (j < 9 && j >=6)) {
                //Section 9
                for(x = 6; x < 9; x++){
                        for(y = 6; y < 9; y++){
                                if(val == maze[9 * x + y]) {
                                        exists = true;
                                }
                        }
                }
        }
        return exists;
}

// Function: is_val_in_diag
// Return true if the val alraedy exists in the diagionals of the sudoku square
int is_val_in_diag(const int val, const int i, const int j, const int* maze) {

        //create return variable
        int exists = false;

        //check asserts
        assert(i>=0 && i<9);
        assert(j>=0 && j<9);

        //initalize more vars
        int x, y;
        x = 0;
        y = 0;

        //check top-left diagional to bottom
        if(i == j){
                for(x = 0; x < 9; x++){
                        if(maze[9 * x + y] == val){
                                exists = true;
                        }
                        y++;
                }
        }
        //reset variable and do top-right diagional to bottom
        x = 8;
        if(i + j == 8){
                for(y = 0; y < 9; y++){
                        if(maze[9 * x + y] == val) {
                                exists = true;
                        }
                        x--;
                }
        }

        //return if a value was fround
        return exists;
}
