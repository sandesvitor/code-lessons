let a = 2 //visível apenas dentro do módulo!


module.exports = {
    bomDia: 'Bom dia',
    boaNoite() {
        return 'Boa noite'
    }
}