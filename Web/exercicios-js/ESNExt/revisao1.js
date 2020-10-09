// duas novas palavras reservadas: "let" e "const"
// LET tem escopo de bloco!

{
    var a = 2
    let b = 3
    console.log(`Dentro do bloco: a = ${a}, b = ${b}`)
}

console.log(`Fora do bloco: `, a, b)

// // Template String
// const produto = 'iPad'
// console.log(`${produto} 
// é 
// caro`)

// // Destructuring
// const [l, e, ...tras] = "Cod3r"
// console.log(l,e,tras)

// const [x, , y] = [1, 2, 3]
// console.log(x, y)

// const { idade, nome} = { nome: 'Ana', idade: 9}
// console.log(idade, nome)