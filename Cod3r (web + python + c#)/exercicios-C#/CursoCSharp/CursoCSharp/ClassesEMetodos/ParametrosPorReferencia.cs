using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    class ParametrosPorReferencia
    {
        public static void AlterarRef(ref int numero)
        {
            numero = numero + 100;
        }

        public static void AlterarOut(out int numero)
        {
            numero = 0;
            numero = numero + 15;
        } 

        public static void Executar()
        {
            int a = 3;
            // você passa a referência para o método
            AlterarRef(ref a);
            Console.WriteLine(a);

            //int b;
            AlterarOut(out int b);
            Console.WriteLine(b);
        }
    }
}
