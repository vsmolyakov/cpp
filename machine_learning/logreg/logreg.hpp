#pragma once
#include <Eigen/Dense>
using namespace Eigen;

class lrsgd
{
public:
	lrsgd();
	~lrsgd() {};

	VectorXf sigmoid(VectorXf& a);
	void lr_objective(float& cost, VectorXf& grad, VectorXf& theta);
	void fit(void);
	void generate_data(MatrixXf& X, VectorXi& y);

	int num_iter;       //max number of iterations
	VectorXf theta;     //logistic regression weights
	float lambda;       //regularization parameter
	float cost;         //LR objective
	VectorXf grad;      //gradient of LR objective

	int tau0;           //learning rate parameter
	int kappa;          //learning rate parameter
	VectorXf eta;       //learning rate schedule	

	MatrixXf X;         //input data n x d
	VectorXi y;         //input labels n x 1
};
