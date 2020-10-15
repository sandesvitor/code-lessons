using System;
using System.Collections.Generic;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace CursoCSharp.EstruturaDeControle
{
    class EstruturaWhile
    {
        public static void Executar()
        {
            int palpite = 0;
            Random random = new Random();

            int numeroSecreto = random.Next(1, 16);
            bool numeroEncontrado = false;
            int tentaivasRestantes = 5;
            int tentativas = 0;

            while (tentaivasRestantes > 0 && !numeroEncontrado)
            {
                Console.WriteLine("Insira o seu palpite");
                string entrada = Console.ReadLine();
                int.TryParse(entrada, out palpite);

                tentativas++;
                tentaivasRestantes--;

                if(numeroSecreto == palpite)
                {
                    numeroEncontrado = true;
                    var corAnterior = Console.BackgroundColor;
                    Console.BackgroundColor = ConsoleColor.Green;
                    Console.WriteLine("Número encontrado em {0} tentativas", tentativas);
                    Console.BackgroundColor = corAnterior;
                }
                else if (palpite > numeroSecreto)
                {
                    Console.WriteLine("Menor... Tente novamente!");
                    Console.WriteLine("Tentativas restantes {0}", tentaivasRestantes);
                }
                else if (numeroSecreto > numeroSecreto)
                {
                    Console.WriteLine("Maior... Tente novamente");
                    Console.WriteLine("Tentativas restantes {0}", tentaivasRestantes);
                }
                else
                {
                    Console.WriteLine("Maior... Tente novamente");
                    Console.WriteLine("Tentativas restantes {0}", tentaivasRestantes);
                }
            }
        }
    }
}
