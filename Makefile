HOME = /home/bjarni/Documents/Vinna
BUILDDIR = LAMMPS/build/includes/lammps
SRCDIR = LAMMPS/src
SCMEDIR = SCME_OLDMASTER/obj
LMPCC = mpicxx
CC = g++
FC = gfortran
CFLAGS = -O2 -I${HOME}/SCME_OLDMASTER/mod -lstdc++
FFLAGS = -O0 -cpp -pg -I${HOME}/SCME_OLDMASTER/mod/ -I./
MPI = mpirun


run: simple.x
	$(MPI) -np 1 simple.x 1 in.lj
	
main.x: main.o scme_interface.o scme_wrapper.o
	$(LMPCC) -o main.x main.o scme_interface.o scme_wrapper.o -L${HOME}/${SRCDIR} -L${HOME}/${BUILDDIR} ${HOME}/${SCMEDIR}/libscme.a -llammps_mpi -lgfortran
	
	

simple.x: simple.o
	$(LMPCC) -L${HOME}/${SRCDIR} simple.o -llammps -o simple.x

simple.o: simple.cpp
	$(LMPCC) -I${HOME}/${SRCDIR} -c simple.cpp



scme_wrapper.o: scme_wrapper.f90 ${HOME}/${SCMEDIR}/libscme.a
	$(FC) $(FFLAGS) -c scme_wrapper.f90

scme_interface.o: scme_interface.cpp
	$(CC) $(CFLAGS) -c scme_interface.cpp 

main.o: main.cpp
	$(LMPCC) -c -O -I${HOME}/${SRCDIR} -I${HOME}/${LAMMPSDIR} main.cpp


clean:
	rm -f *.o *.x
