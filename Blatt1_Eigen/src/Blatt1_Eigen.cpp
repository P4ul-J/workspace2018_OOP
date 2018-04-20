/*! \file Blatt1_Eigen.cpp
 *  \brief Kind of "Hello World" for the Linear Algebra Package "Eigen"
 *
 * This little appetizer can serve as an example of object oriented programming in practice.
 * Eigen is a famous, very useful library of linear algebra routines.
 * Be patient - Eigen is a header library and compilation of this program is slow.
 *
 * Documentation: https://eigen.tuxfamily.org/dox/index.html
 * First  example: https://eigen.tuxfamily.org/dox/classEigen_1_1JacobiSVD.html
 * Second example: https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html
 * Additional examples:  see folder portableDevEnv\Eigen333\demos\ in this package
 *
 */

#include <iostream>     // cout, endl
#include <cstdlib>      // srand()
#include <ctime>        // time()
#include <Eigen/Dense>

int main()
{
	std::srand(static_cast<unsigned int>(time(0)));  // seed of random generator, otherwise random numbers are reproduced
	Eigen::MatrixXf m = Eigen::MatrixXf::Random(3, 2);
	std::cout << "First example: Calculate singular values\nHere is the matrix m:" << std::endl << m << std::endl;
	Eigen::JacobiSVD<Eigen::MatrixXf> svd(m, Eigen::ComputeThinU | Eigen::ComputeThinV);
	std::cout << "Its singular values are:" << std::endl << svd.singularValues() << std::endl;
	std::cout << "Its left singular vectors are the columns of the thin U matrix:" << std::endl << svd.matrixU() << std::endl;
	std::cout << "Its right singular vectors are the columns of the thin V matrix:" << std::endl << svd.matrixV() << std::endl;
	Eigen::Vector3f rhs(1, 0, 0);
	std::cout << "Now consider this rhs vector:" << std::endl << rhs << std::endl;
	std::cout << "A least-squares solution of m*x = rhs is:" << std::endl << svd.solve(rhs) << std::endl;

	// *************************************************************************************
	   Eigen::Matrix3f A;
	   A << 1, 2, 5,
	        2, 1, 4,
	        3, 0, 3;
	   std::cout << " \nSecond example: Calculate rank and basis of column-space and null-space\nHere is the matrix A:\n"
			     << A << std::endl;
	   Eigen::FullPivLU<Eigen::Matrix3f> lu_decomp(A);
	   std::cout << "The rank of A is " << static_cast<int>(lu_decomp.rank()) << std::endl;
	   std::cout << "Here is a matrix whose columns form a basis of the null-space of A:\n"
	        << lu_decomp.kernel() << std::endl;
	   std::cout << "Here is a matrix whose columns form a basis of the column-space of A:\n"
	        << lu_decomp.image(A) << std::endl; // yes, have to pass the original A
}
