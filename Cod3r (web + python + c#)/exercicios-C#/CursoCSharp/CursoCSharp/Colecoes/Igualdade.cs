using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.Colecoes
{
    class Igualdade
    {
        public static void Executar()
        {
            var p1 = new Produto("Caneta", 1.89);
            var p2 = new Produto("Caneta", 1.89);
            
            // atribuição por referência (as duas variáveias apontam para o mesmo local de memória)
            var p3 = p2;

            Console.WriteLine(p1 == p2);
            Console.WriteLine(p2 == p3);

            // Como demos override no método Equals, não comparamos mais pelo endereço,
            // e sim por valores:
            Console.WriteLine(p1.Equals(p2));
        }
    }
}
