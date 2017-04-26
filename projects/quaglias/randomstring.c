/**********
** Steven Quagliata
** quaglias@onid.oregonstate.edu
** Spring 2017 Quiz 2
***********/


/*****************************************

** Random Tester Assignment 2:

** There are a few approaches to this randomized tester, such as creating a fuzzer
** or as I did, creating simple Ascii comparisons. As we can clearly see all of the
** testing is centered around the function testMe().  The function has a while loop
** that runs based on a char value, an int state, and a string by bringing the values
** in from the functions we were assigned to create (inputChar() & inputString()). The
** function testMe() is also where the print to the screen is created.

** inputChar() Implementation:

** char inputChar()
    {
        char c = (rand() % (127-32)) + 32;
        return c;
    }
** This allows the program to create random char values within a designated range that
** covers all values that are being checked for in the testMe() while loop.

** inputString() Implementation:

**char *inputString()
    {
        int length = 6;
        char * s = malloc(length);
        int i;

        for(i = 0; i < length-1; i++)
        {
            s[i] = (rand() % (123-97)) + 97;
        }
        s[i] = '\0';

        return s;
    }
** This function only is useful if it returns the escape word "reset" so a new set of
** limits needs to be used here. First we need to limit the size of the string itself
** and then the range of available Ascii characters. These limits are key in that they
** create a system that limits the overall time wasted waiting for all random iterations
** to be processed until the key word is reached.

** Additional potential improvements:
** - Increase the range of the Ascii chars in inputString() to include upper case letters
** - Create a probability clause where reaching "reset" directly is a bit more likely

** Results (10 Iterations)

** The way the tester is written, it can sometimes require a large amount of iterations
** before reaching the desired result to find the error.

** Sample run iteration outputs:
** Test:    |1           |2            |3           |4           |5
** Tries:   |7,750,628   |11,936,615   |4,549,031   |7,200,571   |36,754,352

** Total Coverage Test 1: 97.3% of 37























*********************************************************************************/
