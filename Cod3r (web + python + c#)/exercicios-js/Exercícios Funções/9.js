function recebaNota(nota) {
    0  
    if (nota > 40) {
        if (nota % 5 >= 3) {
            nota += (5 - nota % 5)
            console.log(`Aprovado com nota ${nota}`)
        }
        console.log(`Aprovado com nota ${nota}`)
    } else {
        console.log(`Aluno reprovado com nota ${nota}`)
    }
}

recebaNota(81)