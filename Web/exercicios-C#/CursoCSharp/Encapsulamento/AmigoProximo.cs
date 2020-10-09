using System;
using System.Collections.Generic;
using System.Text;

namespace Encapsulamento
{
    public class AmigoProximo
    {
        public readonly SubCelebridade amiga = new SubCelebridade(); // relação de COMPOSIÇÃO

        public void MeusAcessos()
        {
            Console.WriteLine("Amigo próximo...");

            Console.WriteLine(amiga.InfoPublica);
            //Console.WriteLine(amiga.CorDoOlho); // só transmitido por herança!
            Console.WriteLine(amiga.NumeroCelular);
            Console.WriteLine(amiga.JeitoDeFalar);
            //Console.WriteLine(amiga.SegredoDeFamilia); // só é transmitido por herança dentro do assembly!
            //Console.WriteLine(amiga.UsaMuitoPhotoshop);
        }
    }
}
