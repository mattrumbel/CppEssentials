#include "ECSquareMat.h"

using namespace std;

ECSquareMat::ECSquareMat (int nDim) {
    for (int i = 0; i < nDim; i++) {
        vector<int> v(nDim, 0);
        listMatEntries.push_back(v);
    }
};

ECSquareMat::ECSquareMat (const ECSquareMat &rhs) {
    listMatEntries = rhs.listMatEntries;
};

ECSquareMat::~ECSquareMat() {};

ECSquareMat& ECSquareMat::operator=(const ECSquareMat &rhs) {
    if (this == &rhs) return *this;
    else { 
        listMatEntries = rhs.listMatEntries;
        return *this;
    }
};

int ECSquareMat::GetDimension() const {
    return listMatEntries.size();
};

void ECSquareMat::SetValAt(int nRow, int nCol, int val) {
    listMatEntries[nRow][nCol] = val;
};

int ECSquareMat::GetValAt(int nRow, int nCol) const {
    return listMatEntries[nRow][nCol];
};

ECSquareMat ECSquareMat::operator+(const ECSquareMat &rhs) {
    ECSquareMat new_mat(rhs.GetDimension());

    for (int nRow = 0; nRow < rhs.GetDimension(); nRow++) {
        for (int nCol = 0; nCol < rhs.GetDimension(); nCol++) {
            new_mat.SetValAt(nRow, nCol, this->GetValAt(nRow, nCol) + rhs.GetValAt(nRow, nCol));
        }
    } return new_mat;
};

ECSquareMat ECSquareMat::operator*(const ECSquareMat &rhs) {
    ECSquareMat new_mat(rhs.GetDimension());

    int value;
    
    for (int i = 0; i < rhs.GetDimension(); i++) {
        for (int j = 0; j < rhs.GetDimension(); j++) {
            value = 0;
            for (int k = 0; k < rhs.GetDimension(); k++) {
                value += this->GetValAt(i, k) * rhs.GetValAt(k, j);
            }
            new_mat.SetValAt(i, j, value);
        }
    }
    return new_mat;
};