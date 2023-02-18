struct matrix{
    int n;
    double* a;
    double* b;
    double* c;

    matrix(int m){
        a = new double[m-1];
        b = new double[m];
        c = new double[m-1];
        n = m;
    };

    matrix(int m,double* a,double* b,double* c){
        this->a = a;
        this->b = b;
        this->c = c;
        n = m;
    };
};

void progonka(matrix* M, double* d, double* x){
    int n = M->n;
    double* p = new double[n];
    double* q = new double[n];

    p[0] = -M->c[0]/M->b[0];
    q[0] = d[0]/M->b[0];

    for(int i=1;i<n;i++){
        double z = (M->a[i-1]*p[i-1]+M->b[i]);
        p[i] = -M->c[i]/z;
        q[i] = (d[i]-M->a[i-1]*q[i-1])/z;
    }

    /*for(int i=0;i<n-1;i++){
        std::cout<<p[i]<<" "<<q[i]<<std::endl;
    }*/

    x[n-1]=q[n-1];

    for(int i=n-2;i>=0;i--){
        //x[i] = (d[i]-a[i]*q[i])/(a[i]*p[i]+b[i]);
        x[i] = p[i]*x[i+1]+q[i];
    }
}