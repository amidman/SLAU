#include"Gauss_zedel.h"

bool converge(std::vector<double> xk, std::vector<double> xkp, int n, double eps){
	double norm = 0;
	for (int i = 0; i < n; i++){
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
    }
	return (norm < eps*eps);
}

std::vector<double> Zedel(CSR<double> matrix, std::vector<double> b, double tolerance){
    std::vector<double> x;
    std::vector<double> p;
    int n = b.size();
    x.reserve(n);
    p.reserve(n);

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
	} while (!converge(x, p, n, tolerance));

    return x;
}