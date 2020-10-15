const pilotos = ['Vettel', 'Alonzo', 'Raikkonen', 'Massa']

pilotos.pop() // remove o último elemento

console.log(pilotos)

pilotos.push('Verstappen')
console.log(pilotos)

pilotos.shift() // remove o primeiro elemento

console.log(pilotos)

pilotos.unshift('Hamilton')
console.log(pilotos)

// splice pode adicionar e remover elementos

// adicionar:
pilotos.splice(2, 0, 'Bottas', 'Massa')
console.log(pilotos)

// remover:
pilotos.splice(3, 1)
console.log(pilotos)

// "splice" != "slice"
const algunsPilotos1 = pilotos.slice(2) // retorna novo array
console.log(algunsPilotos1)

const algunsPilotos2 = pilotos.slice(1, 4) // índice "1" ao "3"
console.log(algunsPilotos2)