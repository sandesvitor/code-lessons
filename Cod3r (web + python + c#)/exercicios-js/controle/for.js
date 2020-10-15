let contador = 1
while (contador <= 10) {
    console.log(`contador = ${contador}`)
    contador++
}

// mesma expressão com "for"
for(let i = 1; i <= 10; i++) {
    console.log(`i = ${i}`)
}


const notas = [6.7, 7.4, 9.8, 8.1, 7.7]
for(let i = 0; i < notas.length; i++) {
    console.log(`nota = ${notas[i]}`)
}

/* não é preciso colocar o "let" para atribuir ao valor
 * da variável "i". Porém, não colocando "let" a variável "i"
 * fica disponível fora do laço do "for", o que não é muito
 * interessante.
 * Assim, por boas práticas, sempre usar o "let" para essas
 * variáveis, para deixá-las com o escopo limitado.
*/