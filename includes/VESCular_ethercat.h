#include "VESCular_Command.h"

#define BYTE_NUM 32

struct Ecat_raw
{
    int hostype;
    int command;
    int vesc_id;
    float set_value;
};


Ecat_raw ethercat_send_cmd( char *cmd , float value );

int* packet_encoding(int temp[], int comm , Ecat_raw data );

int* packet_encoding(int temp[], int comm , Ecat_raw data ){
    temp[0]=2;  //start_frame = 2

    if (comm = COMM_CUSTOM_APP_DATA)
    {

        int command_frame[5] = {comm, data.hostype, 1 ,data.vesc_id, data.command};
        float comm_value = data.set_value;
    }
    else if(comm = COMM_FORWARD_CAN)
    {
        int command_frame[3] = {comm, data.vesc_id, data.command};
        float comm_value = data.set_value;
    }
    else
    {
        int command_frame[1] = {data.command};
    }


}

Ecat_raw ethercat_send_cmd( char *cmd , float value ){
    Ecat_raw temp ; 
    temp.hostype = ETHERCAT;
    temp.vesc_id = 0xFF;

    int command = 0;
    int comm_set_cmd = COMM_CUSTOM_APP_DATA;
    
    
    int hostype = ETHERCAT;
    float set_value = 0;
    
    if (cmd == "duty")
    {
        temp.command = COMM_SET_DUTY;
        temp.set_value = value ;
    }
    else if (cmd == "current")
    {
        temp.command = COMM_SET_CURRENT;
        temp.set_value = value ;
    }
    else if (cmd == "current_brake")
    {
        temp.command = COMM_SET_CURRENT_BRAKE;
        temp.set_value = value ;
    }
    else if (cmd == "release")
    {
        temp.command = COMM_SET_CURRENT;
        temp.set_value = 0 ;
    }
    else
    {
        temp.command = 0;
        temp.set_value = 0 ;
    }
    
   return temp;

}