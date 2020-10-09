const bodyParser = require('body-parser')
const express = require('express')
const app = express()

// middleware -> callbacks que são executadas sempre
// que chega uma requisição.


// Dentro da pasta atual, sirva os arquivos estáticos:
app.use(express.static('.'))

/* 
 * Se vier algum formato a partir de uma submit de um formulário
 * esse código vai ser responsável para ler os dados e transformar
 * isso em objeto.
*/
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())

/* Quando vier uma requisição do tipo "get" nessa URL "/teste",
 * chame essa função, que recebe request e response, que retorna
 * "Ok"
*/
app.get('/teste', (req, res) => res.send(`
    <div width="1000px" style="border: solid 10px red">
        <h1 style="text-align: center; border: solid 5px green">Ok</h1>
        <h2 style="text-align: center; border: solid 5px navy"">Está funfando</h2>
        <h3 style="text-align: center; border: solid 5px violet"">Template String é foda!</h3>
        <h4 style="text-align: center; border: solid 5px dodgerblue"">!!!</h4>
    </div>`))


const multer = require('multer')

const storage = multer.diskStorage({
    destination: function (req, file, callback){
        callback(null, './upload')
    },
    filename: function (req, file, callback) {
        callback(null, `${Date.now()}_${file.originalname}`)
    }
})

const upload = multer({storage}).single('arquivo')

app.post('/upload', (req, res)=>{
    upload(req,res,err => {
        if(err){
            return res.end('Ocorreu um erro.')
        }

        res.end('Concluído com sucesso')
    })
})

app.post('/formulario', (req, res) => {
    res.send({
        ...req.body,
        id: 1
    })
})

app.get('/parOuImpar', (req, res) => {
    //req.body
    //req.query
    //req.params
    const par = parseInt(req.query.numero) % 2 === 0
    res.send({
        resultado: par ? 'par' : 'impar'
    })
})

app.listen(8080, ()=> console.log('Executando... '))