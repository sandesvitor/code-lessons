const valores = [7.7, 9.9, 6.3, 9.3]
console.log(valores[0], valores[3])
console.log(valores[4])

valores[4] = 10
console.log(valores)
console.log(valores.length)

valores.push({id: 3}, false, null, 'teste')
console.log(valores)

console.log(valores.pop()) // tira o último valor de um array
delete valores[0] // deleta o valor do índice indicado, funciona no contexto do objeto
console.log(valores)

console.log(typeof valores)
