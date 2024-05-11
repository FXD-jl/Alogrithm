#include <Eigen/Dense>  
#include <iostream>  
  
int main() {  
    Eigen::MatrixXd m(2, 2);  
    m(0, 0) = 3;  
    m(1, 0) = 2.5;  
    m(0, 1) = -1;  
    m(1, 1) = m(1, 0) + m(0, 1);  
    std::cout << "Here is the matrix m:\n" << m << std::endl;  
  
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(m, Eigen::ComputeThinU | Eigen::ComputeThinV);  
    std::cout << "Its singular values are:\n" << svd.singularValues() << std::endl;  
    return 0;  
} 
