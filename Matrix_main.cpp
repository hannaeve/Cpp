#include "Matrix.cpp"
#include "isMatrix.cpp"

int main(){
    Matrix m2("[[2,3][5,6][7,8]]");
    Matrix m3 = m2.transpose();
    Matrix m4(m3);

    m2.printMatrixInfo();
    m3.printMatrix();
    m4.printMatrix();

    std::cout << "\n" << std::endl;

    std::cout << m3.toString() << " and " << m4.toString() << " ";
    if(m3==m4) std::cout << "are equal\n" << std::endl;
    else std::cout << "are not equal\n" << std::endl;

    std::cout << m3.toString() << " + " << m4.toString() << " = ";
    m3+=m4;
    std::cout << m3.toString() << std::endl;
    std::cout << std::endl;

    std::cout << m3.toString() << " and " << m4.toString() << " ";
    if(m3==m4) std::cout << "are equal\n" << std::endl;
    else std::cout << "are not equal\n" << std::endl;

    Matrix m5("[[1,1][2,2][5,5]]");
    Matrix m6("[[3,3,5][4,4,5]]");

    std::cout << m5.toString() << " * " << m6.toString()<< " = ";
    m5*=m6;
    std::cout << m5.toString() << std::endl;

    std::string str = "[[1,2,3][2,3,4]]";
    std::string str2 = "[[a1,2,3][2,3,4]]";

    std::cout << std::endl;
    if(isMatrix(str)) std::cout << str << " is a matrix" << std::endl;
    else std::cout << str << " is not a matrix" << std::endl;

    if(isMatrix(str2)) std::cout << str2 << " is a matrix" << std::endl;
    else std::cout << str2 << " is not a matrix" << std::endl;


return 0;
}

