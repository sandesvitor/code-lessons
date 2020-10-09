let canal:string = 'Gaveta'
let inscritos:number = 610234

// canal = inscritos
console.log(`Canal = ${canal}`); /*---> precisa desse ';'*/ 

// let nome = 'Pedro' // mesmo namespace que ./tipos/tipo.ts

// escopo diferente!
(function() {
    let nome: string = 'Ana'
    console.log(nome)
})()

function soma(a: any, b: any){
    return a + b
}

let qualquerCoisa
qualquerCoisa = 12
qualquerCoisa = 'abc'

function saudar(isManha: boolean): string{
    let saudacao: string
    if(isManha){
        saudacao = 'Bom dia!'
    } else {
        saudacao = "Boa vida."
    }
    return saudacao
}