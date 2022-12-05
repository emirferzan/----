
/**
replaces each element in a string with a _*/
void initializeBlankString(int size, char *string);

/**
prints the contents of the string character by character with spaces
in between
*/
void printWithSpaces(char *s);

/**
this function checks if the constraint string contains the given letter
if it does not then the element becomes _
*/
int revealGuessedLetter(const char *a, char *s, char letter);

/**
if strings are equal, returns 1, 0 if not
*/
int checkGuess(char *a, char *s);


//the following functions have been done for you.

/**
 * Sets the game up, checks for win condition,
 * prints relevant data
 */
void startGame(char *wordToGuess);

/**
 * Clears the unix terminal of previous input
 */
void clearScreen();

/**
 * Prints part of the horse based on the ratio between
 * the two numbers.
 */
void drawHorse(int guessedSoFar, int allowedGuesses);
