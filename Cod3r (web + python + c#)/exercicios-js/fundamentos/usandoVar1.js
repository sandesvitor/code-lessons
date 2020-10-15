{
    {
        {
            {
                var sera = 'Será???'
            }
        }
    }
}
console.log(sera)

// escopo = até onde a variável fica visível
// No caso da variável "var" ela fica visível até fora do bloco

function teste() {
    var local = 123
}

test()
console.log(local) 
// será que a variável "local" está dentro do escopo? = Não!
/* no Browser o objeto global é o "window"
 * aqui no VSCode é o Node, o objeto Globo.
 * "var" só tem dois escopos possíveis: global, visíveis para todo mundo
 * ou dentro de uma função, tornando ela visível só no escopo da function
*/
