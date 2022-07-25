#include <iostream>
#include <stdio.h>
#include "VESCular_ethercat.h"


using namespace std;


/*구초제 만들기*/
int send_data[BYTE_NUM];
Ecat_raw debug;

int main (void)
{
    debug=ethercat_send_cmd("duty",0.1);
    
    cout<<debug.hostype;

    return 0;
}

