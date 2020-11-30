#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

/**
* \class Matrix
* \brief Class for Matrix object
*/
class Matrix{
    private:
        int ncol, nrow;
        bool square;
        std::vector<std::vector<int>> elements;

    public:
        /**
        * \brief Default constructor
        */
        Matrix();

        /**
        * \brief Parametric constructor
        * \param s String representation of matrix of the form [[a11,..,a1n]...[an1,....,ann]]
        */
        Matrix(const std::string& s);

        /**
        * \brief Copy constructor
        * \param m Other Matrix object to copy
        */
        Matrix(const Matrix& other);

        /**
        * \brief Destructor
        */
        virtual ~Matrix();

        /**
        * \brief Converts rows into columns and columns into rows
        * \return Transpose of matrix
        */
        Matrix transpose() const;

        /**
        * \brief Adds this Matrix with other
        * \param m Other Matrix
        * \return  This Matrix added by other
        */
        Matrix& operator+=(const Matrix& other);

        /**
        * \brief This Matrix is subtracted from another Matrix
        * \param m Other Matrix
        * \return  This Matrix subtracted by other
        */
        Matrix& operator-=(const Matrix& other);

        /**
        * \brief Multiplies this Matrix with other
        * \param m Other Matrix
        * \return  This Matrix multiplied by other
        */
        Matrix& operator*=(const Matrix& other);

        /**
        * \brief Compares two matrix
        * \param m Other matrix
        * \return  Return true if matrix are equal
        */
        bool operator==(const Matrix& other) const;

        /**
        * \brief Convert Matrix to string
        * \return  String
        */
        std::string toString();

        /**
        * \brief Print matrix
        */
        void printMatrix();

        /**
        * \brief Print information about matrix (number of rows and columns, and type)
        */
        void printMatrixInfo();
};

#endif
