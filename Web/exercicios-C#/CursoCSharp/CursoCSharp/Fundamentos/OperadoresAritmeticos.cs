using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class OperadoresAritmeticos {
        public static void Executar() {
            var preco = 1000;
            var imposto = 355;
            var desconto = 0.1;

            double total = preco + imposto;
            //int total = (int)preco + imposto;

            var totalComDesconto = total - (total * desconto);
            Console.WriteLine("O preço final é {0}", totalComDesconto);

            //IMC
            double peso = 91.2;
            double altura = 1.82;
            double imc = peso / Math.Pow(altura, 2);
            Console.WriteLine("O IMC é {0}", imc.ToString("F2"));
        }
    }
}
