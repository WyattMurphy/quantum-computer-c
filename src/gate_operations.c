#include <stdio.h>
#include <stdlib.h>

#include "../include/gate_operations.h"

// Init and allocate space for unitary matrix
s_unitary *create_unitary_matrix()
{
	s_unitary *matrix = (s_unitary *)malloc(sizeof(s_unitary));
	if (!matrix)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}
	matrix->size = DIMENSION;
	matrix->data = (double complex *)malloc(DIMENSION * DIMENSION * sizeof(double complex));
	if (!matrix->data)
	{
		fprintf(stderr, "Memory allocation for matrix data failed.\n");
		free(matrix);
		exit(1);
	}
	return matrix;
}

// Free the memory for a unitary
void free_unitary_matrix(s_unitary *matrix)
{
	if (matrix)
	{
		free(matrix->data);
		free(matrix);
	}
}

// Function to print unitary
void print_unitary_matrix(s_unitary *matrix)
{
	// Loop for row 
	for (int i = 0; i < matrix->size; i++)
	{
		printf("| "); // Row border
		// Loop for Column
		for (int j = 0; j < matrix->size; j++)
		{
			// Print each complex number (real, imaginary)
			printf("(%f, %f)", creal(matrix->data[i * matrix->size + j]), cimag(matrix->data[i * matrix->size + j]));
			if (j < matrix->size - 1)
			{
				printf(", "); // Add a comma if not last element in row
			}
		}
		printf(" |\n"); // End with border
	}
}

/*Define hadamard gate*/
s_unitary *create_hadamard_gate()
{
	s_unitary *hadamard = create_unitary_matrix();

	double scale = 1.0 / sqrt(2); // normalization factor 

	// Fill data
	hadamard->data[0] = scale + 0.0 * I;  // (0,0) = 1/sqrt(2)
	hadamard->data[1] = scale + 0.0 * I;  // (0,1) = 1/sqrt(2)
	hadamard->data[2] = scale + 0.0 * I;  // (1,0) = 1/sqrt(2)
	hadamard->data[3] = -scale + 0.0 * I; // (1,1) = -1/sqrt(2)

	return hadamard;
}

// Create pauli_y unitary (0 ,  1)
//						  (1 ,  0)
s_unitary *create_pauli_x_gate()
{
	s_unitary *pauli_x = create_unitary_matrix();
	// Fill data
	pauli_x->data[0] = 0;  // (0,0) = 0
	pauli_x->data[1] = 1;  // (0,1) = 1
	pauli_x->data[2] = 1;  // (1,0) = 1
	pauli_x->data[3] = 0; // (1,1) = 0

	return pauli_x;
}

// Create pauli_zunitary (1 ,  0)
//						 (0 , -1)
s_unitary *create_pauli_z_gate()
{
	s_unitary *pauli_z = create_unitary_matrix();

	//Fill data 
	pauli_z->data[0] = 1;  // (0,0) = 1
	pauli_z->data[1] = 0;  // (0,1) = 0
	pauli_z->data[2] = 0;  // (1,0) = 0
	pauli_z->data[3] = -1; // (1,1) = -1
}

// Create pauli_y unitary (0 , -I)
//						  (I ,  0)
s_unitary *create_pauli_y_gate()
{
	s_unitary *pauli_y = create_unitary_matrix();

	//Fill data 
	pauli_y->data[0] = 0;  // (0,0) = 0
	pauli_y->data[1] = -I;  // (0,1) = -I
	pauli_y->data[2] = I;  // (1,0) = I
	pauli_y->data[3] = 0; // (1,1) = 0
}

int main()
{
	s_unitary *hadamard = create_hadamard_gate();

	// Print matrix
	print_unitary_matrix(hadamard);

	// Free the memory when done
	free_unitary_matrix(hadamard);

	return 0;
}
