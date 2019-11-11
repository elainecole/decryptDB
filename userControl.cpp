#include "userControl.h"
#include "aes.h"
#include <iostream>

UserDatabase::UserDatabase() {
    authenticated = false;
}

UserDatabase &UserDatabase::getInstance() {
    static UserDatabase singleton;
    return singleton;
}

int UserDatabase::loadUserDatabase(const char *userDbFileLocation) {
    memset(userDatabase, 0, MAX_USER * NUM_USER_PARAM * MAX_PASSWORD_LENGTH);

    // save the database name, such that we can reload them later
    strcpy(databaseFsPath, userDbFileLocation);

    int dbsize;
    FILE *fptr;
    fptr = fopen(userDbFileLocation, "rb");

    if (!fptr) {
        //printf("cannot find database at location %s\n", userDbFileLocation);
        return -1;
    }

    // read the first four bytes of the file to get the size of the database
    fscanf(fptr, "%d", &dbsize);

    // read the binary database back into database
    fread(encryptedUserDatabase, 1, dbsize, fptr);

    // close the file
    fclose(fptr);

    // use this to test bypassing encryption
    // memcpy((uint8_t*)userDatabase,
    // 		 (uint8_t*)encryptedUserDatabase,
    // 		 dbsize);

    //decrypt the database
    AES128_ECB_decrypt_buffer((uint8_t *) userDatabase,
                              (uint8_t *) encryptedUserDatabase,
                              dbsize,
                              (uint8_t *) mySuperSecretKey);

    return 0;
}

void UserDatabase::printDatabase() {
  printf("-----------------------------------------------\n");
  printf("|          ## Printing Database: ##           |\n");
  printf("|    (format: 'index username <password>')    |\n");
  printf("-----------------------------------------------\n");

  for (int i = 0; i < MAX_USER; i++)
  {
      if (strcmp(userDatabase[i][0], "") == 0 && strcmp(userDatabase[i][1], "") == 0) {
        printf("-----------------------------------------------\n");
        printf("|       ## %d users found in database ##       |\n", i);
        break;
      } else {
        printf("    %d    %s <%s>\n", i, userDatabase[i][0], userDatabase[i][1]);
      }
  }
  printf("|          ## Printing Complete ##            |\n");
  printf("-----------------------------------------------\n");
  return;
}
