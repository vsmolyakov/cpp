#include "logreg.hpp"
#include <cmath>
#include <random>
#include <fstream>
#include <Eigen/Dense>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace Eigen;

mt19937 rng;

lrsgd::lrsgd()
{
	//set training parameters
	num_iter = 20;
	lambda = (float) 1e-4;
	theta = VectorXf::Random(2, 1);
	cost = 0.0;
	grad = VectorXf::Zero(2, 1);

	//generate training data
	generate_data(X, y);

	//learning rate schedule
	tau0 = 10;
	kappa = 1;  //(0.5, 1]
	eta = VectorXf::Zero(num_iter,1);
	for (int i = 0; i < num_iter; i++)
	{
		eta[i] = (float) pow((tau0 + i), (-kappa));
	}	
}

VectorXf lrsgd::sigmoid(VectorXf& a)
{
	return (1 + (-1*a.array()).exp()).inverse();  // 1/(1 + exp(-a))
}

void lrsgd::lr_objective(float& cost, VectorXf& grad, VectorXf& theta)
{
	float n = (float) y.size();
	VectorXi y01 = (y.array() + 1) / 2;  //y \in {0, 1}
	VectorXf h = X * theta;
	VectorXf mu = sigmoid(h);

	mu = mu.cwiseMax((float) 1e-7);       //bound away from zero: max(mu, eps)
	mu = mu.cwiseMin((float)(1 - 1e-7));  //bound away from one:  min(mu, 1-eps)

	ArrayXf t1 = y01.array().cast<float>() * mu.array().log();
	ArrayXf t2 = (1 - y01.array().cast<float>()) * ((1 - mu.array()).log());
	cost = -(t1 + t2).sum() / n;  //NLL
	cost += lambda * theta.norm();  //regularizer
	//cout << "cost: " << cost << endl;

	grad = X.transpose() * (mu - y01.cast<float>()) + 2 * lambda * theta;  //gradient of LR objective
	//cout << "grad norm: " << grad.norm() << endl;
}

void lrsgd::fit()
{
	VectorXf obj_hist = VectorXf::Zero(num_iter, 1);
	VectorXf theta_norm_hist = VectorXf::Zero(num_iter, 1);

	for (int i = 0; i < num_iter; ++i)
	{
		lr_objective(cost, grad, theta);
		theta = theta - eta[i] * grad;
		
		cout << "grad: " << endl << grad << endl;
		cout << "theta: " << endl << theta << endl;

		obj_hist[i] = cost;
		theta_norm_hist[i] = theta.norm();
		printf("iteration: %d, cost: %.4f, eta: %.4f, theta_norm: %.4f, grad_norm: %.4f\n", i, obj_hist[i], eta[i], theta.norm(), grad.norm());
	}
}

void lrsgd::generate_data(MatrixXf& X, VectorXi& y)
{
	int n = 32, d = 2;
	X = MatrixXf::Zero(n, 2);
	y = VectorXi::Zero(n, 1);

	Vector2f mu1(1, 1), mu2(-1, -1);
	Vector2f pik(0.4, 0.6), cpik(0.4, 1.0); //cumsum(pik)

	cout << "mu1: " << endl << mu1 << endl;
	cout << "mu2: " << endl << mu2 << endl;

	uniform_real_distribution<float> dis01(0, 1);
	Vector2f xn(0, 0);

	for (int i = 0; i < n; i++)
	{
		float z01 = dis01(rng);
		//cout << "z01: " << z01 << endl;

		if (z01 < cpik[0])
		{
			X.row(i) = xn.setRandom() + mu1;
			y(i) = 1;
		}
		else
		{
			X.row(i) = xn.setRandom() + mu2;
			y(i) = -1;
		}
	}

	cout << "y: " << endl << y << endl;
	cout << "X: " << endl << X << endl;

	ofstream fout("./input.txt");
	if (fout.is_open())
	{
		fout << X.size() << endl;
		fout << X << endl;
		fout << y.size() << endl;
		fout << y << endl;
	}
	else
		cout << "Unable to open fout.\n";
}


int main()
{
    cout << "Binary Logistic Regression\n"; 
	lrsgd LR = lrsgd();
	LR.fit();
	cout << "Learned weights: " << endl << LR.theta << endl;

	cout << "Predicting on training data: " << endl;
	VectorXf mu = LR.X * LR.theta;
	VectorXf h = LR.sigmoid(mu);
	VectorXf y_pred = 2.0 * (h.array() >= 0.5).cast<float>() - 1.0;
	float y_err = (y_pred - LR.y.cast<float>()).sum() / (float) y_pred.size();
        cout << "LR classification error: " << y_err << endl;

	return 0;
}
