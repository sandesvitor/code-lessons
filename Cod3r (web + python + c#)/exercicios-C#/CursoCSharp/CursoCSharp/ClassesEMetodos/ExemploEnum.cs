using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    public enum Genero { Acao, Aventura, Terror, Animacao, Comedia };

    public class Filme
    {
        public string Titulo;
        public Genero GeneroDoFilme;
    }

    class ExemploEnum
    {
        public static void Executar()
        {
            int id = (int)Genero.Animacao; // podemos fazer esse "cast" para converter os itens do enum
            Console.WriteLine(id);

            var filmeParaFamilia = new Filme();
            filmeParaFamilia.Titulo = "Sharknado 17";
            filmeParaFamilia.GeneroDoFilme = Genero.Comedia;

            Console.WriteLine("{0} é um filme de {1}", filmeParaFamilia.Titulo, filmeParaFamilia.GeneroDoFilme);
        }
    }
}
