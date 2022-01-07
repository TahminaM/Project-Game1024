/*Name: Tahmina Akther Munni
Professor Tong Yi
Projrct 2A
 
 Task A (20 points)
 Define constructors, destructor, and method print for Board.cpp.
 Implement constructors, we set max to be 0 and the target to be 32. Also, set numRows and numCols, initialize panel as a two-dimensional array of numRows rows and numCols.
 For default constructor, set numRows and numCols to be 3, panel is two-dimensional array with 3 rows and 3 columns, set max to be 0 and target to be 32.
 For Board(int m), set numRows to be m and numCols to be m if m is >= 1, otherwise, set numRows and numCols to be 3. Set panel to be a two-dimensional array with numRows rows and numCols columns, set max to be 0 and target to be 32.
 For Board(int m, int n), set numRows by m and numCols by n if both m and n are >= 1, otherwise, set numRows and numCols to be 3. Set panel to be a two-dimensional array with numRows rows and numCols columns, set max to be 0 and target to be 32.
 Define destructor, release the memory space pointed by panel and remember to handle dangling pointer problem.
 Define print method, which prints panel as a tabular format, each number in a cell with 4-character wide, if the number is 0, do not print it out. See sample output in the project.
 In this task, only submit Board.cpp to gradescope for grading. However, you should keep Board.hpp and Board.cpp in the same directory of local computer for compilation.
 After finishing this task, your code does not run yet, use g++ -std=c++11 -c Board.cpp to check for compilation errors.
 To test Task A, define TestBoard.cpp in the same directory as Board.hpp and Board.cpp, with the following contents.

*/

#include "Board.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
Board::Board()
{
	numRows = 3;
    	numCols = 3;
	panel = new int*[3];
	target = 32;
	max = 0;
	for (int i = 0; i < 3; i++)
		panel[i] = new int[3];
}


Board::Board(int m)
{
	if (m >= 1)
	{
		numRows = m;
		numCols = m;
	}
	else
	{

		numRows = 3;
		numCols = 3;
	}
	target = 32;
	max = 0;
	panel = new int*[numRows];
	for (int i = 0; i < numRows; i++)
		panel[i] = new int[numCols];
}



Board::Board(int m, int n)
{
	if (m >= 1)
		numRows = m;
	else
		numRows = 3;
	if (n >= 1)
		numCols = n;
	else
		numCols = 3;
	max = 0;
	target = 32;
	panel = new int*[numRows];
	for (int i = 0; i < m; i++)
		panel[i] = new int[numCols];
}


Board::~Board()
{
	for(int i = 0; i < sizeof(panel) / sizeof(panel[0]); i++)
		delete[] panel[i];
	delete[] panel;
}
//destructor

void Board::print() const
{
	for (int i = 0; i < numRows; i++)
	{
		for (int h = 0; h < numCols; h++)
			cout << "+----";
		cout << "+" << endl;
		for (int h = 0; h < numCols; h++)
		{
			cout << "|";
			if (panel[i][h] != 0)
				cout << std::setw(4) << panel[i][h];
			else
				cout << "    ";
		}
		
		cout << "|" << endl;
	}
	for (int h = 0; h < numCols; h++)
		cout << "+----";
	cout << "+" << endl;
}
