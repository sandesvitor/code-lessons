function disponibilidadeFruta(fruta) {
    switch(fruta){
        case('Maçã'):
            return 'Não vendemos esta fruta aqui'
            break
        case('Kiwi'):
            return 'Estamos com escassez de kiwis'
            break
        case('Melancia'):
            return 'Aqui está, são 3 reais o quilo'
            break
        default:
            return 'Erro'
    } 
}

console.log(disponibilidadeFruta('Maçã'))
console.log(disponibilidadeFruta('Kiwi'))
console.log(disponibilidadeFruta('Melancia'))
console.log(disponibilidadeFruta('Banana'))