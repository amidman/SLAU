#include<vector>
#include"../src/MPI.h"
#include <gtest/gtest.h>
#include<iostream>

TEST(MPI,test){
    std::cout<<"gfds";

    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};

    std::vector<double> b{1, 2, 3};

    CSR<double> matrix = CSR<double>(values,cols, rows);
    std::cout<<"gfds";
    std::vector<double> res;
    res = MPI(matrix,b,0.01,0.01);
}