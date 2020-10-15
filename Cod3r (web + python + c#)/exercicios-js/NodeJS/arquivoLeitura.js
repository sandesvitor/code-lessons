const fs = require('fs')

const caminho = __dirname + '/arquivo.json'

// ler arquivo de forma síncrona...
const conteudo = fs.readFileSync(caminho, 'utf-8')
console.log(conteudo)

// ler arquivo de forma assíncrona...
fs.readFile(caminho, 'utf-8', (err, conteudo) => {
    const config = JSON.parse(conteudo)
    console.log(`${config.db.host}: ${config.db.port}`)
})

const config = require('./arquivo.json')
console.log(config.db)

fs.readdir(__dirname, (err, arquivos) => {
    console.log('Conteúdos da pasta...')
    console.log(arquivos)
})

// a constante "__dirname" representa o diretório atual!