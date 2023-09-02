/*
 * File: stringhelper.h
 * --------------------
 * This interface exports some simple string processing functions.
 */

#ifndef STRINGHELPER_H
#define STRINGHELPER_H


/* Function: removeCharacters
 * Usage: removeCharacters(std::string, std::string);
 * --------------------------------------------------
 * Takes the first argument and treats it as the original string from which
 * the characters included in second string are to be removed.
 * Example: removeCharacters("Rawr", "a"); returns "Rwr"
 */
std::string removeCharacters(std::string originale, std::string deletionKey);

/* Function removeCharactersInPlace
 * Usage: removeCharactersInPlace(std::string&, std::string);
 * ---------------------------------------------------------
 * This does the same as removeCharacters, but instead of returning a string, it
 * directly modifies the first argument. Use this if you would rather not have to
 * create a new string to assign the result of the function removeCharacters.
 */

void removeCharactersInPlace(std::string &originale, std::string deletionKey);

#endif // STRINGHELPER_H
