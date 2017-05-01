Joshua Couture
CS 362-400 
Quiz 2
4/30/2017

To complete this quiz we need to to implement the functions inputChar() and inputString() in testme.c such that the function testme() produces an error statement.  The error statement is triggered inside of a continuous while loop that generates two variables, a character 'c' and a character array 's'.  The while loop maintains an integer variable state that is part of the testing conditions and an integer variable tcCount that keeps track of the number of times the loop executes.  The loop will continue executing until the following two conditions are true:

1. integer variable "state" is set to 9
2. The first 6 items in character array referenced by *s point to memory containing characters 'r', 'e', 's', 'e', 't', and '\0' in order.

The check for these conditions is implemented in the code: 

    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
	
The integer variable "state" is set to 0 initially and increased by one whenever the c character variable in testme() is equal to a specific character.  The possible characters that will increment "state" are '[', '(' , '{', ' ', 'a', 'x', '}', ')', and ']'.  The character will only increase state if state is already set to the appropriate value associated with the character c.  For example state will only be set to 1 of c = ' 7 if c = '}' and state is already equal to 6. 

The easiest way to trigger the error message is to manually set s to "reset" and c to a random character in the set of characters that increase state, however this would not be much of a random test.  The following was what I added to testme.c to allow the error to be triggered while still keeping it a random test. 

In inputChar(): Since a character can be set to an integer representing the character in the ASCII table my solution is to set c to any random integer from 32 (char '!') to 126 (char = '~') which includes all of the required characters that we need to cause state to = 9.  This is implemented by simply adding "return rand() % 95 + 32;" to inputChar().

In inputString(): To set s = to the required 'reset\0' we need to set s[0] ro r, s[1] and s[3] to e, s[2] to s, and s[4] to 5.  In C all strings are terminate with \0 so we do not need to worry about s[5] being equal to \0 because a string of size 5 will always have s[5] = \0.  In order to complete the test in a somewhat reasonable time I limited the input set to all lower case letters a-z by setting each character in the array to the equivalent ASCII integer.  This will usually result in an error message after several million iterations. 
