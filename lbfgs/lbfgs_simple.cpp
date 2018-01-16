#include <Eigen/Core>
#include "LBFGS.h"
#include <iostream>

using Eigen::VectorXd;
using namespace LBFGSpp;
using namespace std;

double quadratic(const VectorXd& x, VectorXd& grad)
{
    //compute f(x) and grad(x)
    const int n = x.size();
    VectorXd d(n);
    for (int i=0; i<n; ++i)
    {
        d[i] = i;
    }

    double f = (x-d).squaredNorm();
    grad = 2.0 * (x-d);

    return f;
}

int main()
{
    const int n = 10; //dimension
    LBFGSParam<double> param;
    LBFGSSolver<double> solver(param);

    VectorXd x = VectorXd::Zero(n);
    double fx; // f(x)
    int niter = solver.minimize(quadratic, x, fx);

    cout << niter << " iterations" << endl;
    cout << "x = \n" << x.transpose() << endl;
    cout << "f(x) = " << fx << endl;

    return 0;
}
