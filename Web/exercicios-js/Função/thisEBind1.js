const pessoa = {
    saudacao: 'Bom dia',
    falar() {
        console.log(this.saudacao)
    }
}

pessoa.falar()
const falar = pessoa.falar
falar() // conflito entre paradigmas: programação funcional X OO

const falarDePessoa = pessoa.falar.bind(pessoa)
/* a função "bind" é o método responsável por amarrar
 * um determinado Objeto para ele ser o dono da execução
 * daquele método, sempre que aquele método for chamado!
 * No bind você passa um Objeto no qual você quer que seja 
 * resolvido o "this"
*/

falarDePessoa()