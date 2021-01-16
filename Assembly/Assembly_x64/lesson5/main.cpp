#include <iostream>


extern "C" int Question1(int a, int b);
extern "C" int Question2(int a, int b);
extern "C" int Question3(int a, int b);
extern "C" int Question4(int a);

void PrintBits(int x){
   for(int i = 31; i >= 0; i--){
       std::cout << ( (x>>i) & 1); 
   } 
       std::cout << std::endl;
}

int main(){
    printf("------------------- QUESTION 1 -------------------\n\n");
    PrintBits(2783);
    PrintBits(1552);
    PrintBits(Question1(2783, 1552));
    printf("\n--------------------------------------------------\n");
    
    printf("------------------- QUESTION 2 -------------------\n\n");
    PrintBits(2783);
    PrintBits(1552);
    PrintBits(Question2(2783, 1552));
    printf("\n--------------------------------------------------\n");
    
    printf("------------------- QUESTION 3 -------------------\n\n");
    PrintBits(2783);
    PrintBits(1552);
    PrintBits(Question3(2783, 1552));
    printf("\n--------------------------------------------------\n");
    
    printf("------------------- QUESTION 4 -------------------\n\n");
    PrintBits(Question4(129));
    std::cout << Question4(129) << std::endl;
    std::cout << Question4(-129) << std::endl;
    printf("\n--------------------------------------------------\n");
    
    return 0;
}