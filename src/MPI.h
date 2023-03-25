#pragma once

#include<vector>
#include"CSR.h"
#include<iostream>

std::vector<double> sub_vec(std::vector<double> a,std::vector<double> b){
    std::vector<double> res(a.size());
    for(int i=0;i<res.size();++i){
        res[i] = a[i]-b[i];
    }
    return res;
}

std::vector<double> operator*(std::vector<double> a, double b){
    std::vector<double> res(a.size());
    for(int i=0;i<a.size();++i){
        res[i] = a[i]*b;
    }
    return res;
}

double norm(std::vector<double> a){
    double max = a[0];
    if(max<0){
            max = -max;
    }
    for(int i=0;i<a.size();++i){
        int x = a[i];
        if(x<0){
            x = -x;
        }
        if(x>max){max=x;}
    }

    return max;
}

std::vector<double> MPI(CSR<double> matrix, std::vector<double> b, double tau, double tolerance){
    std::vector<double> res(b.size());
    std::vector<double> dif(b.size());
    do{
        dif = (sub_vec(matrix*res,b));
        res = sub_vec(res,dif*tau);
    }while(norm(dif) > tolerance);

    return res;
}