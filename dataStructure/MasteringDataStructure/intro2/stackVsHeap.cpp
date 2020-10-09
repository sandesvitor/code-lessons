/*
    Static VS Dynamic Memory Allocation:

    Addresses are linear, only have one value.
    Ex: 8 Gb of RAM represents a 8,388,608.00 bytes.

    Entire Main Memory is divided in 3 sections:

    1) Heap;
    2) Stack;
    3) Code Section;

    - The machine code of a program is loaded in the CODE SECTION.

    STACK:

    void main ()
    {
        int a; ------> assume 2 bytes
        float b; ----> assume 4 bytes
    }

    Total: 6 bytes (are allocated in the Stack) 
            ---> "Stack Frame of Main Function" 
            or:
            ---> "Activation Record of Main Function"

    PS: Everything decided before compile time are static!

    The Stack workes "stacking" piles of functions at run time and deleting
    them after they are used!


    HEAP:

    Means "pilling up!";

    Can be used for unorganized memory (the opposite of Stack);

    It must be used as a resource (should be used by the program when required);

    Program CANNOT DIRECTLY ACCESS HEAP MEMORY (to used it, programs must use a
    pointer!).

    Ex:
    void main (){
        int *p; ---------------------------> 2 bytes

        p = new int[5]; -------------------> (C++)
        p = (int*)malloc(sizeof(p) * 5); --> (C-Lang)
    }

    Heap memory should be EXPLICITY REQUESTED and EXPLICIT DISPOSED, otherwise,
    it will cause MEMORY LEAK (loss of memory);

*/

#include <stdio.h>

int main()
{
    printf("Stack vs Heap Memory");
    return 0;
}