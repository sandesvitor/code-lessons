using System;
using System.IO;

namespace CursoCSharp.Api
{
    public static class ExtensaoString
    {
        public static string ParseHome(this string path)
        {
            string home = (Environment.OSVersion.Platform == PlatformID.Unix ||
                Environment.OSVersion.Platform == PlatformID.MacOSX)
                ? Environment.GetEnvironmentVariable("HOME")
                : Environment.ExpandEnvironmentVariables("%HOMEDRIVE%%HOMEPATH");

            return path.Replace("~", home);
        }

    }
    class PrimeiroArquivo
    {
        public static void Executar()
        {
            // "/" em string é interpretado como Tab
            // "@" serve para interpretar uma string de forma literal!
            // "~" serve para resolver a pasta Home, porém não é nterpretado por padrão!

            //var path = @"~/Snades/Desktop/exercicios-C#/CursoCSharp/primiero_arquivo.txt".ParseHome();
            var path = @"C:\Users\Snades\Desktop\exercicios - C#\CursoCSharp";

            if (!File.Exists(path))
            {
                // usando "using" o C# abre vários recursos para trabalhar
                // e depois os fecha ao sairmos do bloco
                using (StreamWriter sw = File.CreateText(path))
                {
                    sw.WriteLine("Esse é");
                    sw.WriteLine("o nosso");
                    sw.WriteLine("primeio");
                    sw.WriteLine("arquivo!");
                }
                using (StreamWriter sw = File.AppendText(path))
                {
                    sw.WriteLine("");
                    sw.WriteLine("Mais texto");
                }
            }
        }
    }
}
