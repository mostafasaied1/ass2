// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: CS213-2018-A2-T1
// Purpose: cpp file which contain code of program that do mathimatical operation on matrices
// Author:  Mostafa saied-Mohamed abd elbaset-Rawan mahmoud
// Version: 2.0
#include "matrix.h"
#include <iostream>

using namespace std;
//defult constractor
matrix::matrix() {}

// Takes an array of data and stores in matrix according
// to rows and columns
matrix::matrix(int row,int col,int num[])
{
    this->row = row;
    this->col = col;
    data = new int* [row];

    for (int i = 0; i < row; i++)
        data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = num[i * col + j];
    //ctor
}
//======================================================================
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with combined process
matrix matrix ::operator+(matrix mat2)
{
    matrix res(0,0, {});

    //res.data[res.row][res.col]=0;
    if((this->col!=mat2.col)||(this->row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {
        res.col=this->col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=this->data[i][j]+mat2.data[i][j];
            }
        }
        return res;
    }
}
//_______________________________________________________________________
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with  subtraction process
matrix matrix::operator-(matrix mat2)
{
    matrix res(0,0, {});
    //res.data[res.row][res.col]=0;
    if((this->col!=mat2.col)||(this->row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {

        res.col=this->col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=this->data[i][j]-mat2.data[i][j];
            }
        }
        return res;
    }
}
//________________________________________________________________________
//this function take two matrix and make sure columns in matrix1 is equal to rows in matrix2
//then return new matrix with  multiplication process
matrix matrix::operator*(matrix mat2)
{
    matrix res(0,0, {});
    //res.data[res.row][res.col]=0;
    if(this->col!=mat2.row)
    {
        cout<<"Dimensions Do Not Match"<<endl;
        return res;
    }
    else
    {
        res.col=mat2.col;
        res.row=this->row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                int temp=0;
                for(int x=0; x<this->col; x++)
                {
                    temp+=this->data[i][x]*mat2.data[x][j];
                }
                res.data[i][j]=temp;
            }

        }
        return res;
    }
}
//_________________________________________________________________________
//this function take only on matrix and scalar this add scalar to each element in matrix
// and return it
matrix matrix::operator+ ( int scalar)
{

    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            this->data[i][j]+=scalar;
        }
    }
    return *this;

}
//_________________________________________________________________________
//this function take only on matrix and scalar this subtract scalar from each element in matrix
// and return it
matrix matrix::operator-  ( int scalar)
{

    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            this->data[i][j]-=scalar;
        }
    }
    return *this;
}
//_________________________________________________________________________
//this function take only on matrix and scalar this multiply scalar to each element in matrix
// and return it
matrix matrix::operator*( int scalar)
{
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            this->data[i][j]*=scalar;

        }
    }
    return *this;
}
//=========================================================================
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with combined process
matrix matrix::operator+= ( matrix mat2)
{
    matrix res(0,0, {});

    //res.data[res.row][res.col]=0;
    if((this->col!=mat2.col)||(this->row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {
        res.col=this->col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=this->data[i][j]+mat2.data[i][j];
            }
        }
        *this=res;
        return *this;

    }
}
//------------------------------------------------------------
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with  subtraction process
matrix matrix::operator-= ( matrix mat2)
{
    matrix res(0,0, {});

    //res.data[res.row][res.col]=0;
    if((this->col!=mat2.col)||(this->row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {

        res.col=this->col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=this->data[i][j]-mat2.data[i][j];
            }
        }
        *this=res;
        return *this;
    }
}
//--------------------------------------------------------------------------------
//this function take only on matrix and scalar this add scalar to each element in matrix
// and return it
matrix matrix::operator+= ( int scalar)
{
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            this->data[i][j]+=scalar;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------------
//this function take only on matrix and scalar this subtract scalar from each element in matrix
// and return it
matrix matrix::operator-= ( int scalar)
{
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            this->data[i][j]-=scalar;
        }
    }
    return *this;
}
//--------------------------------------------------------------------------------
//this function take only one matrix and add 1 to each element of this matrix
void matrix::operator++()
{
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            ++this->data[i][j];
        }
    }
}
//--------------------------------------------------------------------------------
//this function take only one matrix and subtract 1 from each element of this matrix
void   matrix::operator--()
{
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            --this->data[i][j];
        }
    }
}
//---------------------------------------------------------------------------------
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input
istream& operator>> (istream& in,matrix &mat)
{
    in>>mat.row>>mat.col;
    mat.data = new int* [mat.row];
    for(int i=0; i<mat.row; i++)
    {
        mat.data[i] = new int [mat.col];
        for(int j=0; j<mat.col; j++)
        {
            in>>mat.data[i][j];
        }
    }
    return in;
}
//=================================================================================
ostream& operator<< (ostream& out,const matrix& mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            out<<mat.data[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
//----------------------------------------------------------------------------------
//this function take two matrix and return True if not same
bool matrix::operator!= ( matrix mat2)
{
    if((this->col!=mat2.col)||(this->row!=mat2.row))
    {
        // cout<<"*";
        return true;
    }
    else
    {

        for(int i=0; i<this->row; i++)
        {

            for(int j=0; j<this->col; j++)
            {

                if(this->data[i][j]!=mat2.data[i][j])
                {

                    //  cout<<mat1.data[i][j]<<" "<<mat2.data[i][j];
                    return true;
                }
                else if((i==this->row-1)&&(j==this->col-1))
                {

                    return false;
                }

            }
        }
    }
}
//----------------------------------------------------------------------------------
// this function take one matrix and return True if square matrix
bool matrix::isSquare()
{
    if(this->col==this->row)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-----------------------------------------------------------------------------------
// this function take one matrix and  Return new matrix with the transpose
matrix matrix::transpose()
{
    matrix res;
    res.row=col;
    res.col=row;
    res.data = new int* [res.row];
    for(int i=0; i<res.row; i++)
    {
        res.data[i] = new int[res.col];
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {

            res.data[j][i]=data[i][j];

        }
    }
    return res;
}
//----------------------------------------------------------------------------------
//this function take two matrix and return true if two matrix identical and false if not
bool matrix::operator== (matrix mat2)
{
    if((col!=mat2.col)||(row!=mat2.row))
    {
        return false;
    }
    else
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(data[i][j]!=mat2.data[i][j])
                {
                    return false;
                }
                else if((i==row-1)&&(j==col-1))
                {
                    return true;
                }
            }
        }
    }
}
//-------------------------------------------------------------------------
void   matrix::operator=(matrix mat2)
{
    this->row=mat2.row;
    this->col=mat2.col;

    this->data=new int*[mat2.row];
    for(int i=0; i<mat2.row; i++)
    {
        this->data[i]=new int[mat2.col];
        for(int j=0; j<mat2.col; j++)
        {
            this->data[i][j]=mat2.data[i][j];
        }
    }
}
//-----------------------------------------------------------------------------------
// this function take one matrix and return True if square and symmetric
bool matrix::isSymetric ()
{
    if(!this->isSquare())
    {
        return false;
    }
    else
    {
        matrix temp=this->transpose();
        if((temp==*this))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}

//-----------------------------------------------------------------------------------
//  this function take one matrix and returnTrue if square and identity
bool matrix::isIdentity()
{
    if(!this->isSquare())
    {
        return false;
    }
    else
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if((i==j)&&(data[i][j]!=1))
                {
                    return false;
                }
                else if((i!=j)&&(data[i][j]!=0))
                {
                    return false;
                }
                else if((i==row-1)&&(j==col-1))
                {
                    return true;
                }
            }
        }
    }
}
//************************************************************
void matrix::setCol(int col)
{
    this->col=col;
}
//***********************************************************
void matrix::setRow(int row)
{
    this->row=row;
}
//*************************************************************
void matrix::setData(int** data)
{
    this->data=data;
}
//************************************************************
int matrix::getCol()
{
    return this->col;
}
//****************************************************************
int matrix::getRow()
{
    return this->row;
}
//**************************************************************
int** matrix::getData()
{
    return this->data;
}
//********************************************************************
matrix::~matrix()
{
    //dtor
}















