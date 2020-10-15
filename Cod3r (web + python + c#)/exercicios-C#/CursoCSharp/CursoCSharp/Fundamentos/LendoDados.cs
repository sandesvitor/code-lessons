using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class LendoDados {
        public static void Executar() {
            Console.Write("Qual é o seu nome? ");
            string nome = Console.ReadLine();

            Console.Write("Qual é a sua idade? ");
            //int idade = Convert.ToInt32(Console.ReadLine());
            int idade = int.Parse(Console.ReadLine());

            Console.Write("Qual é o seu salário? ");
            double salario = double.Parse(Console.ReadLine());

            Console.WriteLine($"{nome} - {idade} anos recebe R${salario}");
        }
    }
}
