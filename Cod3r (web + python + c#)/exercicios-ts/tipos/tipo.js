"use strict";
// string
let nome = 'João';
console.log(nome);
// nome = 28
// numbers
let idade = 27;
// idade = 'Ana'
idade = 27.5;
console.log(idade);
// boolean
let possuiHobbies = false;
// possuiHobbies = 1
console.log(possuiHobbies);
// tipos explícitos
let minhaIdade;
minhaIdade = 27;
console.log(typeof minhaIdade);
// minhaIdade = 'idade é 27'
// array
let hobbies = ["Cozinhar", "Praticar Esportes"];
console.log(hobbies[0]);
console.log(typeof hobbies);
hobbies = [100];
// hobbies = 100
console.log(hobbies);
// tuplas
let endereco = ["Av Principal", 99, ""];
console.log(typeof endereco);
console.log(endereco);
endereco = ["Rua Importante", 1260, "Bloco A"];
console.log(endereco);
// enums
var Cor;
(function (Cor) {
    Cor[Cor["Cinza"] = 0] = "Cinza";
    Cor[Cor["Verde"] = 101] = "Verde";
    Cor[Cor["Azul"] = 2] = "Azul";
    Cor[Cor["Laranja"] = 3] = "Laranja";
    Cor[Cor["Amarelo"] = 4] = "Amarelo";
    Cor[Cor["Vermelho"] = 5] = "Vermelho";
})(Cor || (Cor = {}));
let minhaCor = Cor.Verde;
console.log(minhaCor);
console.log(Cor.Azul);
// any
let carro = 'BMW';
console.log(carro);
carro = { marca: 'BMW', ano: 2019 };
console.log(carro);
// funções
function retornaMeuNome() {
    // return minhaIdade
    return nome;
}
console.log(retornaMeuNome());
function digaOi() {
    console.log("Oi!");
    // return minhaIdade
}
digaOi();
function multiplicar(numA, numB) {
    return numA * numB;
}
// console.log(multiplicar(2, 'Bia')) ---> NaN
console.log(multiplicar(2, 12));
// tipo função
let calculo;
// calculo = digaOi
// calculo()
calculo = multiplicar;
console.log(calculo(5, 6));
// objeto
let usuario = {
    nome: 'João',
    idade: 27
};
console.log(usuario);
// usuario = {}
// usuario = {
//     name: 'Maria',
//     age: 31
// }
usuario = {
    idade: 31,
    nome: 'Maria'
};
console.log(usuario);
const funcionario = {
    supervisores: ['Anna', 'Helio', 'Jonas'],
    baterPonto(hora) {
        if (hora <= 8)
            return 'Ponto Normal';
        return 'Fora do Horário';
    }
};
console.log(funcionario.supervisores);
console.log(funcionario.baterPonto(9));
console.log(funcionario.baterPonto(2));
const funcionario2 = {
    supervisores: ['Joao'],
    baterPonto(hora) {
        if (hora <= 8)
            return 'Ponto Normal';
        return 'Fora do Horário';
    }
};
console.log(funcionario2.supervisores);
console.log(funcionario2.baterPonto(9));
console.log(funcionario2.baterPonto(2));
// funcionario = {}
// Union Types
let nota = 10;
console.log(`Minha nota é ${nota}`);
nota = '10';
console.log(`Minha nota é ${nota}`);
// nota = true ---> cenário não desejável!
// Checando tipos em runtime
let valor = 30;
if (typeof valor === "number") {
    console.log('É um valor number!');
}
else {
    console.log(typeof valor);
}
// tipo never
function falha(msg) {
    throw new Error(msg);
}
const produto = {
    nome: 'Sabão',
    preco: 4,
    validarProduto() {
        if (!this.nome || this.nome.trim().length == 0) {
            falha('Precisa ter um nome');
        }
        if (this.preco <= 0) {
            falha('Preco inválido');
        }
    }
};
produto.validarProduto();
// valor nulo
let altura = 12;
// altura = null
let alturaOpcional = 12;
alturaOpcional = null;
const contato1 = {
    nome: 'Fulano',
    tel1: '98893902',
    tel2: null
};
console.log(contato1);
let podeSerNulo = null; // tipo any
let contaBancaria = {
    saldo: 3456,
    depositar(valor) {
        this.saldo += valor;
    }
};
let correntista = {
    nome: 'Ana Silva',
    contaBancaria: contaBancaria,
    contatos: ['345141556', '918982900']
};
correntista.contaBancaria.depositar(3000);
console.log(correntista);
//# sourceMappingURL=tipo.js.map