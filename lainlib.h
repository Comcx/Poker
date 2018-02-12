
#ifndef LAINLIB_H
#define LAINLIB_H

#define OK 1
#ifndef ERROR
	#define ERROR -1
#endif
#define STOP 0

/**
* Stream control tools
* @author: C++ STL
* @namespace: std
*
*/
#include <iostream>
#include <sstream>
#include <fstream>

/**
* Containers
* @author: C++ STL
* @namespace: std
* @include: vector, list, deque, string, stack, queue
*			map, set
*/
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>

using std::string;
/**
* General algorithms
* @author: C++ STL
* @namespace: std
*
*/
#include <algorithm>

/**
* Memory mangement
* @author: C++ STL
* @namespace: std
*
*/
#include <memory>

/**
* Useful
*
*/
#include <utility>
#include <cctype>
#include <cmath>
#include <ctime>
#include <windows.h>


/**
* The Eigen math calculation tool
* if you want to use Eigen, remember to use 'Eigen' namespace
* @namespace: Eigen
* @author: Eigen team
*
*/
#include "Eigen\Core"
// example of using namespace, this pre-definition shall be useful
// if you do not like these pre-definitions, you can erase them.
#define Matrix Eigen::Matrix
#define Array Eigen::Array

#define matrix_d Eigen::MatrixXd
#define array_d Eigen::ArrayXXd
/**
* Grammar sugar of MatrixXT(XT: dimension and type)
* Types: i(int), f(float), d(double)
*
*/
#define matrix_(rd, cd) Matrix<double, rd, cd>
#define array_(rd, cd) Array<double, rd, cd>





#endif














