// Uma factory retorna um novo objeto (nova instância)
module.exports = () => {
    return {
        valor: 1,
        inc() {
            this.valor++
        }
    }
}