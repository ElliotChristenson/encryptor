//
//  command_parser.h
//  encryptor
//
//  Created by Elliot Christenson on 2/8/20.
//  Copyright © 2020 Elliot Christenson. All rights reserved.
//

#ifndef command_parser_h
#define command_parser_h

#include <iostream> //std::cerr and std::cerr
#include <ctype.h> //isprint function
#include <stdlib.h>
#include <string.h>

using namespace std;

class Parser {

    private:
    
        string encryption_key;
        string infile;
        string outfile;
        bool is_decrypt;

    public:
        
        Parser() {}
        
        Parser(int optc, char *optv[]) {
            getOptions(optc, optv);
        }
    
        void getOptions(int option_count, char *option_values[]) {
            for (int item=1; item<option_count; item++) {
                if (checkOptions(option_values[item],option_values[item+1])) {
                    item++;
                }
            }
            
        }

        int checkOptions(char *flag, char *value) {
            if ((flag[0] == '-') && (value[0] != '-')) {
                switch (flag[1]) {
                    case 'd':
                        is_decrypt = true;
                        encryption_key = string(value);
                        break;
                    case 'e':
                        is_decrypt = false;
                        encryption_key = string(value);
                        break;
                    case 'f':
                        infile = string(value);
                        break;
                    case 'o':
                        outfile = string(value);
                        break;
                }
                return 1;
            } else {
                return 0;
            }
        }
    
        string getInfile() {
            return infile;
        }
    
        string getOutfile() {
            return outfile;
        }
    
        string getKey() {
            return encryption_key;
        }
    
        bool isDecrypt() {
            return is_decrypt;
        }

          
};


#endif /* command_parser_h */
