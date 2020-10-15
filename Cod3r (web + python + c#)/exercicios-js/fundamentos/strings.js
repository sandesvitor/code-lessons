const escola = "Cod3r"

console.log(escola.charAt(4))
console.log(escola.charAt(9))
console.log(escola.charCodeAt(3))
console.log(escola.indexOf('3'))

console.log(escola.substring(1)) // do índice 1 ao final
console.log(escola.substring(0, 3)) // do índice 0 ao 3

console.log('Escola '.concat(escola).concat("!"))
console.log(escola.replace(/\d/, 'e')) // Regex, expressõa regular -> subistituir tds os dígitos por "e"

console.log('Ana,Maria,Pedro'.split(','))

