#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mpi.h>

// these are LAMMPS include files
#include "lammps.h"
#include "input.h"
#include "atom.h"
#include "library.h"

using namespace LAMMPS_NS;

int main(int narg, char **arg)
{
    const char *lmpargv[] {"liblammps", "-log", "none"};
    int lmpargc = sizeof(lmpargv)/sizeof(const char *);

    MPI_Init(&narg, &arg);
    LAMMPS *lmp = new LAMMPS(lmpargc, (char **)lmpargv, MPI_COMM_WORLD);
    lmp->input->file("in.lj");

    printf("\n");
    printf("\n");
    printf("Test\n");
    printf("\n");
    printf("\n");

    lmp->input->one("run 100 post yes");
    delete lmp;
    MPI_Finalize();
    return 0;
}
