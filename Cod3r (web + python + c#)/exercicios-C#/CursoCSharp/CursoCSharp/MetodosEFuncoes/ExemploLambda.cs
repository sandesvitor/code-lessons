﻿using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.MetodosEFuncoes
{
    class ExemploLambda
    {
        public static void Executar()
        {
            // "Action" é uma função void
            Action algoNoConsole = () =>
            {
                // "Lambda" é uma função anônima que
                // pode ser armazenada em uma variável!
                Console.WriteLine("Lambda com C#!");
            };

            algoNoConsole();

            // "Func" é uma função que exige return!
            // o ÚLTIMO parâmetro passado é o tipo de retorno@
            Func<int> jogarDado = () =>
            {
                Random random = new Random();
                return random.Next(1, 7);
            };

            Console.WriteLine(jogarDado());

            Func<int, string> conversorHex = numero => numero.ToString("X");

            Console.WriteLine(conversorHex(1234));

            Func<int, int, int, string> formatarData = (dia, mes, ano) =>
                String.Format("{0:D2}/{1:D2}/{2:D4}", dia, mes, ano);

            Console.WriteLine(formatarData(1, 1, 2019));
        }
    }
}