using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    class CalculadoraEstatica
    {
        // método estático pertence à CLASSE, não ao OBJETO
        public static int Somar(int a, int b)
        {
            return a + b;
        }

        public static int Multiplicar(int a, int b)
        {
            return a * b;
        }
    }

    class MetodosEstaticos
    {
        public static void Executar()
        {
            var resultado1 = CalculadoraEstatica.Somar(1, 3);
            var resultado2 = CalculadoraEstatica.Multiplicar(4, 5);

            Console.WriteLine(resultado1 + " " + resultado2);
        }
    }
}
