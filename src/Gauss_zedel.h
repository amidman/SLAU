#include"CSR.h"

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

    do{
		for (int i = 0; i < n; i++){
			p[i] = x[i];
        }
		for (int i = 0; i < n; i++)
		{
			double var = 0;
			for (int j = 0; j < n; j++){
                if(j!=i){var += ((matrix)(i,j) * x[j]);}
            }
			x[i] = (b[i] - var) / (matrix)(i,i);
		}
		int_count++;
	} while (!converge(x, p, tolerance));

    return x;
}