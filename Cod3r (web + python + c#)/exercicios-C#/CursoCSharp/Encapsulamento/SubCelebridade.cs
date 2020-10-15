using System;
using System.Collections.Generic;
using System.Text;

namespace Encapsulamento
{
    public class SubCelebridade
    {
        // TRANSMISSÂO (VISIBILIDADE) DE ATRIBUTOS:
        //
        // Todos:
        public string InfoPublica = "Tenho um Instagram!";

        // Herança:
        protected string CorDoOlho = "Verde";

        // Mesmo projeto (mesmo assembly):
        internal ulong NumeroCelular = 55119999999;

        // Herança OU no mesmo projeto (mesmo assembly):
        protected internal string JeitoDeFalar = "Uso muitas gírias!";

        // Mesma class OU herança no mesmo projeto (c# >= 7.2)
        private protected string SegredoFamilia = "Bla Bla!";

        // private é o padrão:
        bool UsaMuitoPhotoshop = true;

        public void MeusAcessos()
        {
            Console.WriteLine("Subcelebridade...");

            Console.WriteLine(InfoPublica);
            Console.WriteLine(CorDoOlho);
            Console.WriteLine(NumeroCelular);
            Console.WriteLine(JeitoDeFalar);
            Console.WriteLine(SegredoFamilia);
            Console.WriteLine(UsaMuitoPhotoshop);
        }
    }
}
