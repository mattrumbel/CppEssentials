#include <iostream>
#include "ECSquareMat.h"

using namespace std;

int main() {

    ECSquareMat mat1(2);
    mat1.SetValAt(0,0,1);
    mat1.SetValAt(0,1,2);
    mat1.SetValAt(1,0,3);
    mat1.SetValAt(1,1,4);
    cout << mat1.GetValAt(0, 0) << endl;
    cout << mat1.GetValAt(0, 1) << endl;
    cout << mat1.GetValAt(1, 0) << endl;
    cout << mat1.GetValAt(1, 1) << endl;

    cout << "Before copy transfer" << endl;
    ECSquareMat mat2 = mat1;
    cout << "After copy transfer" << endl;
    mat2.SetValAt(0,1,3);
    mat2.SetValAt(1,0,2);
    cout << mat2.GetValAt(0, 1) << endl;
    cout << mat2.GetValAt(1, 0) << endl;

    /*
    ECSquareMat mat3 = mat1+mat2;
    cout << mat3.GetDimension() << endl;
    cout << mat3.GetValAt(0,0) << endl;
    cout << mat3.GetValAt(0,1) << endl;
    cout << mat3.GetValAt(1,0) << endl;
    cout << mat3.GetValAt(1,1) << endl;

    ECSquareMat mat4 = mat1*mat2;
    cout << mat4.GetDimension() << endl;
    cout << mat4.GetValAt(0,0) << endl;
    cout << mat4.GetValAt(0,1) << endl;
    cout << mat4.GetValAt(1,0) << endl;
    cout << mat4.GetValAt(1,1) << endl;
    */
    /*
    ECSquareMat mat1(2);
mat1.SetValAt(0,0,1);
mat1.SetValAt(0,1,2);
mat1.SetValAt(1,0,3);
mat1.SetValAt(1,1,4);
ECSquareMat mat2 = mat1;
mat2.SetValAt(0,1,3);
mat2.SetValAt(1,0,2);
ECSquareMat mat3 = mat1+mat2;
ASSERT_EQ(mat3.GetDimension(), 2);
ASSERT_EQ(mat3.GetValAt(0,0),2);
ASSERT_EQ(mat3.GetValAt(0,1),5);
ASSERT_EQ(mat3.GetValAt(1,0),5);
ASSERT_EQ(mat3.GetValAt(1,1),8);
ECSquareMat mat4 = mat1*mat2;
ASSERT_EQ(mat4.GetDimension(), 2);
ASSERT_EQ(mat4.GetValAt(0,0),5);
ASSERT_EQ(mat4.GetValAt(0,1),11);
ASSERT_EQ(mat4.GetValAt(1,0),11);
ASSERT_EQ(mat4.GetValAt(1,1),25);
YOUR CODE'S OUTPUT
*/


    return 1;
}