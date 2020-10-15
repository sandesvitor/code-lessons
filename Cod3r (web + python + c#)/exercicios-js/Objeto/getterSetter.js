const sequencia = {
    _valor: 1, // convenção que é uma variável que só será acessada internamente!
    get valor() { return this._valor++ },
    set valor(valor) {
        if (valor > this._valor){
            this._valor = valor
        }
    }
}

console.log(sequencia.valor, sequencia.valor) // "valor" é uma pseudovariável
// chamando a função internamente o JS entende que é pra chamar o "get"
sequencia.valor = 1000
// atribuindo um valor internamente o JS entende que é pra chamar o "set"

console.log(sequencia.valor, sequencia.valor)
sequencia.valor = 900
console.log(sequencia.valor, sequencia.valor)

