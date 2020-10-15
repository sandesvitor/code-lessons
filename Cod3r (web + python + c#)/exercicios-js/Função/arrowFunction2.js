function Pessoa () {
    this.idade = 0

    setInterval(() => {
        this.idade++
        console.log(this.idade)

    }, 1000)
}

new Pessoa

// neste caso, o "this" não varia de acordo
// com quem está chamando, pois com a arrow
// function ele não fica variando.