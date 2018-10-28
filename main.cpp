#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    int num1[6]={1,2,3,4,5,6};
    int num2[6]={5,6,7,8,9,10};
    int num3[9]={1,0,0,0,1,0,0,0,1};
    int num4[9]={1,7,3,7,4,-5,3,-5,6};
    //int row=2;
   // int col=2;
    matrix mat1(2,2,num1);
    matrix mat2(3,2,num2);
    matrix mat3(3,3,num3);
    matrix mat4(3,3,num4);     //symatric matrix for test
  //  mat1.setCol(2);
   // mat1.setRow(row);
//mat1=mat2;
 //   mat2.data[0][0]=10;
  //  cin>>mat1;
   // cout<<mat1;


    return 0;
}









