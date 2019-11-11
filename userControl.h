#ifndef USER_CONTROL
#define USER_CONTROL

#include "SysParam.h"

#include <cstdio>
#include <cstring>
#include <iostream>

class UserDatabase {
private:
    bool authenticated;
    unsigned char mySuperSecretKey[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c,
                                          0x0d, 0x0e, 0x0f};
    char userDatabase[MAX_USER][NUM_USER_PARAM][MAX_PASSWORD_LENGTH];
    char encryptedUserDatabase[MAX_USER * NUM_USER_PARAM * MAX_PASSWORD_LENGTH];
    char databaseFsPath[100];

    UserDatabase();

    UserDatabase(const UserDatabase &);

    UserDatabase &operator=(const UserDatabase);

public:

    static UserDatabase &getInstance();

    void printDatabase();

    int loadUserDatabase(const char *userDbFileLocation);

};

#endif
