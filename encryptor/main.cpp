//
//  main.cpp
//  encryptor
//
//  Created by Elliot Christenson on 2/8/20.
//  Copyright © 2020 Elliot Christenson. All rights reserved.
//

#include <iostream> 
#include "command_parser.h"
#include "encryptor.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    Parser parse_command_line(argc, argv);
    Encryptor encryptor(
        parse_command_line.getInfile(),
        parse_command_line.getOutfile(),
        parse_command_line.isDecrypt(),
        parse_command_line.getKey()
    );
    
    return 0;
}
