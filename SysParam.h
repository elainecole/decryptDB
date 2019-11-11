#ifndef Sys_Param_H
#define Sys_Param_H

#define USER_DB_PATH  "usrDb"
#define ML_MODEL_PATH "mlModel"

enum index {
    PROGRAM_NAME,
    LIBRARY,
    FUNCTION,
    PARAM1,
    PARAM2,
    PARAM3,
    PARAM4,
    PARAM5,
};

enum library {
    CRYPTO,
    ML
};

enum argument {
    UNIT_TEST = 1,
    //make changes here 3-2;
    MIN_NUMBER_OF_ARGUMENTS = 2,
    MAX_NUMBER_OF_ARGUMENTS = 8
};

enum state {
    SUCCESS,
    WRONG_ARGUMENTS,
    UNABLE_OPEN_FILE,
    SUCCESS_OPEN_FILE,
    AUTH_FAILED,
    ADD_USER_FAILED,
    REMOVE_USER_FAILED
};

enum user {
    MAX_USER = 100,
    NUM_USER_PARAM = 2,
    MAX_PASSWORD_LENGTH = 40
};

#endif 