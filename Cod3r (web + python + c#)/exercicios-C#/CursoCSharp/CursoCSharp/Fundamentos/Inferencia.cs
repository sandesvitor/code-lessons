using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class Inferencia {
        public static void Executar() {
            var nome = "Leonardo";
            Console.WriteLine("Tipo implicito: " + nome.GetType());

            //NÃO PODE!
            //var idade;
            //idade = 19;
        }
    }
}
