#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

/**
/brief
    Check if string is in a correct form for creating matrix object
*/
bool isMatrix(std::string mStr){
    std::stringstream ss(mStr);
    char c;
    int i=0, row_end=0, row_begin=0, ncol=1, ncol_c=1;
    bool endmatrix = false;
    ss >> c;
    if(mStr.substr(0, 2) == "[[" && mStr.substr(mStr.length()-2, 2) == "]]"){
        while(ss >> c){
            if(c == '['){
                row_begin++; bool endrow = false;
                while(!endrow){
                    ss >> c;
                    if(c == ']'){
                        row_end++;
                        if(ncol != ncol_c){
                            //std::cout << "Return false because ncol != ncol_c" << std::endl;
                            return false;
                            }
                        ncol_c = 1;
                        endrow = true;
                        if(ss.peek() == ']') break;
                        else if(ss.peek() != '[') return false;

                    }else if(c == ','){
                        if(row_begin == 1) ncol++;
                        ncol_c++;
                    }else if(isdigit(c))continue;
                    else{
                        //std::cout << "Return false because of " << c << std::endl;
                        return false;}
                    }
            }
            else if(c == ']') break;
            else{
                //std::cout << "Return false because of something is wrong with the string" << std::endl;
                return false;
            }}
    }else{
        //std::cout << "Return false because of wrong begin or end" << std::endl;
        return false;
    }
    if(row_begin != row_end){
        //std::cout << "Return false because of number of end ] and begin [ not match"<< std::endl;
        return false;
    }
    else
        return true;
}
