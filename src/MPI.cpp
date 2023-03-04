#include<vector>
#include"CSR.h"

template <typename T>
std::vector<T>& operator+(std::vector<T>& a, const std::vector<T>& b)
{
    std::vector<T> res = a;
    for(int i=0;i<res.size();++i){
        res[i]+=b[i];
    }
    return res;
}

template <typename T>
std::vector<T>& operator-(std::vector<T>& a, const std::vector<T>& b){
    std::vector<T> res = a;
    for(int i=0;i<res.size();++i){
        res[i]+=b[i];
    }
    return res;
}

template <typename T>
std::vector<T> sub_vec(std::vector<T>& a,std::vector<T>& b){
    std::vector<T> res = a;
    for(int i=0;i<res.size();++i){
        res[i] = res[i]-b[i];
    }
    return res;
}

template <typename T>
std::vector<T>& operator*(std::vector<T>& a, const double& b)
{
    std::vector<T> res = a;
    for(int i=0;i<res.size();++i){
        res[i] = res[i]*b;
    }
    return res;
}

std::vector<double> MPI(CSR<double> *matrix, std::vector<double> b, double tau, double tolerance){
    std::vector<double> res;
    res.reserve(b.size());
    
    double err = 0;
    do{
        err = tau*(sub_res((*matrix)*res,b));
        res = sub_res(res,err);
    }while(err < tolerance);

    return res;
}