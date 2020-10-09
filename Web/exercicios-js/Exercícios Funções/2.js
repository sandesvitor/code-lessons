function getTriangulo(a,b,c){
    if (a == b && b == c) {
        console.log('Triângulo Equilátero')
    }
    if (a != b && b != c && c != a){
        console.log('Triângulo Escaleno')
    }
    else {
        console.log('Triângulo Isosceles')
    }
}

getTriangulo(2,3,2)