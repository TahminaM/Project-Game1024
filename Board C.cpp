
/*Name: Tahmina Akther Munni
Professor Tong Yi
Projrct 2C
Task C (20 points)
 
*/




#include <iostream>
#include <iomanip> 
#include <vector>
#include "Board.hpp"
using namespace std;

void printSeparateLine(int numCols)
{
    cout << "+";
    for (int j = 0; j < numCols; j++)
        cout << "----+";

    cout << endl;
}

void Board::print() const
{
    printSeparateLine(numCols);
    for (int i = 0; i < numRows; i++)
    {
        cout << "|";
        for (int j = 0; j < numCols; j++)
            if (panel[i][j] > 0)
                cout << setw(4) << panel[i][j] << "|";
            else cout << setw(4) << " " << "|";

        cout << endl;
        printSeparateLine(numCols);
    }
}

void Board::pressDown()
{
    int* temp = new int[numRows];
    int toWrite;
    for (int j = 0; j < numCols; j++)
    {
       
        for (int k = 0; k < numRows; k++)
            temp[k] = 0;

        
        toWrite = numRows - 1; 
        for (int i = numRows - 1; i >= 0; i--)
            if (panel[i][j] > 0)
            {
                temp[toWrite] = panel[i][j];
                toWrite--;
            }

        for (int k = numRows - 1; k > 0; k--) 
            if (temp[k] == temp[k - 1])
            {
                temp[k] *= 2;

                if (max < temp[k])
                    max = temp[k];

                temp[k - 1] = 0;
                k--; 

            }

        int i = numRows - 1;  
        int k = numRows - 1; 
        while (k >= 0)
        {
            if (temp[k] > 0)
            {
                panel[i][j] = temp[k];
                i--;
            }
            k--;
        }

        
        while (i >= 0)
        {
            panel[i][j] = 0;
            i--;
        }
    }

    delete[] temp;
    temp = nullptr;


    int row = -1, col = -1;
    selectRandomCell(row, col);
}

void Board::pressUp() {

    int* temp = new int[numRows];
    int toWrite;
    for (int j = 0; j < numCols; j++) {
        for (int k = 0; k < numRows; k++) {
            temp[k] = 0;
        }
        toWrite = 0;
        for (int i = 0; i < numRows; i++) {
            if (panel[i][j] > 0) {
                temp[toWrite] = panel[i][j];
                toWrite++;
            }
        }
        for (int m = 0; m < numRows; m++) {
            if (temp[m] == temp[m + 1]) {
                temp[m] *= 2;
               
                if (max < temp[m]) 
                    max = temp[m];
                
                temp[m + 1] = 0;
                m++;
            }
        }
        int h = 0;
        int g = 0;
        while (g < numRows) {
            if (temp[g] > 0) {
                panel[h][j] = temp[g];
                h++;
            }
            g++;
        }
        while (h < numRows ) {
            panel[h][j] = 0;
            h++;
        }
    }
    delete[] temp;
    temp = nullptr;
    int row = 1;
    int col = 1;
    selectRandomCell(row, col);
}

void Board::pressLeft()
{
    int* temp = new int[numCols];
    int toWrite;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++)
            temp[j] = 0;
        toWrite = 0;
        for (int j = 0; j < numCols; j++) {
            if (panel[i][j] > 0) {
                temp[toWrite] = panel[i][j];
                toWrite++;
            }
        }
        for (int j = 0; j < numCols; j++) {
            if (temp[j] == temp[j + 1]) {
                temp[j] *= 2;
                temp[j + 1] = 0;
                if (max < temp[j])
                    max = temp[j];
                j++;
            }
        }
        toWrite = 0;
        for (int j = 0; j < numCols; j++) {
            if (temp[j] > 0) {
                panel[i][toWrite] = temp[j];
                toWrite++;
            }
        }
        while (toWrite < numCols) {
            panel[i][toWrite] = 0;
            toWrite++;
        }
    }
    delete[] temp; //release dynamically allocated memory
    temp = nullptr;
    //avoid dangling pointer problem,
    //by setting pointer to released memory to
    //nullptr

    int row = -1;
    int col = -1;
    selectRandomCell(row, col);
}

void Board::pressRight()
{
    int* temp = new int[numCols];
    int toWrite;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = numCols - 1; j >= 0; j--)
            temp[j] = 0;
        
        toWrite = numCols - 1;
        for (int j = numCols - 1; j >= 0; j--)
            if (panel[i][j] > 0)
            {
                temp[toWrite] = panel[i][j];
                toWrite--;
            }
        for (int j = numCols - 1; j > 0; j--)
        {
            //merge temp[j] and temp[j-1]
            //if they are equal
            if (temp[j] == temp[j - 1])
            {
                temp[j] *= 2;
                temp[j - 1] = 0;
                if (max < temp[j])
                    max = temp[j];

                j--;
            }
        }

        //copy the non-zeros from temp
        //back the ith row, starting from right
        //to left
        toWrite = numCols - 1; //column index of ith row
        for (int j = numCols - 1; j >= 0; j--)
            if (temp[j] > 0)
            {
                panel[i][toWrite] = temp[j];
                toWrite--;
            }

        while (toWrite >= 0)
        {
            panel[i][toWrite] = 0;
            toWrite--;
        }
    }

    delete[] temp; //release dynamically allocated memory
    temp = nullptr;
    //avoid dangling pointer problem,
    //by setting pointer to released memory to
    //nullptr

    int row = -1;
    int col = -1;
    selectRandomCell(row, col);
}
