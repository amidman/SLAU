#include<vector>
#include"CSR.h"

template <typename T>
std::vector<T>& operator+(std::vector<T>& a, const std::vector<T>& b)
{
}

template <typename T>
std::vector<T>& operator-(std::vector<T>& a, const std::vector<T>& b)
{
}

template <typename T>
std::vector<T>& operator*(std::vector<T>& a, const double& b)
{
}

template <typename T>
std::vector<T> sub_vec(std::vector<T>& a,std::vector<T>& b){
}

std::vector<double> MPI(CSR<double> matrix, std::vector<double> b, double tau, double tolerance){
}