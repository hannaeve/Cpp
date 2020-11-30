#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

#include "Matrix.h"

Matrix::Matrix(){
    ncol = 0;
    nrow = 0;
    square = false;
    elements = std::vector<std::vector<int>> (0);
}

Matrix::Matrix(const std::string& s){
    int nrow_par=0, ncol_par=0, ncol_c=0, ending=0;
    std::stringstream inputstr(s);
    char c;
    int number;

    inputstr >> c;
    if(c == '['){
            do{
            inputstr >> c;
            if(c == '['){
                std::vector<int> row;
                nrow_par++;
                ncol_c = 1; ending = 0;
                do{
                    inputstr >> number >> c;
                    if(inputstr.good()){
                        row.push_back(number);
                        if(c == ','){ncol_c++;}
                        else{
                            if(c !=']') throw(std::invalid_argument("Invalid init string"));
                        }
                }
                else throw(std::invalid_argument("Invalid init string"));

            }while(c != ']');
            if(nrow_par == 1){ncol_par = ncol_c;}
            if(ncol_c != ncol_par){throw(std::invalid_argument("Invalid init string"));}

            elements.push_back(row);
            }
            if(c == ']') ending++;
        }while(ending == 1);

       inputstr >> c;
        if(!inputstr.eof())
            throw(std::invalid_argument("Invalid init string"));

    }
    else throw(std::invalid_argument("Invalid init string"));

ncol = ncol_par;
nrow = nrow_par;

if(ncol == nrow) square = true;
else square = false;
}

Matrix::Matrix(const Matrix& other){
    nrow = other.nrow;
    ncol = other.ncol;
    square = other.square;

    for(auto& row: other.elements)
    {
        elements.push_back(row);
    }
}

Matrix::~Matrix(){
}

Matrix Matrix::transpose() const{
    Matrix trans;

    trans.ncol = nrow;
    trans.nrow = ncol;
    trans.square = square;
    trans.elements = std::vector<std::vector<int>> (ncol);

    for(int j=0; j<ncol; j++){
        std::vector<int> newrow;
        for(int i=0; i<nrow; i++){
            int elem = elements.at(i).at(j);
            newrow.push_back(elem);
        }
    trans.elements.at(j) = newrow;
    newrow.erase(newrow.begin(), newrow.end());
    }

return trans;
}

Matrix& Matrix::operator+=(const Matrix& other){

   if(ncol != other.ncol && nrow != other.nrow)
        throw(std::invalid_argument("Addition error"));

    for(int i=0; i<nrow; i++){
        std::vector<int> thisRow = elements.at(i);
        std::vector<int> otherRow = other.elements.at(i);
        std::vector<int> sum;

        std::transform(thisRow.begin(), thisRow.end(), otherRow.begin(),
                   std::back_inserter(sum), [](int elem1, int elem2)
                        {return elem1 + elem2;});
        elements.at(i) = sum;
        sum.erase(sum.begin(), sum.end());
    }
}

Matrix& Matrix::operator-=(const Matrix& other){
    if(ncol != other.ncol && nrow != other.nrow)
        throw(std::invalid_argument("Subtraction error"));

    for(int i=0; i<nrow; i++){
        std::vector<int> thisRow = elements.at(i);
        std::vector<int> otherRow = other.elements.at(i);
        std::vector<int> diff;

        std::transform(thisRow.begin(), thisRow.end(), otherRow.begin(),
                   std::back_inserter(diff), [](int elem1, int elem2)
                        {return elem1 - elem2;});
        elements.at(i) = diff;
        diff.erase(diff.begin(), diff.end());
    }

}


Matrix& Matrix::operator*=(const Matrix& other){
    if(ncol != other.nrow)
        throw(std::invalid_argument("Multiplication error"));

    Matrix trans = other.transpose();
    std::vector<int> prod, results;

    for(int i=0; i<nrow; i++){
        for(int j=0; j<other.ncol; j++){
            std::vector<int> thisRow = elements.at(i);
            std::vector<int> otherRow = trans.elements.at(j);

            std::transform(thisRow.begin(), thisRow.end(), otherRow.begin(),
                   std::back_inserter(prod), [](int elem1, int elem2)
                   {return elem1*elem2;});

            int sum=0;
            for(auto& elem: prod){
                sum = sum + elem;
            }
        prod.erase(prod.begin(), prod.end());
        results.push_back(sum);
        }
    elements.at(i) = results;
    results.erase(results.begin(), results.end());
    }

ncol = other.ncol;

if(ncol == nrow)
    square = true;
else
    square = false;
}


bool Matrix::operator==(const Matrix& other) const{
     if(ncol != other.ncol | nrow != other.nrow)
        return false;
    else
    {
        for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
              if(elements.at(i).at(j) != other.elements.at(i).at(j))
                return false;
    }}}
return true;
}

void Matrix::printMatrix(){
    std::cout << toString() << std::endl;

}

std::string Matrix::toString(){
    std::stringstream output;
    output << "[";
        for(auto& row:elements){
            output << "[";
            int ind = 0;
            for(auto& elem: row){
                output << elem;
                if(ind < ncol-1) output << " ";
                ind++;
                }
        output << "]";
        }
    output << "]";

return output.str();
}

void Matrix::printMatrixInfo(){
    std::cout << "The matrix "<< toString()
              << " has " << nrow << " row(s), "
              << ncol << " column(s) and ";
    if(square) std::cout << "it is a square matrix" << std::endl;
    else std::cout << "it is not a square matrix" << std::endl;
}


