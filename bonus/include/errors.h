/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-matisse.dufour
** File description:
** errors.h
*/

#ifndef COREWAR_ERROR_MESSAGES
    #define COREWAR_ERROR_MESSAGES
    #define DUMP_VALUE "Wrong dump value, please enter a positive integer\n"
    #define MULTIPLE_DUMP "Warning, multiple dump definition\n"
    #define TO_MANY_ARGS "To many arguments\n"
    #define MULTIPLE_PC "-a: Multiple definition of champion adress\n"
    #define PC_VALUE1 "-a: Wrong champion adress: "
    #define PC_VALUE2 "Champion adress is a positive integer shorter than: "
    #define ARGS_WITHOUT_CHAMP "Error: Option defined without champ file\n"
    #define MULTIPLE_INDEX_DEF "-n: Multiple definition of champion index\n"
    #define INDEX_VALUE "Champion Index must be an integer between 1 and 4\n"
    #define SAME_INDEX "-n: Same index used for more than one champion\n"
    #define OPEN_FILE "Failed to open file\n"
    #define WRONG_MAGIC "Wrong files, magic is not correct.\n"
    #define TOO_MANY_CHAMP "To many champions, 4 maximum\n"
    #define NOT_ENOUGH_CHAMP "Not enough champ, need at least 2 champions\n"
    #define OVERLAP "Champion overlap each others\n"
#endif // !COREWAR_ERROR_MESSAGES
