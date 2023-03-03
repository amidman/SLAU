#include"../src/tri_diag_matrix.h"
#include"../src/CSR.cpp"
#include<iostream>
#include <gtest/gtest.h>

TEST(matrix, values){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};
    CSR<double> matrix = CSR<double>(values,cols, rows);

    ASSERT_EQ(matrix(0,0),1);
    ASSERT_EQ(matrix(1,0),0);
    ASSERT_EQ(matrix(3,0),0);
    ASSERT_EQ(matrix(-1,0),0);
}

TEST(matrix, out_of_range){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};
    CSR<double> matrix = CSR<double>(values,cols, rows);

    ASSERT_EQ(matrix(3,0),0);
}

TEST(matrix, negative_indexes){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};
    CSR<double> matrix = CSR<double>(values,cols, rows);

    ASSERT_EQ(matrix(-1,0),0);
}

TEST(matrix, mult_by_vect){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};

    std::vector<double> b{1, 2, 3};

    CSR<double> matrix = CSR<double>(values,cols, rows);

    std::vector<double> x = matrix*b;

    ASSERT_EQ(x[0],5);
    ASSERT_EQ(x[1],8);
    ASSERT_EQ(x[2],22);
}