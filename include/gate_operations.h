#ifndef QUANTUM_GATES_H
#define QUANTUM_GATES_H

#include <complex.h>  // For complex number operations
#include <math.h> 
#define DIMENSION 2
// Define a struct for a unitary matrix
typedef struct {
    int size;       // size of the matrix (N x N)
    double complex *data;  // pointer to store matrix elements, represented as complex numbers
} s_unitary;

// Function declarations for quantum gates

// Function to create a Hadamard gate (H)
s_unitary *create_hadamard_gate();

// Function to create a Pauli-X gate (X)
s_unitary *create_pauli_x_gate();

// Function to create a Pauli-Y gate (Y)
s_unitary *create_pauli_y_gate();

// Function to create a Pauli-Z gate (Z)
s_unitary *create_pauli_z_gate();

// Function to apply a gate to a qubit state
void apply_gate(s_unitary gate,double complex* alpha, double complex* beta);

#endif // QUANTUM_GATES_H
