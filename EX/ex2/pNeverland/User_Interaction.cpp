

#include "User_Interaction.h"

const char space_delimiter = ' ';
string INPUT_SIGN = "-i";
string CONFIG_SIGN = "-c";
string OUTPUT_SIGN = "-o";
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


void initializing(int size, const char** files){
    ///  initializing first files
    vector<string> input;
    vector<string> input_files;

    string output_file ;
    string config_file ;

    for(int i =1 ; i < size; i++){
        input.emplace_back(files[i]);
    }

    for(int i = 0 ; i < input.size()  ;  i++){
        /// INPUT FILES
        if( input[i] == INPUT_SIGN){
            i++;
            for(int j = i ; j < input.size() ; j++){
                if(input[j] == CONFIG_SIGN || input[j] == OUTPUT_SIGN) break;
                input_files.push_back(input[j]);
                check_input_file(input[j]);
                set_pNeverland(input[j] );
                i = j;

            }
        }
            /// CONFIG FILES
        else if(input[i] == CONFIG_SIGN){
//            TODO - init configurations
            config_file = input[++i];
        }
            /// OUTPUT FILES
        else if(input[i] == OUTPUT_SIGN){
            output_file = input[++i];
        }
    }
    print_data_container();
    cout << N;
}

void get_input(){
    /// Interaction with user -- simulation control
    string input;
    cout << N;
    while(true){
        vector<string> details;
        input= "";
        getline(cin , input);
        stringstream s(input);
        istream_iterator<std::string> begin(s);
        istream_iterator<std::string> end;
        vector<std::string> data(begin, end);
        //split_str(input  ,details, space_delimiter );
        /// print to check
        print_input(data);
        ////////
        try {
            if (data[0] == "load") {
                /// load details file from user
                check_input_file(data[1]);
                set_pNeverland(data[1]);
                cout << N;
            } else if (data[0] == "outbound") {
                ///get all stations which can be reached in a few steps from the requested  start station
                string source_station = data[1];
                //            if(!function){
                //throw exception("source_station does not exist in the current network. \n");
                //            }

            } else if (data[0] == "inbound") {
                ///get all stations which can be reached in a few steps from the requested  destination station
                string target_station = data[1];
                //            if(!function){
                //                cerr<< source_station << "does not exist in the current network. \n";
                //            }
            } else if (data[0] == "uniExpress") {
                /// get the shortest route between two stations -- without vehicle replacement
                string source_station = data[1];
                string target_station = data[2];
                //            if(!function){
                //              cerr<< source_station << "does not exist in the current network. \n";
                //            }
            } else if (data[0] == "multiExpress") {
                /// get the shortest route between two stations -- with vehicle replacement
                string source_station = data[1];
                string target_station = data[2];
                //            if(!function){
                //                cerr<< source_station << "does not exist in the current network. \n";
                //            }
            } else if (data[0] == "print") {

                cout << "here" << endl;
                /// print transport network

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

void split_str( string const &str,vector <string> &out ,  const char delim)
{
    std::stringstream s(str);
    std::string s2;
    while (std:: getline (s, s2, delim) )
    {
        out.push_back(s2);
    }

}

void print_input(vector <string> &out) {
    for(auto a :out){
        cout << a <<"\n";
    }
}

void print_data_container(){
    for(const auto& e: data_container){
        for(const auto& v: e){
            cout << v << endl;

        }
    }
}

