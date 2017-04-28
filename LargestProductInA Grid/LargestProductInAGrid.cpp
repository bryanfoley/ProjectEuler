//============================================================================
// Name        : LargestProductInAGrid.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

const unsigned int size = 20;
unsigned int M[size][size] = {0};

int main()
{
    unsigned int r=0, c=0;

    // Fill the array
    ifstream fin("numbers.txt");
    if( fin )
    {
        for( r=0; r < size*size; ++r )
            fin >> M[r/size][r%size];

        fin.close();
    }
    else
    {
        cout << "The input file is not found!!" << endl;
        return 1;
    }

    unsigned int prod = 1;
    unsigned int maxProd = prod;

    // vertical products
    for( c=0; c < size; ++c )
        for( r=0; r < size-3; ++r )
        {
            prod = M[r][c]*M[r+1][c]*M[r+2][c]*M[r+3][c];
            if( prod > maxProd )
                maxProd = prod;
        }

    // horizontal products
    for( r=0; r < size; ++r )
        for( c=0; c < size-3; ++c )
        {
            prod = M[r][c]*M[r][c+1]*M[r][c+2]*M[r][c+3];
            if( prod > maxProd )
                maxProd = prod;
        }

    // Left-to-right diagonal products: (\)
    for( c=0; c < size-3; ++c )
        for( r=0; r < size-3; ++r )
        {
            prod = M[r][c]*M[r+1][c+1]*M[r+2][c+2]*M[r+3][c+3];
            if( prod > maxProd )
                maxProd = prod;
        }

    // Right-to-left diagonal products: (/)
    for( c=3; c < size; ++c )
        for( r=0; r < size-3; ++r )
        {
            prod = M[r][c]*M[r+1][c-1]*M[r+2][c-2]*M[r+3][c-3];
            if( prod > maxProd )
                maxProd = prod;
        }

    cout << "maxProd = " << maxProd << endl;

    cout << endl;
    return 0;
}
