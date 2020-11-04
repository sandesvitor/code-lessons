// proprocessor directives
/*
    This isa directive that tells the preprocessor to
    include the contents of file
*/
#include <iostream>
#include <stdio.h>

int main(){
    // print não orientado ao objeto:
    printf("Hello C\n");
    
    // A code block is a grouping of one or more statements
    {
        ; // a statement is a syntactic unit of an imperative programming language
        ;
    }
    // stc(namespace) cout (saída padrão do sistema)
    std::cout
        <<
        "Hi there,"
        <<
        "C++"
        <<
    std::endl;

    std::cout << "end" << std::endl;
    return 0;
}