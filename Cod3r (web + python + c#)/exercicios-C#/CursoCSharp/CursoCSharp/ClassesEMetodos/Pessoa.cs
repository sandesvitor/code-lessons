
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    class Pessoa
    {
        public string Nome; // string valor padrão == null
        public int Idade; // int valor padrão == 0

        public string Apresentar()
        {
            if (Nome != "" && Idade > 0)
            {
                return string.Format($"Olá! Me chamo {Nome} e tenho {Idade} anos.");
            }
            else
            {
                return string.Format("Dados inválidos.");
            }
        }

        public void ApresentarNoConsole()
        {
            Console.WriteLine(Apresentar());
        }
    }
}
