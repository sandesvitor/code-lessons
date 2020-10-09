console.log("##### Promises ######");
console.log("Type of promises:", typeof Promise);

function primeiroElemento(array) {
  return array[0]
}

function primeiraLetra(string) {
  return string[0]
}

const letraMinuscula = letra => letra.toLowerCase()

new Promise(function (resolve, reject) {
  try {
    resolve([
      'Ana',
      'Bia',
      'Carlos',
      'Daniel'
    ])
  } catch (ex) {
    reject(ex)
  }
}).then(primeiroElemento)
  .then(primeiraLetra)
  .then(letraMinuscula)
  .then(console.log) 
