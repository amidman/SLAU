#include<iostream>
#include"../src/progonka.cpp"


int main(){
    int n = 3;
    matrix* M = new matrix(n);

    double* d = new double[n];
    double* x = new double[n];

    for(int i=0;i<n-1;i++){
        M->a[i] = i+1;
        M->b[i] = i+10;
        M->c[i] = i+1;
        d[i] = i+1;
    }
    M->b[n-1] = n+10;
    d[n-1] = n;
    

    //a[0]=5;
    //a[1]=1;
    //b[0]=2;
    //b[1]=4;
    //b[2]=-3;
    //c[0]=-1;
    //c[1]=2;
    //d[0]=3;
    //d[1]=6;
    //d[2]=2;
    progonka(M, d, x);

    std::cout<<"a b c d x"<<std::endl;
    for(int i=0;i<n;i++){
        std::cout<<M->a[i]<<" "<<M->b[i]<<" "<<M->c[i]<<" "<<d[i]<<" "<<x[i]<<std::endl;
    }

    return 0;
}