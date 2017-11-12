#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"
#include <iostream>
using namespace std;

SC_MODULE(Monitor)
{
    sc_in<bool> A, B, Z;

    void monitor()
    {
        cout << sc_time_stamp()  << "\t" << A << "\t" << B << "\t" << Z <<endl;
    }

    SC_CTOR(Monitor)
    {
        cout << endl <<  "time\tA\tB\tF" << endl;
        SC_METHOD(monitor);
        sensitive << A << B << Z;
        dont_initialize();
    }
};

#endif
