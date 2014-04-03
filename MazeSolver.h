/*
 * MazeSolver.h
 *
 *  Created on: Mar 16, 2014
 *      Author: mikeykem
 */

#ifndef MAZESOLVER_H_
#define MAZESOLVER_H_
#include "maze.h"
#include <vector>
using namespace std;

class MazeSolver{
private:
	/*
	 * x and y store the coordinates from Maze::getCurrentLocation(x,y)
	 */
	int x;
	int y;
	/*
	 * beenThere vectors store coordinates previously traversed.
	 */
	vector<int> beenThereX;
	vector<int> beenThereY;
	/*
	 * path vectors store coordinates used to solve the maze
	 */
	vector<int> pathX;
	vector<int> pathY;
	/*
	 * finish variables store the location of the finish.
	 */
	int finishX;
	int finishY;
	/*
	 * Maze class to interface with.
	 */
	Maze M;

public:
	bool beenThere(int x, int y);
	bool solve();
	MazeSolver(Maze m);
	vector<int> getPathX();
	vector<int> getPathY();



};




#endif /* MAZESOLVER_H_ */
