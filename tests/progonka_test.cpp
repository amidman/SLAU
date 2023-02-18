#include<iostream>
#include"../src/progonka.cpp"
#include<gtest/gtest.h>

TEST(progonka, test1){
    int n = 3;
    matrix* M = new matrix(n);

    double a[2] = {1,2};
    double b[3] = {10,11,12};
    double c[2] = {1,2};

    M->a = a;
    M->b = b;
    M->c = c;

    double d[3] = {1,2,3};
    double x[3] = {1,2,3};

    double* res = new double[n];

    d[0] = b[0]*x[0] + c[0]*x[1];
    for(int i=1;i<n-1;i++){
        d[i] = a[i-1]*x[i-1] + b[i]*x[i] + c[i]*x[i+1];
    }
    d[n-1] = a[n-2]*x[n-2]+b[n-1]*x[n-1];

    progonka(M, d, res);

    for(int i=0;i<n;i++){
        EXPECT_FLOAT_EQ(res[i],x[i]);
    }
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}