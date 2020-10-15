// função array com operador ternário "?"
const resultado = nota => nota >= 7 ? 'Aprovado' : 'Reprovado'

console.log(resultado(7.1))
console.log(resultado(6.7))

// a resposta do operador ternário também pode
// ser armazenada em uma constante
const status =  nota >= 7 ? 'Aprovado' : 'Reprovado'