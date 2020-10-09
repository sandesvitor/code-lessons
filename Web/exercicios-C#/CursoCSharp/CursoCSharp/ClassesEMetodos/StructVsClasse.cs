using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    public struct SPonto
    {
        public int X;
        public int Y;
    }

    public class CPonto
    {
        public int X;
        public int Y;
    }

    class StructVsClasse
    {
        public static void Executar()
        {
            // STRUCT:
            SPonto ponto1 = new SPonto { X = 1, Y = 3 };
            SPonto copiaPonto1 = ponto1; // ATRIBUIÇÃO POR VALOR, NÃO REFERÊNCIA!!!
            ponto1.X = 3; 
            // Os valores ficam diferentes:
            Console.WriteLine("Ponto 1 X: {0}", ponto1.X);
            Console.WriteLine("Cópia Ponto 1 X: {0}", copiaPonto1.X);


            // CLASSE:
            CPonto ponto2 = new CPonto { X = 2, Y = 4 };
            CPonto copiaPonto2 = ponto2; // ATRIBUIÇÃO POR REFERÊNCIA, NÃO VALOR!!!
            ponto2.X = 4; 
            // OS VALORES APONTAM PARA O MESMO LOCAL DE MEMÓRIA,
            // POR ISSO SE MUDAR EM UM LOCAL MUDA NO OUTRO
            Console.WriteLine("Ponto 2 X: {0}", ponto2.X);
            Console.WriteLine("Cópia do Ponto 2 X: {0}", copiaPonto2.X);
        }
    }
}
