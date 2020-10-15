function anoBissexto (ano) {
    if (ano % 400 == 0) {
        console.log(`${ano} é bissexto`)
    } else if (ano % 100 == 0) {
        console.log(`${ano} é bissexto`)
    } else if (ano % 4 == 0) {
        console.log(`${ano} é bissexto`)
    } else {
        console.log(`${ano} não é bissexto`)
    }
}

anoBissexto(2017)
