console.log('01)', '1' == 1) 
// nesse caso é "true" porque estamos comparando o valor, não o tipo

console.log('02)', '1' === 1)
// neste caso é "false" porque "===" é estritamente igual,
// então ele também considera o tipo (int <> str)

console.log('03)', '3' != 3)
console.log('04)', '3' !== 3)

console.log('05)', 3 < 2)
console.log('06)', 3 > 2)
console.log('07)', 3 <= 2)
console.log('08)', 3 >= 2)

// Date(0) é a data de referência do JS, 01/01/1970
const d1 = new Date(0)
const d2 = new Date(0)
// não diferença usar "==" "===" 
// pois estão comparando referências de memória
console.log('09)', d1 === d2)
console.log('10)', d1 == d2)
// dão false porque são espaços diferntes na memória

console.log('11)', d1.getTime() === d2.getTime())
console.log('12)', d1.getTime() == d2.getTime())
// dão true porque estão pegando o valor do horário

console.log('13)', undefined == null)
console.log('14)', undefined === null)
