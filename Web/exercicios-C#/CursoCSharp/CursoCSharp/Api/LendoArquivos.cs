using System;
using System.IO;

namespace CursoCSharp.Api
{
    class LendoArquivos
    {
        public static void Executar()
        {
            var path = @"~/lendo_arquivos.txt".ParseHome();

            if (!File.Exists(path))
            {
                using (StreamWriter sw = File.AppendText(path))
                {
                    sw.WriteLine("Produto/Preço/Qtde");
                    sw.WriteLine("Caneta Bic Preta/R$1,50/10");
                    sw.WriteLine("Borracha/R$0,50/7");
                }
            }

            try
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    var texto = sr.ReadToEnd();
                    Console.WriteLine(texto);
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
