#pragma once

#include"CSR.h"
#include"operators.h"

bool converge(std::vector<double> xk, std::vector<double> xkp, double eps){
	double norm = 0;
    int n = xk.size();
	for (int i = 0; i<n; ++i){
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
    }
	return (norm < eps*eps);
}

std::vector<double> Zedel(CSR<double> matrix, std::vector<double> b, double tolerance){
    int n = b.size();
	std::vector<double> x(n);
    std::vector<double> p(n);

    int int_count = 0;

	std::vector<double> Db(n);
    do{
		for (int i = 0; i < n; i++){
			p[i] = x[i];
        }
		    std::vector<double> res(n);
			double diag = 0;
			for (int i = 0; i < n; i++){
				Db[i] = 0;
        	}
            for (int i = 0; i < n; ++i) {
                for (int j = matrix.rows[i]; j < matrix.rows[i+1]; ++j) {
					int k = matrix.cols[j];
					if(k!=i){
                    	res[i] += matrix.values[j] * p[k];
					}else{
						if(matrix.values[j]!=0){
							diag = 1/matrix.values[j];
						}
						Db[i] = diag*b[i];
					}
                }
				res[i] = res[i]*diag;
            }
			x = Db-res;
		int_count++;
    	
	} while (!converge(x, p, tolerance));

    return x;
}


std::vector<double> Zedel_sym(CSR<double> matrix, std::vector<double> b, double tolerance){
    int n = b.size();
	std::vector<double> x(n);
    std::vector<double> p(n);

    int int_count = 0;

	std::vector<double> Db(n);
    do{
		for (int i = 0; i < n; i++){
			p[i] = x[i];
        }
		    std::vector<double> res(n);
			double diag = 0;
			for (int i = 0; i < n; i++){
				Db[i] = 0;
        	}
            for (int i = 0; i < n; ++i) {
                for (int j = matrix.rows[i]; j < matrix.rows[i+1]; ++j) {
					int k = matrix.cols[j];
					if(k!=i){
                    	res[i] += matrix.values[j] * p[k];
					}else{
						if(matrix.values[j]!=0){
							diag = 1/matrix.values[j];
						}
						Db[i] = diag*b[i];
					}
                }
				res[i] = res[i]*diag;
            }
			x = Db-res;

			for (int i = n-1; i >= 0; --i) {
                for (int j = matrix.rows[i]; j < matrix.rows[i+1]; ++j) {
					int k = matrix.cols[j];
					if(k!=i){
                    	res[i] += matrix.values[j] * x[k];
					}else{
						if(matrix.values[j]!=0){
							diag = 1/matrix.values[j];
						}
						Db[i] = diag*b[i];
					}
                }
				res[i] = res[i]*diag;
            }
			x = Db-res;
		int_count++;
		std::cout<<norm(matrix*x-b)<<std::endl;
	} while (!converge(x, p, tolerance));
	//} while (norm(matrix*x-b) > tolerance);

    return x;
}

std::vector<double> iter_for_GZ(CSR<double> matrix, std::vector<double> x, std::vector<double> b){
	int n = b.size();
    std::vector<double> p(n);
	std::vector<double> Db(n);

	for (int i = 0; i < n; i++){
		p[i] = x[i];
    }
	std::vector<double> res(n);
	double diag = 0;
	for (int i = 0; i < n; i++){
		Db[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = matrix.rows[i]; j < matrix.rows[i+1]; ++j) {
			int k = matrix.cols[j];
			if(k!=i){
            	res[i] += matrix.values[j] * p[k];
			}else{
				if(matrix.values[j]!=0){
					diag = 1/matrix.values[j];
				}
				Db[i] = diag*b[i];
			}
        }
		res[i] = res[i]*diag;
    }
	x = Db-res;

	return x;
}

std::vector<double> Zedel_sym_cheb(CSR<double> A, std::vector<double> b, double tolerance, double ro){
    std::vector<double> y0(b.size(), 0);
    std::vector<double> y_1 = iter_for_GZ(A, y0, b);

    std::vector<double> y(b.size());
    std::vector<double> solve = A*y_1-b;

    double nu0 = 1;
    double nu1 = 1/ro;
    int count = 0;

    while (norm(solve) > tolerance){

        y_1 = iter_for_GZ(A, y_1, b);
        y = 2*nu1/ro*y_1 - nu0*y0;
        nu0 = 2/ro*nu1 - nu0;
        y = y / nu0;

        y0 = y_1;
        y_1 = y;

        std::swap(nu0, nu1);

        solve = A*y-b;
        count++;

    }

    return solve;
}