/*
    3 Towers: A, B, C

    Transfer all n Disks of Tower A to Tower C:
        - Move one disk at a time;
        - No larger disk can be on top of a smaller disk;
*/

#include <iostream>

void TOH(int n, char A, char B, char C){
    if(n > 0){
        TOH(n-1, A, C, B);
        std::cout << "From " << A << " to " << C << std::endl;
        TOH(n-1, B, A, C);
    }
}

int main() {
    TOH(4, 'A', 'B', 'C');
    return 0;
}
