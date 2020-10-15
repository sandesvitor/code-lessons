function f1(a, b){
    soma = (a+b).toFixed(2)
    console.log(('R$' + soma).replace('.', ','))
}

f1(0.1, 0.2)