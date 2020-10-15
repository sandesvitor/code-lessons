using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    public class Dependente
    {
        public string Nome; // ---> String é uma classe!
        public int Idade; // ---> int é um struct!
    }

    class ValorVsReferencia
    {
        public static void Executar()
        {
            int numero = 3;
            int copiaNumero = numero;
            numero++;
            Console.WriteLine($"{numero} {copiaNumero}");

            string frase = "Olá";
            string copiaFrase = frase;
            frase = "Hello";
            Console.WriteLine($"{frase} {copiaFrase}");

            Dependente dep = new Dependente
            {
                Nome = "Beto",
                Idade = 20
            };

            Dependente copiaDep = dep;

            Console.WriteLine($"{dep.Nome} {copiaDep.Nome}");
            Console.WriteLine($"{dep.Nome} {copiaDep.Nome}");

            copiaDep.Nome = "Renato";
            dep.Idade = 21;

            Console.WriteLine($"{dep.Nome} {copiaDep.Nome}");
            Console.WriteLine($"{dep.Idade} {copiaDep.Idade}");
        }
    }
}
