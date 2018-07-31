#include "dpmeans.hpp"
#include <iostream>
#include <limits>
#include <random>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <fstream>
#include <vector>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

mt19937 rng;

dpmeans::dpmeans(const Ref<const MatrixXf>& X)
{
	K = 1;
	K_init = 4;
	n = X.rows();
	d = X.cols();
	z = VectorXi::Zero(n);        
	mu = MatrixXf::Zero(K, d);    
	
	nk = VectorXf::Zero(K);
	pik = VectorXf::Ones(K);
		
    //init mu
	mu.row(0) = X.colwise().sum() / (float) n;

	cout << "mu = " << endl << mu << endl;
    //init lambda
	lambda = kpp_init(X, K_init);

	max_iter = 100;
	vector<double> obj(max_iter, 0);
	vector<double> em_time(max_iter, 0);
}

float dpmeans::kpp_init(const Ref<const MatrixXf>& X, int k)
{
	// k++ init 
	// lambda is max distance to k++ means
	float lambda = 0.0;

	int n = X.rows();
	int d = X.cols();
	MatrixXf mu = MatrixXf::Zero(k, d);

	VectorXf dist = VectorXf::Ones(n);
	VectorXf pdist = VectorXf::Zero(n);
	dist = dist * numeric_limits<float>::max();

	uniform_int_distribution<int> dis0n(0,n-1);
	uniform_real_distribution<float> dis01(0, 1);
	int idx = dis0n(rng);
	
	mu.row(0) = X.row(idx);
	MatrixXf D = MatrixXf::Zero(n, d);
	
	for (int i = 1; i < k; ++i)
	{
		D = X - mu.row(i - 1).replicate(n, 1);
		dist = dist.cwiseMin(D.cwiseProduct(D).rowwise().sum());
		//cout << "X = " << endl << X << endl;
		//cout << "mu = " << endl << mu << endl;
		//cout << "dist = " << endl << dist << endl;

		//sample discrete
		pdist = dist / dist.sum();

		for (int j = 1; j < pdist.size(); ++j)
		{
			pdist[j] = pdist[j] + pdist[j - 1];  //cumsum
		}

		int pidx = 0;
		float z01 = dis01(rng);
		for (int item = 0; item < pdist.size(); ++item)
		{
			if (z01 < pdist[item])
			{
				pidx = item;
				break;
			}
		}
		mu.row(i) = X.row(pidx);	
		lambda = dist.maxCoeff();
	}

	return lambda;
}

