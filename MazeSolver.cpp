/*
 * MazeSolver.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: mikeykem
 */
#include "MazeSolver.h"
using namespace std;

/*
 * beenThere() checks if the given space has been traversed.
 */
bool MazeSolver::beenThere(int x, int y){
	for (unsigned int i = 0; i < beenThereX.size(); i++){
		if (x == beenThereX[i] && y == beenThereY[i]){
			return true;
		}
	}
	return false;
}
/*
 * MazeSolver() is the constructor for the MazeSolver class.
 */
MazeSolver::MazeSolver(Maze m){
	int x = 0;
	int y = 0;
	M = m;
	M.getStart();
	M.getCurrentLocation(x, y);
}
/*
 * solve() is the recursive solution.
 */
bool MazeSolver::solve(){
	/*
	 * base case: have we reached the end of the maze?
	 */
	if (M.isFinish() == true){
		M.getCurrentLocation(x, y);
		finishX = x;
		finishY = y;
		return true;
	}
	else{
		/*
		 * Add current position to list of spaces traversed.
		 */
		M.getCurrentLocation(x, y);
		beenThereX.push_back(x);
		beenThereY.push_back(y);

		if (M.north() == true){
			/*
			 * checks if we've been there. If so, we have to head back to
			 * the original location and try the next direction.
			 */
			M.getCurrentLocation(x, y);
			if (beenThere(x, y) == true){
				M.south();
			}
			else{
				/*
				 * After moving successfully, we see if we can go on to find the finish
				 * down this path. if so, we store the position of the successful path
				 * and send the true back down the path chain.
				 */
				if (solve() == true){
					M.getCurrentLocation(x, y);
					pathX.push_back(x);
					pathY.push_back(y);
					return true;
				}
				/*
				 * if solve() returns false, we hit a dead end down the final path.
				 * So, we have no choice but head back and try another path.
				 */
				else{
					M.south();
				}
			}
		}
	  if (M.west() == true){
		M.getCurrentLocation(x, y);
		if (beenThere(x, y) == true){
			M.east();
		}
		else{
			if (solve() == true){
				M.getCurrentLocation(x, y);
				pathX.push_back(x);
				pathY.push_back(y);
				return true;
			}
			else{
				M.east();
			}
		}

	}
	    if (M.south() == true){
		   M.getCurrentLocation(x, y);
		   if (beenThere(x, y) == true){
			   M.north();
		   }
		   else{
			   if (solve() == true){
				   M.getCurrentLocation(x, y);
				   pathX.push_back(x);
				   pathY.push_back(y);
				   return true;
			   }
			   else{
				   M.south();
			   }
		   }
	  }
		   if (M.east() == true){
			  M.getCurrentLocation(x, y);
			  if (beenThere(x, y) == true){
				  M.west();
			  }
			  else{
				  if (solve() == true){
					  M.getCurrentLocation(x, y);
					  pathX.push_back(x);
					  pathY.push_back(y);
					  return true;
				  }
				  else{
					  M.west();
				  }
			  }
		  }
/*
 * If none of the directions works, we've hit a dead end! Returning false lets a
 * previous decision point keep looking elsewhere.
 */
				return false;

	}
}

/*
 * This allows the x values of every path coordinate to be accessed outside of the
 * solver. I found myself unsure of how to incorporate it and pathY into the text file or
 * put it into the string generated by Maze::printMaze() so as to display the path I took. This lets the instructor access
 * my path data to make sure I didn't do any funny business.
 */
vector<int> MazeSolver::getPathX(){
	return pathX;
}
/*
 * This allows the y values of every path coordinate to be accessed outside of the
 * solver. Each y coordinate has it's corresponding x coordinate at the same index in pathY.
 */
vector<int> MazeSolver::getPathY(){
	return pathY;
}


