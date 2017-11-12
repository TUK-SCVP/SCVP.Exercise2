#include <systemc.h>
#include "nand.h"

SC_MODULE(toplevel)
{
    nand n1;

    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> Z;

    SC_CTOR(toplevel) : n1("n1")
    {
        n1.A(A);
        n1.B(B);
        n1.Z(Z);

        SC_METHOD(process);
        sensitive << A << B << Z;
    }

    private:

    void process()
    {
        // Small Test:
        A.write(false);
        B.write(false);

        std::cout << (Z.read() ? "true" : "false") << std::endl;

        A.write(true);
        B.write(true);

        std::cout << (Z.read() ? "true" : "false") << std::endl;
    }

};

int sc_main(int argc, char* argv[])
{
    toplevel("toplevel");
    sc_start();
}
