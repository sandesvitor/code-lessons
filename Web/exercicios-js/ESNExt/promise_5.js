function funcionarOuNao(valor, chanceError) {
    return new Promise((resolve, reject) => {
        try {
            con.log('temp')
            // 'con' não existe!
            // vai cair no primeiro tratamente de erro na cadeia de 
            // 'thens' e 'catch'
            if (Math.random() < chanceError) {
                reject('Ocorreu um erro!')
            } else {
                resolve(valor)
            }
        } catch (ex) {
            reject(ex)
        }
    })
}

funcionarOuNao('Testando...', 0.5)
    .then(v => console.log(`Valor: ${v}`))
    .then(
        v => consol.log(v),
        // err => console.log(`Erro específico: ${err}`)
    )
    .then(() => console.log('Quase Fim!'))
    .catch(err => console.log(`Erro Geral: ${err}`))
    .then(() => console.log('Fim!'))

    // DEPOIS DO CATCH NÃO HÁ MAIS DADOS!