#include<vector>

class matrix{
    public:
        matrix(int m){
            a.reserve(n-1);
            b.reserve(n);
            c.reserve(n-1);
            n = m;
        };

        matrix(int m, std::vector<double> a, std::vector<double> b, std::vector<double> c){
            this->a = a;
            this->b = b;
            this->c = c;
            n = m;
        };

        int get_n(){return n;};
        double get_a(int i){return a[i];};
        double get_b(int i){return b[i];};
        double get_c(int i){return c[i];};

    private:
        int n;
        std::vector<double> a;
        std::vector<double> b;
        std::vector<double> c;
};