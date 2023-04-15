#include<vector>
#include"../src/Gradient_descent.h"
#include <gtest/gtest.h>
#include<iostream>

TEST(Gradient_descent_fast,test){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};

    std::vector<double> res{1, 2, 3};

    CSR<double> matrix = CSR<double>(values,cols,rows);
    std::vector<double> b = matrix*res;
    std::vector<double> x;
    double tolerance = 0.001;
    x = Gradient_descent_fast(matrix,b,tolerance);

    EXPECT_NEAR(x[0],res[0],tolerance);
    EXPECT_NEAR(x[1],res[1],tolerance);
    EXPECT_NEAR(x[2],res[2],tolerance);
}