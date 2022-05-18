

#include "User_Interaction.h"

const char space_delimiter = ' ';
const string INPUT_SIGN = "-i";
const string OUTPUT_SIGN = "-o";
const string CONFIG_SIGN = "-c";
const string BUS ="bus";
const string TRAM = "tram";
const string SPIRNTER = "sprinter";
const string RAIL = "rail";

Neverland N;
vector<vector<string>> data_container;

void set_pNeverland(string file_name){
    /// GET VEHICLE TYPE
    int pos;
    for(int i = 0 ; i < file_name.size() ; i++)
    {
        if( !isalpha(file_name[i])){
            pos = i;
            break;
        }
    }
    string vehicle = file_name.substr(0 , pos);
    for(auto d : data_container){
        N.add_route(d[0] , d[1], stoi(d[2]) , vehicle);
        ///  CRATE OBJECT BY DATA AND TYPE
    }
    data_container.clear();
}

void init_input_file(string file){
    check_input_file(file);
    set_pNeverland(file);
}

void initializing(int size, const char** files){
    ///  initializing first files
    vector<string> input;
    for(int i =1 ; i < size; i++){
        input.emplace_back(files[i]);
    }
    try {
        for (int i = 0; i < input.size(); i++) {
            /// INPUT FILES
            if (input[i] == INPUT_SIGN) {
                i++;
                for (int j = i; j < input.size(); j++) {
                    if (input[j] == CONFIG_SIGN || input[j] == OUTPUT_SIGN) break;
                    init_input_file(input[j]);
                    i = j;
                }
            }
                /// CONFIG FILES
            else if (input[i] == CONFIG_SIGN) {
                N.update_config(input[++i]);
            }

                /// OUTPUT FILES
            else if (input[i] == OUTPUT_SIGN) {
                ///TODO - print to file
            }
        }
    }
    catch(NeverlandException e) { ///////ERROR ON INIT THE PROGRAM , EXIT -- TODO CHECK IF NEED TO DELETE N
        cout << e.what();
        exit(0);
    }
}

void get_input(){
    /// Interaction with user -- simulation control
    string input;
    while(true){
        vector<string> details;
        input= "";
        getline(cin , input);
        stringstream s(input);
        istream_iterator<std::string> begin(s);
        istream_iterator<std::string> end;
        vector<std::string> data(begin, end);
        try {
            if (data[0] == "load") {
                /// load details file from user
                init_input_file(data[0]);

            } else if (data[0] == "outbound") {
                ///get all stations which can be reached in a few steps from the requested  start station
                ///TODO - OUTBOUND

            } else if (data[0] == "inbound") {
                ///get all stations which can be reached in a few steps from the requested  destination station
                ///TODO - inbound

            } else if (data[0] == "uniExpress") {
                /// get the shortest route between two stations -- without vehicle replacement
                    if(data.size() != 3){
                        throw NeverlandException("ERROR : need to stations \n");
                    }
                    ///TODO - uniExpress

            } else if (data[0] == "multiExpress") {
                /// get the shortest route between two stations -- with vehicle replacement
                if(data.size() != 3){
                    throw NeverlandException("ERROR : need to stations \n");
                }
                ///TODO - multiExpress
            }
            else if (data[0] == "print") {
                cout << N;
            }
            else if(data[0] == "EXIT" || data[0] == "exit"){
                break;
            }
            else{
                cout << "commend not found\n";
            }
        }
        catch(NeverlandException e){
            cerr << e.what() << endl;
        }

    }
}


