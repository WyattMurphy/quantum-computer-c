#ifndef QUANTUM_H
#define QUANTUM_H

#include<complex.h>


// Define a struct for the qubit
// qubit represnted as linear combination of basis {0,1} states with coefficents alpha, beta
typedef struct {
    double complex alpha;  // Amplitude for |0⟩ state
    double complex beta;   // Amplitude for |1⟩ state
} s_qubit;

// Function declarations
void init_qubit( s_qubit*, double complex alpha, double complex beta);
void display_qubit(const s_qubit *q);
void normalize_qubit(s_qubit *q);

#endif // QUANTUM_H