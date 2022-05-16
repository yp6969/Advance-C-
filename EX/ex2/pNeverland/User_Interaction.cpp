

#include "User_Interaction.h"
const char space_delimiter = ' ';
string INPUT_SIGN = "-i";
string CONFIG_SIGN = "-c";
string OUTPUT_SIGN = "-o";

void initializing(int size, const char** files){
    ///  initializing first files
    vector<string> input;
    vector<string> input_files;
    string output_file ;
    string config_file ;

    for(int i =1 ; i < size; i++){
        input.push_back(files[i]);
    }

    for(int i = 0 ; i < input.size()  ;  i++){
        /// INPUT FILES
        if( input[i] == INPUT_SIGN){
            i++;
            for(int j = i ; j < input.size() ; j++){
                if(input[j] == CONFIG_SIGN || input[j] == OUTPUT_SIGN) break;
                input_files.push_back(input[j]);
                i = j;
            }
        }
            /// CONFIG FILES
        else if(input[i] == CONFIG_SIGN){
            config_file = input[++i];
        }
            /// OUTPUT FILES
        else if(input[i] == OUTPUT_SIGN){
            output_file = input[++i];
        }
    }
}

void get_input(){
    /// Interaction with user -- simulation control
    string input;

    while(input!="EXIT"){
        vector<string> details;
        input= "";
        cin >> input;
        split_str(input  ,details, space_delimiter );

        /// print to check
        print_input(details);
        ////////

        if(details[0] == "load"){
            /// load details file from user
            string file = details[1];
        }
        else if(details[0] == "outbound"){
            ///get all stations which can be reached in a few steps from the requested  start station
            string source_station = details[1];
//            if(!function){
//                cout<< source_station << "does not exist in the current network. \n";
//            }

        }
        else if(details[0] == "inbound"){
            ///get all stations which can be reached in a few steps from the requested  destination station
            string target_station = details[1];
//            if(!function){
//                cerr<< source_station << "does not exist in the current network. \n";
//            }
        }
        else if(details[0] == "uniExpress"){
            /// get the shortest route between two stations -- without vehicle replacement
            string source_station = details[1];
            string target_station = details[2];
//            if(!function){
//              cerr<< source_station << "does not exist in the current network. \n";
//            }
        }
        else if(details[0] == "multiExpress"){
            /// get the shortest route between two stations -- with vehicle replacement
            string source_station = details[1];
            string target_station = details[2];
//            if(!function){
//                cerr<< source_station << "does not exist in the current network. \n";
//            }
        }
        else if(details[0] == "print"){
            /// print transport network

        }
        else{
            cout << "commend not found\n";
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