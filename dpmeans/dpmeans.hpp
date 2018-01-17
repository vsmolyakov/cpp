#pragma once

#include <Eigen/Dense>
#include <time.h>
#include <vector>

using namespace Eigen;
using namespace std;


class dpmeans
{

public:
	dpmeans(const Ref<const MatrixXf>& X);  //X is n x d
	~dpmeans() {};

	float kpp_init(const Ref<const MatrixXf>& X, int k);
	VectorXi dpmeans_fit(const Ref<const MatrixXf>& X);
	float compute_nmi(const Ref<const VectorXi>& z1, const Ref<const VectorXi>& z2);
	void display_params();

private:
	int K; //infered automatically
	int K_init; //for lambda k++ initiliazation
	int n; //number of points
	int d; //dimension

	VectorXi z;   //assignments
	MatrixXf mu;  //K x d means
	VectorXf nk;  //number of points in cluster k
	VectorXf pik; //mixture proportions
	float lambda; //dp-means hyper-parameter
    
	int max_iter;
	vector<double> obj;
	vector<double> em_time;
	
};
