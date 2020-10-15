using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.Fundamentos {
    class OperadorTernario {
        public static void Executar() {
            float nota = 7.0f;
            bool bomComportamento = true;
            string resultado = nota >= 7.0 && bomComportamento
                ? "Aprovado"
                : "Reprovado";

            Console.WriteLine("Aluno {0}", resultado);
        }
    }
}
