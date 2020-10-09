using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.ClassesEMetodos
{
    public class Cliente
    {
        public string Nome;
        //const DateTime Nascimento; ---> tipo "DateTime" não permite "const"
        readonly DateTime Nascimento; //---> pode ser setado dentro do construtor!


        /*
         * Const: é o valor imutável avaliado no tempo de COMPILAÇÃO (precisa ser inicializada).
         * Readonly: é o valor imutável avaliado no contexto de EXECUÇÃO (neste caso no construtor)
         */

        public Cliente(string nome, DateTime nascimento)
        {
            Nome = nome;
            Nascimento = nascimento;
        }

        public string GetDataDeNascimento()
        {
            return String.Format("{0}/{1}/{2}", Nascimento.Day,
                Nascimento.Month, Nascimento.Year);
        }
    }
    class Readonly
    {
        public static void Executar()
        {
            Cliente novoClient = new Cliente("Ana Silva", new DateTime(1987, 5, 22));

            Console.WriteLine(novoClient.Nome);
            Console.WriteLine(novoClient.GetDataDeNascimento());
        }
    }
}
