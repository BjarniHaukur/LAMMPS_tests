#include "scme_interface.h"
#include "library.h"
#include "lammps.h"
#include "input.h"
#include <mpi.h>
#include <iostream>

using namespace std;
using namespace LAMMPS_NS;

void scme() {
    int n_atoms = 3;
    double coordinates[n_atoms*3], cell[3];

    coordinates[0] =  0.018;  
    coordinates[1] = -0.739;       
    coordinates[2] =  0.521;      
    coordinates[3] = -0.815;       
    coordinates[4] = -0.673;
    coordinates[5] = -0.592;
    coordinates[6] =  0.000;       
    coordinates[7] =  0.000;
    coordinates[8] =  0.000; 


    cell[0] = 35.000;
    cell[1] = 35.000;
    cell[2] = 35.000;

    // cout << sizeof(coordinates)/sizeof(coordinates[0]) << endl;

    SCME s(n_atoms, coordinates, cell);

    s.CALCULATE();

    cout << "Done" << endl;   
    
}

int main(int argc, char *argv[])
{
    LAMMPS *lmp;
    // custom argument vector for LAMMPS library
    const char *lmpargv[] {"liblammps", "-log", "none"};
    int lmpargc = sizeof(lmpargv)/sizeof(const char *);

    // explicitly initialize MPI
    MPI_Init(&argc, &argv);

    // create LAMMPS instance
    lmp = new LAMMPS(lmpargc, (char **)lmpargv, MPI_COMM_WORLD);
    // output numerical version string
    cout << "LAMMPS version ID: " << lmp->num_ver << endl;

    lmp->input->file("job.lmp");
    // lmp->input->one("run 100 post yes");



    // delete LAMMPS instance
    // stop MPI environment
    delete lmp;
    MPI_Finalize();

    return 0;
}

