for (let i = 0; i < 10; i++) {
    console.log(i)
}
console.log('i =', i) 
/* fora do bloco, como let tem escopo de bloco, 
 * ele não imprime pois "i" não foi definido.
  * Resumindo: fora do bloca a variável "i" não está disponível.
*/