VectorXi dpmeans::dpmeans_fit(const Ref<const MatrixXf>& X)
{

	int n = X.rows(); 
	int d = X.cols();
	int K = this->K;
	int max_iter = this->max_iter;

	double obj_tol = 1e-3;
	cout << "running dp-means..." << endl;

	//cout << "X = " << endl << X << endl;
	for (int iter = 0; iter < max_iter; ++iter)
	{
		clock_t tic = clock();
		MatrixXf dist = MatrixXf::Zero(n, K);
		
		//assignment step
		MatrixXf Xm = MatrixXf::Zero(n, d);
		for (int k = 0; k < K; ++k)
		{
			Xm = X - mu.row(k).replicate(n, 1);
			dist.col(k) = Xm.cwiseProduct(Xm).rowwise().sum();			
		}
		//cout << "mu = " << endl << mu << endl;
		//cout << "dist = " << endl << dist << endl;

		//update labels
		VectorXf dmin = VectorXf::Zero(n);
		for (int ridx = 0; ridx < n; ++ridx)
		{
			MatrixXf::Index minIndex;
			dmin(ridx) = dist.row(ridx).minCoeff(&minIndex);
			z(ridx) = minIndex;
		}
		//cout << "dmin = " << endl << dmin << endl;
		//cout << "z = " << endl << z << endl;
		//cout << "lambda = " << endl << lambda << endl;

		VectorXi dmin_idx = VectorXi::Zero(n);
		for (int ridx = 0; ridx < n; ++ridx)
		{
			if (dmin(ridx) > lambda)
				dmin_idx(ridx) = 1;
		}
		int num_new = dmin_idx.sum();
		//cout << "num_new = " << endl << num_new << endl;

		if (num_new > 0)
		{
			//create a new cluster for points
			//with dmin > lambda
			K = K + 1;
			//cout << "K = " << endl << K << endl;

			VectorXf new_mean = VectorXf::Zero(d);
			for (int ridx = 0; ridx < n; ++ridx)
			{
				// if assigned to new cluster
				if (dmin_idx(ridx) > 0)
				{
					z(ridx) = K-1;  // cluster labels: [0,...,K-1]
					new_mean = new_mean + X.row(ridx).transpose();
				}
			}
			//cout << "z = " << endl << z << endl;
			mu.conservativeResize(mu.rows() + 1, NoChange);
			//cout << "new mean: " << endl << new_mean << endl;
			//cout << "num_new: " << endl << num_new << endl;
			mu.row(K-1) = new_mean / (float) num_new;  // add new mean		

			MatrixXf Xm = MatrixXf::Zero(n, d);
			Xm = X - mu.row(K-1).replicate(n, 1);
			dist.conservativeResize(NoChange, dist.cols() + 1);
			dist.col(K-1) = Xm.cwiseProduct(Xm).rowwise().sum(); //add dist to new mean			
			//cout << "dist = " << endl << dist << endl;

		}

		//update step
		nk = VectorXf::Zero(K);
		mu = MatrixXf::Zero(K, d);
		//for (int ridx = 0; ridx < z.size(); ++ridx) { nk(z(ridx))++; } //histogram
		for (int k = 0; k < K; ++k)
		{
			nk(k) = (float) (z.array() == k).count();

			for (int ridx = 0; ridx < z.size(); ++ridx)
			{
				if (z(ridx) == k)
				{
					mu.row(k) = mu.row(k) + X.row(ridx);
				}

			}
			mu.row(k) = mu.row(k) / nk(k);
		}
		pik = nk / nk.sum();
		cout << "mu = " << endl << mu << endl;
		cout << "nk = " << endl << nk << endl;
		cout << "pik = " << endl << pik << endl;

		//compute objective
		int kidx = 0;
		double suml2sq = 0.0;
		for (int ridx = 0; ridx < n; ++ridx)
		{
			kidx = z(ridx);
			suml2sq = suml2sq + dist(ridx, kidx);
		}
		suml2sq += lambda * K;
		obj.push_back(suml2sq);
		cout << "obj = " << endl << suml2sq << endl;

		//check convergence
		if (iter > 0 && abs(obj.at(iter) - obj.at(iter - 1)) < obj_tol *obj.at(iter))
		{
			cout << "converged in " << iter << " iterations." << endl;
			break;
		}

		clock_t toc = clock();
		double elapsed_sec = double(toc - tic) / (double) CLOCKS_PER_SEC;
		cout << "elapsed sec = " << endl << elapsed_sec << endl;
		em_time.push_back(elapsed_sec);		
	}

	this->K = K;

	return z;
}

