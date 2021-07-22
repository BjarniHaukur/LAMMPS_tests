module scme_wrapper
    USE, INTRINSIC :: ISO_C_BINDING
    USE scme
    IMPLICIT none

    private
    public scme_c 

    contains
    subroutine scme_c(n_atoms, coords, lattice, fa, u_tot) bind(c, name="scme_c")
        USE, INTRINSIC :: ISO_C_BINDING
        integer(c_int), intent(in)                          :: n_atoms
        real(c_double), intent(in), dimension(n_atoms*3)    :: coords
        real(c_double), intent(in), dimension(3)            :: lattice
        real(c_double), intent(out), dimension(n_atoms*3)   :: fa
        real(c_double), intent(out)                         :: u_tot
        call scme_calculate(n_atoms, coords, lattice, fa, u_tot)
        return
    end subroutine scme_c

end module scme_wrapper