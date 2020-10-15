using System;
using System.IO;

namespace CursoCSharp.Api
{
    class Diretorios
    {
        public static void Executar()
        {
            var novoDir = @"~/Desktop/PastaCSharp".ParseHome();
            var novoDirDestino = @"~/Desktop/PastaCSharpDestino".ParseHome();
            var dirProjeto = @"~/Desktop/exercicios-C#/CursoCSharp".ParseHome();

            if (Directory.Exists(novoDir))
            {
                Directory.Delete(novoDir, true);
            }

            Directory.CreateDirectory(novoDir);
            Console.WriteLine(Directory.GetCreationTime(novoDir));
        }
    }
}
