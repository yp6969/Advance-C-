#include <iostream>
#include "User_Interaction.h"




int main(int argc , const char** argv) {
    try {
        if(argc<2){
            cerr << "ERROR: need one file to initializing";
            exit(-1);
        }
        initializing(argc , argv);
        get_input();
    }
    catch (NeverlandException e){
        cout << e.what();
    }

    return 0;
}


/*TODO - adding rout to the Graph:
 * get the route file,
 * extract the names of the stations and the time
 * send them to the add rout func of the Neverland
 */


/**
 * load <car_name_<number>>.dat
 * <source_node> <TAB> <target_node> <TAB> <duration>
 *
 *
*/