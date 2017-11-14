#pragma once

#include<Eigen/Dense>
#include<time.h>
#include<vector>

using namespace Eigen;
using namespace std;


class dpmeans
{

public:
	dpmeans(const Ref<const MatrixXf>& X);  //n x d
	//~dpmeans();

	float kpp_init(const Ref<const MatrixXf>& X, int k);
	VectorXi dpmeans_fit(const Ref<const MatrixXf>& X);
	float compute_nmi(const Ref<const VectorXi>& z1, const Ref<const VectorXi>& z2);
	void display_params();

	int K;
	int K_init;
	int n;
	int d;

	VectorXi z;
	MatrixXf mu;  //K x d
	float sigma;
	VectorXf nk;
	VectorXf pik;
	float lambda;
    
	int max_iter;
	vector<double> obj;
	vector<double> em_time;

private:
	
};