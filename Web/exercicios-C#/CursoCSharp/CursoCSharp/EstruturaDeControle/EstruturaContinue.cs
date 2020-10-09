using System;
using System.Collections.Generic;
using System.Reflection.Emit;
using System.Text;

namespace CursoCSharp.EstruturaDeControle
{
    class EstruturaContinue
    {
        public static void Executar()
        {
            int intervalo = 50;
            Console.WriteLine("Números pares entre 1 e {0}", intervalo);

            for (int i = 1; i <= intervalo; i++)
            {
                if (i % 2 == 1)
                {
                    continue; // VOLTA PARA O BLOCO DO FOR, SEM PASSAR PRA LINHA DE BAIXO!
                }

                Console.Write(i + " ");
                Random r = new Random();
            }
        }
    }
}
