/*This is a header file. It is used only for declarations of all of our functions in the 'main.c'.
The definitions of that functions are all in the 'Lib.c'.
The 'Lib.h' and 'Lib.c' are forming a so-called 'Kompilation Unit'.
These are like our self-written library, just like the standard libraries from the compiler, e.g. <stdio.h>
*/

/*In a header file there has to be also 'Include Guards'. Those are preprocessor keywords and they ensure that
the 'Lib.h' will be included in the 'main.c' only once, even if we included it multiple times by accident.
In the worst case, without 'Include Guards', compiler errors would occur.
*/
#ifndef LIB_H       // = if not defined, execute lines 9 to 12.
#define LIB_H

int getNumberFromUser();

#endif
