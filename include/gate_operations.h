#ifndef QUANTUM_GATES_H
#define QUANTUM_GATES_H

#include <complex.h>  // For complex number operations

// Define a struct to represent a quantum gate
typedef struct {
    double complex matrix[2][2];  // 2x2 matrix to represent the gate
} s_QuantumGate;

// Function declarations for quantum gates

// Function to create a Hadamard gate (H)
s_QuantumGate hadamard_gate();

// Function to create a Pauli-X gate (X)
s_QuantumGate pauli_x_gate();

// Function to create a Pauli-Z gate (Z)
s_QuantumGate pauli_z_gate();

// Function to apply a gate to a qubit state
void apply_gate(s_QuantumGate gate, double complex* alpha, double complex* beta);

#endif // QUANTUM_GATES_H
