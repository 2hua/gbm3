//////////////////////////////////////////////
//
// File: gbmFunc.h
//
// Author: James Hickey
//
// Description: Functions that are accessible to all of GBM.
//
//////////////////////////////////////////////

#ifndef GBMFUNC_H
#define GBMFUNC_H

#include <Rcpp.h>

namespace GBM_FUNC
{
	int NumGroups(const double* kMisc, int num_training_rows);
	bool has_value(const Rcpp::NumericVector& kVec);
	std::ptrdiff_t PtrShuffler(std::ptrdiff_t n);
}

#endif // GBMFUNC_H
