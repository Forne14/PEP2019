#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include <memory>
using std::unique_ptr;

using std::vector;
using std::set;
using std::cout;
using std::endl;

// TODO: Your Sudoku class goes here:

class Sudoku : public Searchable{

private:
    vector<vector<set<int>>> aGrid;


public:

    Sudoku(const int &size) {
        for (int i = 0; i < size; ++i) {
            vector<set<int>> temp;
            for (int j = 0; j < size; ++j) {
                set<int> x;
                for (int k = 1; k <= size; ++k) {
                    x.insert(k);
                }
                temp.push_back(x);
            }
            aGrid.push_back(temp);
        }
    }

    Sudoku(const Sudoku &other){
        aGrid= other.aGrid;
    }

    int getSquare(int row, int col) const{
        if (aGrid[row][col].size() == 1) {
            return *aGrid[row][col].begin();
        } else {
            return -1;
        }

    }

    bool setSquare(int startRow, int startCol, int value) {


        aGrid[startRow][startCol].clear();
        aGrid[startRow][startCol].insert(value);

        //each box in the grid e.g 9x9 by grid has 9 3x3 boxes
        int subGridSize = sqrt(aGrid.size());
        int finalGridSize =0;
        int gridSize;
        bool search = true;
        vector<vector<set<int>>> tempGrid =aGrid;
        while(search){
            gridSize=0;

            for (int row = 0; row < aGrid.size(); ++row) {
                for (int col = 0; col < aGrid.size(); ++col) {
                    gridSize+=aGrid[row][col].size();
                    if (aGrid[row][col].size() == 1) {
                        int aValue = getSquare(row, col);
                        for (int i = 0; i < aGrid.size(); ++i) {
                            //remove the value from the sets on that row.
                            if (i!=col) {
                                aGrid[row][i].erase(aValue);
                            }
                            //remove the value from the sets on that column.
                            if (i!=row) {
                                aGrid[i][col].erase(aValue);
                            }
                        }
                            //remove the value from the sub-box
                            int subGridStartRow = (row - (row % subGridSize));
                            int subGridStartCol = (col - (col % subGridSize));

                            int subGridEndRow = subGridStartRow + (subGridSize - 1);
                            int subGridEndCol = subGridStartCol + (subGridSize - 1);

                                for (int tempRow = subGridStartRow; tempRow <= subGridEndRow; ++tempRow) {
                                    for (int tempCol = subGridStartCol; tempCol <= subGridEndCol; ++tempCol) {
                                        if (row != tempRow && col != tempCol) {
                                            aGrid[tempRow][tempCol].erase(aValue);
                                        }
                                    }
                                }
                    }else if(aGrid[row][col].size()==2){

                        set<int> doNotDelete = aGrid[row][col];
                        vector<int> values;
                        for(auto &e: aGrid[row][col]){
                            values.push_back(e);
                        }

                        int subGridStartRow = (row - (row % subGridSize));
                        int subGridStartCol = (col - (col % subGridSize));

                        int subGridEndRow = subGridStartRow + (subGridSize - 1);
                        int subGridEndCol = subGridStartCol + (subGridSize - 1);

                        int rowCheck = 0;
                        int colCheck = 0;
                        int gridCheck = 0;

                        for(int i=0; i<aGrid.size(); ++i){
                            if(doNotDelete==aGrid[row][i]){
                                rowCheck++;
                            }
                            if(doNotDelete==aGrid[i][col]){
                                colCheck++;
                            }
                        }

                        for (int tempRow = subGridStartRow; tempRow <= subGridEndRow; ++tempRow) {
                            for (int tempCol = subGridStartCol; tempCol <= subGridEndCol; ++tempCol) {
                                if (doNotDelete==aGrid[tempRow][tempCol]) {
                                    gridCheck++;
                                }
                            }
                        }

                        for(int i=0; i<aGrid.size(); ++i){
                            if(doNotDelete!=aGrid[row][i] && rowCheck==2){
                                aGrid[row][i].erase(values[0]);
                                aGrid[row][i].erase(values[1]);
                            }
                            if(doNotDelete!=aGrid[i][col] && colCheck==2){
                                aGrid[i][col].erase(values[0]);
                                aGrid[i][col].erase(values[1]);
                            }
                        }


                        for (int tempRow = subGridStartRow; tempRow <= subGridEndRow; ++tempRow) {
                            for (int tempCol = subGridStartCol; tempCol <= subGridEndCol; ++tempCol) {
                                if (doNotDelete!=aGrid[tempRow][tempCol] && gridCheck==2) {
                                    aGrid[tempRow][tempCol].erase(values[0]);
                                    aGrid[tempRow][tempCol].erase(values[1]);
                                }
                            }
                        }

                    }
                    else if(aGrid[row][col].size() ==3){
                        set<int> doNotDelete = aGrid[row][col];
                        vector<int> values;
                        for(auto &e: aGrid[row][col]){
                            values.push_back(e);
                        }

                        int subGridStartRow = (row - (row % subGridSize));
                        int subGridStartCol = (col - (col % subGridSize));

                        int subGridEndRow = subGridStartRow + (subGridSize - 1);
                        int subGridEndCol = subGridStartCol + (subGridSize - 1);

                        int rowCheck = 0;
                        int colCheck = 0;
                        int gridCheck = 0;

                        for(int i=0; i<aGrid.size(); ++i){
                            if(doNotDelete==aGrid[row][i]){
                                rowCheck++;
                            }
                            if(doNotDelete==aGrid[i][col]){
                                colCheck++;
                            }
                        }

                        for (int tempRow = subGridStartRow; tempRow <= subGridEndRow; ++tempRow) {
                            for (int tempCol = subGridStartCol; tempCol <= subGridEndCol; ++tempCol) {
                                if (doNotDelete==aGrid[tempRow][tempCol]) {
                                    gridCheck++;
                                }
                            }
                        }

                        for(int i=0; i<aGrid.size(); ++i){
                            if(doNotDelete!=aGrid[row][i] && rowCheck==3){
                                aGrid[row][i].erase(values[0]);
                                aGrid[row][i].erase(values[1]);
                            }
                            if(doNotDelete!=aGrid[i][col] && colCheck==3){
                                aGrid[i][col].erase(values[0]);
                                aGrid[i][col].erase(values[1]);
                            }
                        }


                        for (int tempRow = subGridStartRow; tempRow <= subGridEndRow; ++tempRow) {
                            for (int tempCol = subGridStartCol; tempCol <= subGridEndCol; ++tempCol) {
                                if (doNotDelete!=aGrid[tempRow][tempCol] && gridCheck==3) {
                                    aGrid[tempRow][tempCol].erase(values[0]);
                                    aGrid[tempRow][tempCol].erase(values[1]);
                                }
                            }
                        }
                    }
                    else if (aGrid[row][col].size()==0){
                        aGrid=tempGrid;
                        return 0;
                    }
                }
            }
            if (gridSize == finalGridSize){
                search=false;
            }else{
                finalGridSize =gridSize;
            }
        }

        write(cout);
        return true;
    }

