var numero = 1
{
    var numero = 2
    console.log('dentro =', numero)
}
console.log('fora =', numero)

/* conselho: fuja do escopo global (principalmente se estive
 * trabalhando no browser), pois senão abre a possibilidade da
 * sua variável ser sobreescrita. 
 * Mais crítico ao se trabalhar no front-end (browser)
*/


// NÃO EXISTE escopo em forma de bloco para "var"
// EXISTE escopo para "var" em function