float dpmeans::compute_nmi(const Ref<const VectorXi>& z1, const Ref<const VectorXi>& z2)
{
	// compute normalized mutual information
	float nmi = 0.0;

	int n = z1.size();

	//compute number of unique
	//labels in z1 and z2
	unordered_set<int> s1;
	unordered_set<int> s2;

	int item;
	item = 0;
	for (int idx = 0; idx < n; ++idx)
	{
		item = z1(idx);
		s1.insert(item);
	}

	item = 0;
	for (int idx = 0; idx < n; ++idx)
	{
		item = z2(idx);
		s2.insert(item);
	}

	int k1 = s1.size();
	int k2 = s2.size();

	VectorXf nk1 = VectorXf::Zero(k1);
	VectorXf nk2 = VectorXf::Zero(k2);
	for (int idx = 0; idx < k1; ++idx)
	{
		nk1(idx) = (float) (z1.array() == idx).count();
	}
	for (int idx = 0; idx < k2; ++idx)
	{
		nk2(idx) = (float) (z2.array() == idx).count();
	}

	VectorXf pk1 = nk1 / (float)nk1.sum();
	VectorXf pk2 = nk2 / (float)nk2.sum();

	MatrixXi nk12 = MatrixXi::Zero(k1, k2);
	for (int idx1 = 0; idx1 < k1; ++idx1)
	{
		for (int idx2 = 0; idx2 < k2; ++idx2)
		{
			VectorXi b1 = VectorXi::Zero(n);						
			b1 = (z1.array() == idx1).select(VectorXi::Ones(n), VectorXi::Zero(n));

			VectorXi b2 = VectorXi::Zero(n);
			b2 = (z2.array() == idx2).select(VectorXi::Ones(n), VectorXi::Zero(n));

			VectorXi b1b2 = b1.cwiseProduct(b2);		

			nk12(idx1, idx2) = b1b2.sum();
		}
	}
	MatrixXf pk12 = nk12.cast<float>() / n;
	cout << "nk12 = " << endl << nk12 << endl;
	cout << "pk12 = " << endl << pk12 << endl;

	VectorXf logpk1 = (pk1 + numeric_limits<float>::epsilon()*VectorXf::Ones(k1)).array().log();
	VectorXf logpk2 = (pk2 + numeric_limits<float>::epsilon()*VectorXf::Ones(k2)).array().log();
	MatrixXf logpk12 = (pk12 + numeric_limits<float>::epsilon()*MatrixXf::Ones(k1, k2)).array().log();

	float Hx = -pk1.dot(logpk1);
	float Hy = -pk2.dot(logpk2);
	float Hxy = -pk12.cwiseProduct(logpk12).sum();

	float MI = Hx + Hy - Hxy;
	nmi = MI / (float) (0.5*(Hx + Hy));

	return nmi;
}


void dpmeans::display_params()
{
	cout << "K = " << this->K << endl;
	cout << "K_init = " << this->K_init << endl;
	//cout << "Labels: " << endl << this->z << endl;
	cout << "Means: " << endl << this->mu << endl;
	cout << "Counts: " << endl << this->nk << endl;
	cout << "Proportions: " << endl << this->pik << endl;
	cout << "Lambda: " << this->lambda << endl;	
}

void load_iris(Ref<MatrixXf> X, Ref<VectorXi> y)
{	
	
	//read-in labels
	int cnt = 0;
	string line;
	ifstream fin2("./data/iris_labels.txt");
	if (fin2.is_open())
	{
		while (getline(fin2, line))
		{
			y(cnt) = stoi(line);
			cnt++;
		}
		fin2.close();
	}
	else cout << "Unable to open fin2\n";
	//cout << "y = " << endl << y << endl;
	//cout << "y.size = " << endl << y.size() << endl;

	//read-in data
	cnt = 0;
	int nrows = 0;
	int ncols = 0;
	ifstream fin3("./data/iris_data.txt");
	if (fin3.is_open())
	{
		fin3 >> nrows >> ncols;
		for (int row = 0; row < nrows; row++)
			for (int col = 0; col < ncols; col++)
			{
				float num = 0.0;
				fin3 >> num;
				X(row, col) = num;
			}
		fin3.close();
	}
	else cout << "Unable to open fin3\n";
	//cout << "X = " << endl << X << endl;
	
}

int main(int argc, char* argv[])
{	
	
	//generate data
	//int rows = 150, cols = 4;
	//MatrixXf X = MatrixXf::Random(rows, cols);
	
	//load iris	
	int nrows = 0;
	int ncols = 0;
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

	VectorXi y = VectorXi::Zero(nrows);
	MatrixXf X = MatrixXf::Zero(nrows, ncols);

	load_iris(X,y);
	//cout << "y = " << endl << y << endl;
	//cout << "X = " << endl << X << endl;
	
	dpmeans dp(X);
	dp.display_params();

	VectorXi z;
	z = dp.dpmeans_fit(X);
	//cout << "z = " << endl << z << endl;
	
	float nmi;
	nmi = dp.compute_nmi(z, y);
	cout << "nmi = " << endl << nmi << endl;

	return 0;
}

