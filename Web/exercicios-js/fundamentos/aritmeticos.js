// usando o operador destructuring
const [a, b, c, d] = [3, 5, 1, 15] // forma reduzida de criar 4 variáveis

/* Conceitos:
 * operador post-fixed (op++), depois do operando (operador unário)
 * operador pre-fixed (++op), antes do operando (operador unário)
 * operador in-fixed (op1 + op2), entre os operandos (operador binário)
*/ 

const soma = a + b + c + d
const subtracao = d - b
const multiplicacao = a * b
const divisao = d / a
const modulo = a % 2

console.log(soma, subtracao, multiplicacao, -divisao, modulo)
