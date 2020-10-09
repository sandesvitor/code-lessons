using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    class DesafioAtributos
    {
        int a = 10;

        public static void Executar()
        {
            // Acessar a variável "a" dentro do método Executar!
            DesafioAtributos desafio = new DesafioAtributos();
            Console.WriteLine(desafio.a);

            Console.WriteLine(new DesafioAtributos().a);
        }
    }
}
