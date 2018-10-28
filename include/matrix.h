// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1
// Program: CS213-2018-A2-T1
// Purpose: header  file which contain haeder of function that impelemented in cpp file
// Author:  Mostafa saied-Mohamed abd elbaset-Rawan mahmoud
// Version: 2.0
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

class matrix
{
    public:
        matrix();
        matrix(int row,int col,int num[]);

        matrix operator+  (matrix mat2);
        matrix operator-  (matrix mat2);
        matrix operator*  ( matrix mat2);
        matrix operator+  ( int scalar);
        matrix operator-  ( int scalar);
        matrix operator*  ( int scalar);
        matrix operator+= ( matrix mat2);
        matrix operator-= ( matrix mat2);
        matrix operator+= ( int scalar);
        matrix operator-= ( int scalar);
        void   operator++ ();
        void   operator-- ();
        bool   operator==(matrix mat2);
        void   operator=(matrix mat2);
       friend istream& operator>> (istream &in ,matrix& mat);
     friend ostream& operator<< (ostream& out,const matrix& mat);
      bool   operator!= ( matrix mat2);
      bool   isSquare   ();
      matrix transpose();
      bool   isSymetric ();
      bool   isIdentity ();
      void setRow(int row);
      void setCol(int col);
      void setData(int **data);
      int **getData();
      int getRow();
      int getCol();
        virtual ~matrix();
 // int **data;

    protected:

    private:
        int row;
        int col;
        int **data;

};

#endif // MATRIX_H
