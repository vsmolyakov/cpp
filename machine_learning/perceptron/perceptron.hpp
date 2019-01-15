#pragma once
#include <Eigen/Dense>
using namespace Eigen;

class perceptron
{
public:
	perceptron();
	~perceptron() {};

	void fit(MatrixXf& X_train, VectorXi& y_train);
	void predict(MatrixXf& X_test, VectorXi& y_test);

	int num_epochs; //number of iterations through the dataset
	float   theta0; //hyperplane offset
	VectorXf theta; //hyperplane coeffs

};