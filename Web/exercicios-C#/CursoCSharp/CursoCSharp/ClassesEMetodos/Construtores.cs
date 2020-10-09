using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    class Carro
    {
        public string Modelo;
        public string Fabricante;
        public int Ano;

        //Construtor:
        public Carro(string modelo, string fabricante, int ano)
        {
            this.Modelo = modelo;
            this.Fabricante = fabricante;
            this.Ano = ano;
            //não precisa do "this".
        }
    }

    class Construtores
    {
        public static void Executar()
        {
            // Construtor Padrão (quando não é definido um construtor na classe):
            //var carro1 = new Carro();

            //carro1.Fabricante = "BMW";
            //carro1.Modelo = "325i";
            //carro1.Ano = 2017;

            var carro1 = new Carro("Ka", "Ford", 2018);
            Console.WriteLine(
                $"{carro1.Fabricante} {carro1.Modelo} {carro1.Ano}");

        }
    }
}
