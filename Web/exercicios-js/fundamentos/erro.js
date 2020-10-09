function tratarErrorELancar(erro){
    // throw new Error('OCORREU UM ERRO DE PROCESSAMENTO')
    // throw 10
    // throw true
    // throw 'mensagem'
    throw {
        nome: erro.name,
        msg: erro.message,
        date: new Date
    }

}

function imprimirNomeGritado(obj) {
    try { // usar para códigos potencialmente perigosos
    console.log(obj.name.toUpperCase() + '!!!')
    } catch (e) {
        tratarErrorELancar(e)
    } finally {
        console.log('final')
    }
}
const obj = { nome: 'Roberto' } // o atributo está escrito errado!
imprimirNomeGritado(obj)