    bool isSolution() const {

        for (int i = 0; i < aGrid.size(); ++i) {
            for (int j = 0; j < aGrid.size(); ++j) {
                if(getSquare(i,j)==-1){
                    return 0;
                }
            }
        }
        return 1;
    }

    void write(ostream & o) const{
        for (int i = 0; i < aGrid.size(); ++i) {
            for (int j = 0; j < aGrid.size(); ++j) {
                set<int> aSet = aGrid[i][j];
                for (set<int>::iterator x = aSet.begin(); x != aSet.end(); ++x) {
                    o << *x;
                }

                o << " ";
            }
            o << "" << endl;
        }
        o << "---------------------------------------------------" << endl;

    }

    vector<unique_ptr<Searchable> > successors() const{
        vector<unique_ptr<Searchable>> successors;
        int rowWithMoreThanOneOption = -1;

        //find the first row containing a square with more than one value;
        for (int row=0; row<aGrid.size();++row){
            for(int col=0; col<aGrid.size();++col){
                if(getSquare(row,col)==-1){
                    rowWithMoreThanOneOption =row;
                    row = aGrid.size();
                    col = aGrid.size();
                }
            }
        }



        int leftMostCol =-1;
        for(int col=0; col<aGrid.size();col++){
            if(getSquare(rowWithMoreThanOneOption,col)==-1){
                leftMostCol=col;
                col = aGrid.size();
            }
        }

        set<int> leftMostSetOnRow = aGrid[rowWithMoreThanOneOption][leftMostCol];


            for (set<int>::iterator x = leftMostSetOnRow.begin(); x != leftMostSetOnRow.end(); ++x) {
                unique_ptr<Sudoku> anotherSudokuBoard =unique_ptr<Sudoku>(new Sudoku(*this));
                if(anotherSudokuBoard->setSquare(rowWithMoreThanOneOption,leftMostCol, *x)){

                    successors.push_back(std::move(anotherSudokuBoard));
                }

            }

            if (successors.size()==1 && !((*successors.begin())->isSolution())){
                 return successors[0]->successors();
            }
            return successors;


    }

    int heuristicValue() const {
        int count =0;
        for(int i=0; i<aGrid.size();++i){
            for(int j=0; j<aGrid.size();++j){
              if (getSquare(i,j)==-1){
                  ++count;
              }
            }
        }
        return count;
    }

};

#endif
