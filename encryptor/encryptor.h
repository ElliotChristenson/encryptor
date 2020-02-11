//
//  encryptor.h
//  encryptor
//
//  Created by Elliot Christenson on 2/9/20.
//  Copyright © 2020 Elliot Christenson. All rights reserved.
//

#ifndef encryptor_h
#define encryptor_h

#include <fstream>

using namespace std;

class Encryptor {
    private:
        char *orig_file_mem = nullptr;
        char *new_file_mem = nullptr;
    
    public:
    
        long readFile(string filename) {
            
            streampos file_size;

            ifstream infile (filename, ios::in|ios::binary|ios::ate);
            if (infile.is_open()) {
                file_size = infile.tellg();
                orig_file_mem = new char[file_size];
                infile.seekg(0, ios::beg);
                infile.read(orig_file_mem, file_size);
                infile.close();
            }
            return file_size;
        }
    
        void encrypt(string old_filename, string new_filename, string encryption_key) {
            long size = readFile(old_filename);

            new_file_mem = new char[size];
            int file_index = 0;
            const char *key = encryption_key.c_str();
            unsigned long int keylen = strlen(key);
            while (file_index < size) {
                for (int key_index = 0; key_index < keylen; key_index++) {
                    new_file_mem[file_index+key_index] = orig_file_mem[file_index+key_index] ^ key[key_index];
                }
                file_index += keylen;
            }
            ofstream outfile (new_filename, ios::out|ios::binary);
            if (outfile.is_open()) {
                outfile.write(new_file_mem, size);
                outfile.close();
            }
        }
        void decrypt(string old_filename, string new_filename, string encryption_key) {
            encrypt(old_filename, new_filename, encryption_key);
        }
    
        Encryptor() {}
        Encryptor(string old_file, string new_file, bool is_decrypt, string encryption_key) {
            if (is_decrypt) {
                decrypt(old_file, new_file, encryption_key);
            } else {
                encrypt(old_file, new_file, encryption_key);
            }
        }
    
};

#endif /* encryptor_h */
