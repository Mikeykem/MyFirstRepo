/*
 * Test.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: mikeykem
 */

#include "MazeSolver.h"
#define MAZE_FILE "maze.txt"
int main(){
	Maze maze;
	maze.ReadMaze(MAZE_FILE);
	MazeSolver* solver = new MazeSolver(maze);
	solver->solve();
	vector<int> pathX = solver->getPathX();
	vector<int> pathY = solver->getPathY();
	cout << maze << endl;
	cout << "The path taken:" << endl;
	for (int i = pathX.size() - 1; i <= 0; i--){
		cout << pathX[i] << "," << pathY[i] << endl;
	}
}


