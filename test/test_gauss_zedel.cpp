#include"../src/Gauss_zedel.h"
#include<iostream>
#include <gtest/gtest.h>

TEST(matrix, values){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};

    std::vector<double> b{1, 2, 3};

    CSR<double> matrix = CSR<double>(values,cols,rows);

    std::vector<double> res = Zedel(matrix,b,0.1);
}