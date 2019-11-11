#include "SysParam.h"
#include "userControl.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {

    string msg1=    "===============================================\n"
                    "|             Decrypt the Database            |\n"
                    "===============================================\n"
                    "|       Please enter the database path:       |\n"
                    "-----------------------------------------------\n";

    cout << msg1;

    char dbPath[MAX_PASSWORD_LENGTH];
    cin >> dbPath;

    ifstream db(dbPath);
    if(!db.good()){ cout << "Error: Database file does not exist" <<endl;
        exit(0);
    }

    UserDatabase::getInstance().loadUserDatabase(dbPath);

    db.close();

    std::string s = "abcdefghijklmnopqrstuvwxyz01234567890258";

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH] ;

    s.copy(username, s.size());
    s.copy(password, s.size());

    UserDatabase::getInstance().printDatabase();

    return 0;
}
