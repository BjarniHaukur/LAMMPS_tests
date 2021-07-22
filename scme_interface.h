#ifndef SCME_INTERFACE_H
#define SCME_INTERFACE_H

class SCME
{
    private:
        int n_atoms;
        double *coordinates;
        double *lattice;
        double *fa;
        double u_tot;

    public:
        SCME(int n, double *coords, double *lattice);
        ~SCME();

        void CALCULATE();
        double* getCoords() {return coordinates;}
        double* getLattice() {return lattice;}
        double* getForces() {return fa;}
        double* getEnergy() {return &u_tot;}

    
};

/**
 * The cpp wrapper for the SCME Fortran source code
 * @param n_atoms   - the number of atoms, 4-byte integer
 * @param coords    - array that contains the xyz positions of all the atoms, 
 *                    it´s size is n_atoms*3 and contains 8-byte doubles
 * @param lattice   - array that contains the size of the simulation space
 * @param fa        - array that contains the xyz force components of all the atoms,
 *                    it´s size is n_atoms*3 and contains 8-byte doubles
 * @param u_tot     - the total energy of the system, 8-byte double
 * Must be extern "c" for linking
 */
extern "C" void scme_c(int *n_atoms, double *coords, double *lattice, double *fa, double *u_tot);

#endif