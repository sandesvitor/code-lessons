using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.MetodosEFuncoes
{
    delegate double Operacao(double x, double y);

    class LambdasDelegate
    {
        public static void Executar()
        {
            // Delegate nada mais é do que você definir um TIPO
            // que armazena uma assnatura de uma função!

            // RESUMINDO: voc~e cria um "tipo" para posteriormente definir
            // métodos com Lambda, como no exemplo abaixo:

            Operacao sum = (x, y) => x + y;
            Operacao sub = (x, y) => x - y;
            Operacao mult = (x, y) => x * y;

            Console.WriteLine(sum(3, 3));
            Console.WriteLine(sub(5, 2));
            Console.WriteLine(mult(12, 8));
        }
    }
}
