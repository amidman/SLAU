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
    for(int i=0;i<a.size();++i){
        if(a[i]>max){max=a[i];}
    }
    return max;
}

std::vector<double> MPI(CSR<double> matrix, std::vector<double> b, double tau, double tolerance){
    std::cout<<"1"<<std::endl;
    std::vector<double> res;
    std::vector<double> dif;
    res.reserve(b.size());
    dif.reserve(b.size());
    std::cout<<"2"<<std::endl;
    do{
        res = matrix*res;
        dif = (sub_vec(matrix*res,b))*tau;
        res = sub_vec(res,dif);
    }while(norm(dif) < tolerance);

    return res;
}