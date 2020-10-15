function soBoaNoticia(nota) {
    if(nota >= 7) {
        console.log('Aprovado com ' + nota)
    }
}

soBoaNoticia(8.1)
soBoaNoticia(6.1)

function seForVerdadeEuFalo(valor) {
    if(valor) {
        console.log('É verdade...' + valor)
    }
}

seForVerdadeEuFalo()
seForVerdadeEuFalo(null)
seForVerdadeEuFalo(undefined)
seForVerdadeEuFalo(NaN)
seForVerdadeEuFalo('')
seForVerdadeEuFalo(0) // único número que dá falso
seForVerdadeEuFalo(-1)
seForVerdadeEuFalo(' ')
seForVerdadeEuFalo('?')
seForVerdadeEuFalo([]) /// array vazio = true
seForVerdadeEuFalo([1, 2])
seForVerdadeEuFalo({}) // objeto vazio = true
seForVerdadeEuFalo({nome: 'Ana', carro: 'Celta', endereço:{logradouro: 'Rua ABC', numero: 123}})

testeObjeto = {
    nome: 'Ana', 
    carro: 'Celta', 
    endereço:
    { 
        logradouro: 'Rua ABC', 
        numero: 123}
}

console.log(testeObjeto)