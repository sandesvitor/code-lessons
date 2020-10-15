"use strict";
let canal = 'Gaveta';
let inscritos = 610234;
// canal = inscritos
console.log(`Canal = ${canal}`); /*---> precisa desse ';'*/
// let nome = 'Pedro' // mesmo namespace que ./tipos/tipo.ts
// escopo diferente!
(function () {
    let nome = 'Ana';
    console.log(nome);
})();
function soma(a, b) {
    return a + b;
}
let qualquerCoisa;
qualquerCoisa = 12;
qualquerCoisa = 'abc';
function saudar(isManha) {
    let saudacao;
    if (isManha) {
        saudacao = 'Bom dia!';
    }
    else {
        saudacao = "Boa vida.";
    }
    return saudacao;
}
//# sourceMappingURL=compilador.js.map