const modulaA = require('../../moduloA') 
// caminho relativo
console.log(modulaA.ola)

const modulaB = require('C:\\Users\\Snades\\Desktop\\exercicios-js\\NodeJS\\moduloB.js')
// caminha absoluto
console.log(modulaB.bomDia)

const saudacao = require('saudacao')
console.log(saudacao)
console.log(saudacao.ola)

const http = require('http')
http.createServer((req, res) => {
    res.write('Bom dia')
    res.end()
}).listen(8080)