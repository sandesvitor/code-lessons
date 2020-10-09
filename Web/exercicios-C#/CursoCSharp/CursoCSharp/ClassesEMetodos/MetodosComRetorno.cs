using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    class CalculadoraComum
    {
        public int Somar(double a, int b)
        {
            return (int)a + b;
        }

        public int Somar(int a, double b)
        {
            return a + (int)b;
        }

        public int Subtrair(int a, int b)
        {
            return a - b;
        }

        public int Multiplicar(int a, int b)
        {
            return a * b;
        }
    }

    class CalculadoraCadeia
    {
        private int memoria;

        public CalculadoraCadeia Somar(int a)
        {
            memoria += a;
            return this;
        }
        
        public CalculadoraCadeia Multiplicar(int a)
        {
            memoria *= a;
            return this;
        }

        public CalculadoraCadeia Limpar()
        {
            memoria = 0;
            return this;
        }

        public CalculadoraCadeia Imprimir()
        {
            Console.WriteLine(memoria);
            return this;
        }

        public int Resultado()
        {
            return memoria;
        }
    }

    class MetodosComRetorno
    {
        public static int Somar(double a, int b)
        {
            return (int)a + b;
        }

        public static void Executar()
        {
            var calculadoraComum = new CalculadoraComum();
            var resultado1 = calculadoraComum.Somar(5.0, 5);
            Console.WriteLine(resultado1);

            var resultado2 = Somar(1.0, 1);
            Console.WriteLine(resultado2);


            var calculadoraCadeia = new CalculadoraCadeia();
            calculadoraCadeia
                    .Somar(3)
                    .Multiplicar(3)
                    .Imprimir()
                    .Limpar()
                    .Imprimir();

            var resultado3 = calculadoraCadeia
                    .Somar(3)
                    .Multiplicar(2)
                    .Resultado();

            Console.WriteLine(resultado3);




        }
    }
}
