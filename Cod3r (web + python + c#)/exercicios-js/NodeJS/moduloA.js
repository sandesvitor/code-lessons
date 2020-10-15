// Em NodeJS um arquivo representa um módulo!
// O "módulo" não deixa tudo aquilo escrito dentro dele visível pra todo mundo.
// Funciona como os módulos do Python, precisando exportar e importar!

this.ola = "Fala Pessoal!"
exports.bemVindo = "Bem vindo ao node!"
// "this" e "exports" são objetos!

module.exports.ateLogo = "Até o próximo episódio!"
