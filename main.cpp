// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  shrouq hussein hussein
// ID:20170127
// Date:    5 october 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);



// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
matrix operator+(matrix mat1, matrix mat2);				    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   /// change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
matrix& operator++ (matrix& mat);   	// Add 1 to each element ++mat
matrix& operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	/// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       /// and return istream to allow cascading input

ostream& operator<< (ostream& out,matrix mat);

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;
 // createMatrix (4, 2, data1, mat1);
  //createMatrix (2, 3, data2, mat2);
  //createMatrix (4, 2, data3, mat3);


//cin>>mat1>>mat3;                     /// istream

  cout << mat1 << endl;
  //cout << mat2 << endl;
  cout << mat3 << endl;



  //cout <<( mat1+= mat3 += mat3) << endl;
 // cout << (mat1 -= mat3)<<endl<<endl;                   /// += matrix & -=



 /////////

   // --mat1;                       /// -- &++
   // cout << mat1 << endl;
  //cout << (--mat1) << endl;



//cout<<(mat3-=2)<<endl;    /// scalar

  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {

  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      mat.data[i][j] = num[i * col + j];
    }}


}

///overloading += operator to deal with matrix
matrix operator+= (matrix& mat1, matrix mat2){


assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));

for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){

        mat1.data[i][j]=(mat1.data[i][j])+ mat2.data[i][j];
    }
}
return mat1;
}

///overloading -= operator to deal with matrix
matrix operator-= (matrix& mat1, matrix mat2){


assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));

for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){

        mat1.data[i][j]=(mat1.data[i][j])- mat2.data[i][j];
    }
}
return mat1;
}

///overloading ++( prefix ) operator to deal with matrix
matrix& operator++ (matrix& mat){

 for(int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){

        mat.data[i][j]++;
    }
}
 return mat;
}


///overloading --( prefix ) operator to deal with matrix
matrix& operator--(matrix& mat){


for(int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){

        mat.data[i][j]--;
    }



}
return mat;
}

///overloading += operator to add an integer to matrix
matrix operator += (matrix& mat, int scalar){

  for(int i=0;i<mat.row;i++){
      for(int j=0;j<mat.col;j++){

        mat.data[i][j]=(mat.data[i][j]+scalar);
                  }
             }
return mat;

}


///overloading -= operator to subtruct an integer from matrix
matrix operator-= (matrix& mat, int scalar){

    for(int i=0;i<mat.row;i++){
      for(int j=0;j<mat.col;j++){

        mat.data[i][j]=(mat.data[i][j]-scalar);
                  }
             }
return mat;

}

///overloading >> operator to input matrix
istream& operator>> (istream& in, matrix& mat){
    cout<<"enter number of rows: "<<endl;
    cin>>mat.row;
     cout<<"enter number of columns: "<<endl;
   cin >>mat.col;
    mat.data = new int* [mat.row];
    for(int i=0;i<mat.row;i++){
             mat.data[i] = new int [mat.col];
        for(int j=0;j<mat.col;j++){
            cin>>mat.data[i][j];
        }
    }

return in;
    for(int i=0;i<mat.row;i++){
        delete[]mat.data[i];
    }


}


ostream& operator<< (ostream& out, matrix mat) {
  for (int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){
        out<<mat.data[i][j]<<"  ";
    }
    out<<endl;
  }
  return out;
}

matrix operator+(matrix mat1, matrix mat2){


 assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));
  matrix mat3;
  int mat3data[mat1.row*mat1.col]={};

 createMatrix (mat1.row, mat1.col,mat3data,  mat3);

for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){

        mat3.data[i][j]=(mat1.data[i][j])+ mat2.data[i][j];
    }
}



return mat3;


}

