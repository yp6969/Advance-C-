

#include "Validation.h"

const string BUS ="bus";
const string TRAM = "tram";
const string SPIRNTER = "sprinter";
const string RAIL = "rail";


int check_file_name(string file_name){
    int pos;
    for(int i = 0 ; i < file_name.size() ; i++)
    {
        if( !isalpha(file_name[i])){
            pos = i;
            break;
        }
    }
    string vehicle = file_name.substr(0 , pos);
    if(vehicle != BUS && vehicle != TRAM && vehicle != SPIRNTER && vehicle != RAIL  ){
        cerr << "ERROR: file name to current";
        return 0;
    }
    return 1;
}




void  check_input_file(string file_name , vector<vector<string>>& data_container)
{
    /*
     * CHECK IF FILE NAME IS VALID
     * TRY TO OPEN FILE
     * TAKE EACH LINE AND SPLIT TO --> SOURCE STATION , DESTINATION STATION , TIME ,
     * */

    if(!check_file_name(file_name)) ///IF FILE NAME NOT VALID
    {
        return ;
    }

    ifstream my_file(file_name);             /// OPEN FILE
    if(!my_file){
        cerr <<" ERROR: file cannot open\n";
        ///TODO -- CHECK IF THIS THE FIRST FILE
    }

    /// SPLIT FILE DATA
    string line;
    int time;
    while(getline(my_file , line)){
        stringstream s(line);
        istream_iterator<std::string> begin(s);
        istream_iterator<std::string> end;
        vector<std::string> data(begin, end);

        if(data.size() != 3 ){
            cerr << "ERROR: NEED ONLY 3 ARGUMENT IN THE FILE.\n";
        }
        for(char c : data[2]){           /*CHECK IF THE TIME IS A NUMBER */
            if(!isdigit(c)){
                cerr << "ERROR: time is not valid";
                return;
            }
        }
        /// STATION LENGTH MAX = 32
        if((data[0].size() > 32 || data[0].size() == 0 ) || (data[1].size() > 32 || data[1].size() == 0 ) ){
            cerr << "ERROR: time is not valid";
            return;
        }
        time = stoi(data[2]);
        if(time < 0){
            throw NeverlandException("ERROR: time is not valid");
        }
        data_container.push_back(data);
        /// DATA = [ STRING SOURCE STATION , STRING DESTINATION STATION , INT  TIME ]
    }

    my_file.close();
}



