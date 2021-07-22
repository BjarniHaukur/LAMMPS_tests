#include <cassert>
#include <stdio.h>
#include <iostream>
#include "scme_interface.h"

using namespace std;

extern "C" {
    void scme_c(int *n_atoms, double *coords, double *lattice, double *fa, double *u_tot);
}

SCME::SCME(int n, double *coords, double *box) 
{
    n_atoms = n;
    coordinates = new double[n_atoms*3];
    lattice = new double[3];
    fa = new double[n_atoms*3];
    coordinates = coords;
    lattice = box;
    u_tot = 0;
}

SCME::~SCME() 
{
    // delete[] coordinates;
    // delete[] lattice;
    // delete[] fa;
}

void SCME::CALCULATE() 
{
    scme_c(&n_atoms, getCoords(), getLattice(), getForces(), &u_tot);
} 


