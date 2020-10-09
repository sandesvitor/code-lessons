const express = require('express')
const app = express()
const bodyParser = require('body-parser')

const saudacao = require('./saudacaoMid')
const usuarioApi = require('./api/usuario')

require('./api/produto')(app, 'com param!')

// chain of responsibility
// FUNÇÕES MIDDLEWARE

app.post('/usuario', usuarioApi.salvar)
app.get('/usuario', usuarioApi.obter)

app.use(bodyParser.text())
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ encoded: true })) // padrão de formulários!!!

app.use(saudacao('Joao'))

app.use((req, res, next) => { // tds as requisições passaram por aqui
    console.log('Antes')
    next()
})


// QUERY E PARAMS!

//REQUISIÇÕES:
// ---> TIPO GET: VÃO DIRETAMENTE NA URL!
// ---> TIPO POST: VÃO NO CORPO DA REQUISIÇÃO!
app.get('/clientes/relatorio', (req, res) => {
    res.send(`Cliente relatório: completo ${req.query.completo} ano = ${req.query.ano}`)
})

app.post('/corpo', (req, res) => {
    // let corpo = ''
    // req.on('data', (parte) => {
    //     corpo += parte
    // })

    // req.on('end', () => {
    //     res.send(corpo)
    // })
    res.send(req.body)
})

app.get('/clientes/:id', (req, res) => {
    res.send(`Cliente ${req.params.id} selecionado!`)
})


app.get('/opa', (req, res, next) => {
    console.log('Durante')
    res.json({
        data: [
            { id: 7, name: "Ana" },
            { id: 71, name: "Vitor" },
            { id: 17, name: "Pedro" },
            { id: 37, name: "Joas" },
        ],
        count: 30,
        skip: 0,
        limit: 3,
        status: 200
    })

    next()
})

app.use((req, res, next) => {
    console.log('Depois')
    // não precisa do next por ser a última
})


app.listen(3000, () => {
    console.log('Backend executando...')
})
