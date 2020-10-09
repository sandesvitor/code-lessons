using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class OperadoresUnarios {
        public static void Executar() {
            var valorNegativo = -5;
            var num1 = 2;
            var num2 = 3;
            var booleano = true;

            Console.WriteLine(-valorNegativo);
            Console.WriteLine(!booleano);
            Console.WriteLine(num1++);
            Console.WriteLine(--num1);

            //NÃO FAÇA ISSO!!!
            Console.WriteLine(num1++ == --num2);
            // forma pré-fixada tem precedência!
        }
    }
}
