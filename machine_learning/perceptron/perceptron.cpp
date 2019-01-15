#include "perceptron.hpp"
#include <cmath>
#include <time.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

mt19937 rng;

perceptron::perceptron()
{
	num_epochs = 5;
}

void perceptron::fit(MatrixXf& X_train, VectorXi& y_train)
{
	cout << "fit" << endl;
	int n = X_train.rows(), dim = X_train.cols();
	
	theta0 = 0.0; 
	theta = VectorXf::Zero(dim, 1);
	
	uniform_int_distribution<int> unif(0, n-1);
	int k = 1;
	for (int epoch = 0; epoch < num_epochs; ++epoch)
	{
		for (int i = 0; i < n; ++i)
		{
			int idx = unif(rng); //sample random point
			if (y_train[idx] * (theta.dot(X_train.row(idx)) + theta0) <= 1.0) //hinge loss
			{
				float eta = pow(k + 1, -1); k++;  //update learning rate
				theta = theta + eta * y_train[idx] * X_train.row(idx).transpose();  //update theta
				theta0 = theta0 + eta * y_train[idx]; //update intercept
				cout << "eta: " << eta << endl;
			}
		}
		cout << "epoch: " << epoch << endl;
		cout << "theta: " << endl << theta << endl << " theta0: " << theta0 << endl;
	}
}
void perceptron::predict(MatrixXf& X_test, VectorXi& y_test)
{
	cout << "predict" << endl;
	int n = X_test.rows(), dim = X_test.cols();

	int num_errors = 0;
	for (int i = 0; i < n; ++i)
	{
		if (y_test[i] * (theta.dot(X_test.row(i)) + theta0) < 0)
		{
			num_errors++;
		}
	}
	float yerr = (float)num_errors / float(n);
	cout << "Perceptron classification error: " << yerr << endl;
}


void load_iris(MatrixXf& X_train, VectorXi& y_train)
{
	//read-in labels
	int cnt = 0;
	string line;
	ifstream fin1("./data/iris_labels.txt");
	if (fin1.is_open())
	{
		while (getline(fin1, line))
		{
			y_train(cnt) = stoi(line);
			cnt++;
		}
		fin1.close();
	}
	else cout << "Unable to open fin1\n";
	cout << "y = " << endl << y_train << endl;
	cout << "y.size = " << y_train.size() << endl;

	//read-in data
	cnt = 0;
	int nrows = 0;
	int ncols = 0;
	ifstream fin2("./data/iris_data.txt");
	if (fin2.is_open())
	{
		fin2 >> nrows >> ncols;
		for (int row = 0; row < nrows; row++)
			for (int col = 0; col < ncols; col++)
			{
				float num = 0.0;
				fin2 >> num;
				X_train(row, col) = num;
			}
		fin2.close();
	}
	else cout << "Unable to open fin2\n";
	cout << "X = " << endl << X_train << endl;
	cout << "X.size = " << X_train.rows() << " x " << X_train.cols() << endl;
}

int main()
{
    cout << "Perceptron Algorithm" << endl;

	//load iris	
	int nrows = 0, ncols = 0;
	string line;
	ifstream fin1("./data/iris_data.txt");
	if (fin1.is_open())
	{
		fin1 >> nrows >> ncols;
		fin1.close();
	}
	else cout << "Unable to open data file\n";
	cout << "nrows = " << nrows << endl;
	cout << "ncols = " << ncols << endl;

	MatrixXf X_train = MatrixXf::Zero(nrows, ncols); //training data n x d
	VectorXi y_train = VectorXi::Zero(nrows);        //training labels n x 1

	load_iris(X_train, y_train);

	perceptron P = perceptron();
	P.fit(X_train, y_train);     
	P.predict(X_train, y_train); //TODO: predict on test data

	return 0;
}
