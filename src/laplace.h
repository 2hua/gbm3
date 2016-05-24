//------------------------------------------------------------------------------
//
//  File:       laplace.h
//
//  Description:   laplace distribution for GBM.
//
//  History:    3/26/2001   gregr created
//              2/14/2003   gregr: adapted for R implementation
//------------------------------------------------------------------------------

#ifndef LAPLACE_H
#define LAPLACE_H

//------------------------------
// Includes
//------------------------------
#include "distribution.h"
#include "locationm.h"
#include <algorithm>
#include <memory>

//------------------------------
// Class definition
//------------------------------
class CLaplace : public CDistribution
{

public:
	//---------------------
	// Factory Function
	//---------------------
	static CDistribution* Create(DataDistParams& distparams);

	//---------------------
	// Public destructor
	//---------------------
	virtual ~CLaplace();

	//---------------------
	// Public Functions
	//---------------------
	void ComputeWorkingResponse(const CDataset& kData,
				const double* kFuncEstimate,
				double* residuals);

	double InitF(const CDataset& kData);

	void FitBestConstant(const CDataset& kData,
				   const double* kFuncEstimate,
		       	   unsigned long num_terminalnodes,
		       	   double* residuals,
		       	   CTreeComps& treecomps);
  
	double Deviance(const CDataset& kData,
					const double* kFuncEstimate,
                    bool is_validationset=false);
  
	double BagImprovement(const CDataset& kData,
			      const double* kFuncEstimate,
			      const double kShrinkage,
			      const double* kFuncEstimateadj);

private:
	//----------------------
	// Private Constructors
	//----------------------
	CLaplace();

	//-------------------
	// Private Variables
	//-------------------
	CLocationM mpLocM_;
};

#endif // LAPLACE_H



