var numero = 1 
{
    let numero = 2
    console.log('dentro =', numero)
}
console.log('fora =', numero)

/* "let", ao contrário de "var", tem escopo de bloco,
 * ou seja, mesmo não sendo uma function, o let tem o escopo
 * apenas daquele bloco.
 * Ou seja, dentro ele vai imprimir o valor "2" e fora 
 * o valor "1".
 * Como têm escopos diferentes, não entram em conflito.
*/

// também vemos o let ir de "dentro para fora" em seus escopos

// pegando do escopa mais próximo


/* MUITO IMPORTANTE: variáveis com a plavras reservada "let" tem:
 * escopo global, escopo de função e escopo de bloco (que a "var não tem")
*/