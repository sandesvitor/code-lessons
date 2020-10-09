using System;
using System.Globalization;

namespace CursoCSharp.Fundamentos {
    class FormatandoNumero {
        public static void Executar() {
            double valor = 15.175;
            Console.WriteLine(valor.ToString("F1")); //apenas uma casa decimal
            Console.WriteLine(valor.ToString("C")); // currency
            Console.WriteLine(valor.ToString("P")); // percentual * 100
            Console.WriteLine(valor.ToString("#.##"));

            CultureInfo cultura = new CultureInfo("pt-BR");
            Console.WriteLine(valor.ToString("C0"), cultura);

            int inteiro = 256;
            Console.WriteLine(inteiro.ToString("D10")); //completa com zero à esquerda


        }
    }
}
