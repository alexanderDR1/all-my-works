#include <iostream>

using namespace std;

typedef struct {
    int n;
    int m;
    float** mat;
} Matrix;

Matrix createMatrix(int m, int n) {
    Matrix matrix;
    // Create matrix in memory
    matrix.mat = new float*[m];

    for(int i = 0; i < m; i++){
        matrix.mat[i] = new float[n];
        for(int j = 0; j < n; j++){
            if(j == i) matrix.mat[i][j] = 1;
            else matrix.mat[i][j] = 0;
        }
    }

    matrix.n = n;
    matrix.m = m;

    return matrix;
}



void printMatrix(Matrix matrix) {
    for(int i = 0; i < matrix.m; i++){
        for(int j = 0; j < matrix.n; j++){
            cout << matrix.mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void TransposeMatrix(Matrix matrix) {
    for(int i = 0; i < matrix.n; i++){
        for(int j = 0; j < matrix.m; j++){
            cout << matrix.mat[j][i] << "\t";
        }
        cout << endl;
    }
}


void mulByScalar(Matrix matrix, int scalar) {
    for(int i = 0; i < matrix.m; i++){
        for(int j = 0; j < matrix.n; j++){
            matrix.mat[i][j] = matrix.mat[i][j] * scalar;
        }
    }
}

void addMartix(Matrix a, Matrix b) {
    if(a.m != b.m || a.n != b.n){
        cout << "you gay" << endl;
        return;
    }

    for(int i = 0; i < a.m; i++){
        for(int j = 0; j < a.n; j++){
            a.mat[i][j] += b.mat[i][j];
        }
    }
}

void multyplication(Matrix a, Matrix b, Matrix c){
     if(c.m != c.n){
        cout << "false" << endl;
        return;
    }

    for(int i = 0; i < a.m; i++){
        for(int j = 0; j < a.n; j++){
               for(int k = 0; k< b.n; k++ ){
               c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
    }
}


int main()
{
    Matrix a = createMatrix(6, 4);
    Matrix b = createMatrix(7, 7);
    printMatrix(a);
    cout << endl;
    a.mat[3][1] = 4;
    mulByScalar(a, 12);
    printMatrix(a);
    cout << endl;
    addMartix(a, b);
    printMatrix(a);
    cout <<endl;
    TransposeMatrix ( a );
    return 0;
}
