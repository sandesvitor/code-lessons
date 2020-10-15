function Pessoa() {
    this.idade = 0

    const self = this 
    // não importa, nesse caso, quem esteja chamando a 
    // função, pois o self sempre vai estar apontando 
    // para "Pessoa"
    setInterval(function(){ 
        self.idade++
        console.log(self.idade)
    }/*.bind(this)*/, 1000) 
}
// o "setInterval" além da função, recebe um intervalo em milisegundos para executar o valor
// assim, a cada 1000 milisegundos vai disparar a função anônima

new Pessoa