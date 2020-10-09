function teste1(num) {
    if(num > 7)
        console.log(num) 
        // com uma única sentança de código n~]ao precisa de chaves
    
    console.log('Final')
}

teste1(6)
teste1(8)

function teste2(num) {
    if(num > 7); { // cuidado com o ";" não usar com bloco IF (e outras estruturas de controle)
        console.log(num)
        }
}

teste2(6)
teste2(8)