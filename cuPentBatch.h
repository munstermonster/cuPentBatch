// Andrew Gloster
// June 2018
// Header file for cuPentBatch functions

// ---------------------------------------------------------------------
// Define Header
// ---------------------------------------------------------------------

#ifndef PENTFUN_H
#define PENTFUN_H

// ---------------------------------------------------------------------
//  Standard Libraries and Headers
// ---------------------------------------------------------------------



// ---------------------------------------------------------------------
//  Programmer Libraries and Headers
// ---------------------------------------------------------------------



// ---------------------------------------------------------------------
//  Header file functions
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Function to factorise the LHS matrix
// ---------------------------------------------------------------------

__global__ void pentFactorBatch
(
	double* ds,  	// Array containing the lower diagonal, 2 away from the main diagonal. First two elements are 0. Stored in interleaved format.
	double* dl,  	// Array containing the lower diagonal, 1 away from the main diagonal. First elements is 0. Stored in interleaved format.
	double* d, 	 	// Array containing the main diagonal. Stored in interleaved format.
	double* du,	 	// Array containing the upper diagonal, 1 away from the main diagonal. Last element is 0. Stored in interleaved format.
	double* dw,  	// Array containing the upper diagonal, 2 awy from the main diagonal. Last 2 elements are 0. Stored in interleaved format.

	int m,  		// Size of the linear systems, number of unknowns
	int batchCount	// Number of linear systems
);

// ---------------------------------------------------------------------
// Function to solve the Ax = b system of pentadiagonal matrices
// ---------------------------------------------------------------------

__global__ void pentSolveBatch
(
	double* ds, 	// Array containing updated ds after using pentFactorBatch
	double* dl,		// Array containing updated ds after using pentFactorBatch
	double* d,		// Array containing updated ds after using pentFactorBatch
	double* du,		// Array containing updated ds after using pentFactorBatch
	double* dw,		// Array containing updated ds after using pentFactorBatch
	
	double* b,		// Dense array of RHS stored in interleaved format

	int m,  		// Size of the linear systems, number of unknowns
	int batchCount	// Number of linear systems
);

// ---------------------------------------------------------------------
// End of header file functions
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// End of definition
// ---------------------------------------------------------------------

#endif

// ---------------------------------------------------------------------
// End of file
// ---------------------------------------------------------------------
