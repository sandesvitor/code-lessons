using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class NotacaoPonto {
        public static void Executar() {
            var saudacao = "Olá".ToUpper()
                    .Insert(3, " World")
                    .Replace("World", "Mundo")
                    .ToUpper();

            Console.WriteLine(saudacao);

            Console.WriteLine("Teste".Length);

            foreach (char letra in "Teste") {
                Console.WriteLine(letra);
            }

            string valorImportante = null;

            // NAVEGAÇÃO SEGURA (utilizar "?" antes do ".")
            Console.WriteLine(valorImportante?.Length); 
        }
    }
}
