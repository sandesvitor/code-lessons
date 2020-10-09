using System;
using System.Collections.Generic;
using System.Reflection.Metadata;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class VariaveisEConstantes {
        public static void Executar() {
            // área da circunferência
            double raio = 4.5;
            const double PI = Math.PI;
            double area = PI * raio * raio;
        
            Console.WriteLine("A área é " + area);

            bool estaChovendo = false;
            Console.WriteLine(estaChovendo 
                ? "Está chovendo!" 
                : "Tudo certo, solzão!");

            byte idade = 45; // bom para economizar memória!
            Console.WriteLine("idade " + idade);

            sbyte saldoDeGols = sbyte.MinValue; //aceita sinal negativo!
            Console.WriteLine(saldoDeGols);

            short salario = short.MaxValue;
            Console.WriteLine(salario);

            int menorValor = int.MinValue; // mais usado dos inteiros!
            Console.WriteLine(menorValor);

            uint populacaoBrasileira = 207_600_000; // underline pra dar clareza!
            Console.WriteLine(populacaoBrasileira);

            long menorValorLong = long.MinValue;
            Console.WriteLine(menorValorLong);

            ulong populacaoMundial = 7_600_000;
            Console.WriteLine(populacaoMundial);

            float precoComputador = 1299.99f;
            Console.WriteLine(precoComputador);

            decimal distanciaEntreAsEstrelas = decimal.MaxValue;
            Console.WriteLine(distanciaEntreAsEstrelas);

            char letra = 'b'; // delimitado por aspas simples ''
            Console.WriteLine(letra);

        }
    }
}
