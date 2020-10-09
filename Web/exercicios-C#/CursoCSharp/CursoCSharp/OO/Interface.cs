using System;
using System.Collections.Generic;
using System.Text;

namespace CursoCSharp.OO
{
    // Uma interface é uma estrutura na qual todos os métodos
    // são públicos e abstratos!

    interface Teste
    {
        string Bla(string a);
    }

    interface OperacaoBinaria : Teste
    {
        // apesar de ser um método abstrato, não pode colocar
        // um modificador "abstract", poias já está implícito!
        // por padrão PÚBLICOS e ABSTRATOS:
        int Operacao(int a, int b);
    }

    class Soma : OperacaoBinaria
    {
        // a visibilidade PRECISA SER PÚBLICA
        public int Operacao(int a, int b)
        {
            return a + b;
        }

        public string Bla(string teste)
        {
            return teste;
        }
    }

    class Subtracao : OperacaoBinaria
    {
        public int Operacao(int a, int b)
        {
            return a - b;
        }

        public string Bla(string teste)
        {
            return teste;
        }
    }

    class Multiplicacao : OperacaoBinaria
    {
        public int Operacao(int a, int b)
        {
            return a * b;
        }

        public string Bla(string teste)
        {
            return teste;
        }
    }

    class Calculadora
    {
        List<OperacaoBinaria> operacoes = new List<OperacaoBinaria>
        {
            new Soma(),
            new Subtracao(),
            new Multiplicacao()
        };

        public string ExecutarOperacoes(int a, int b)
        {
            string resultado = "";

            foreach (var op in operacoes)
            {
                // "getType.Name === retorna o nome da classe!
                resultado += $"Usando a {op.GetType().Name} = {op.Operacao(a, b)}\n";
            }

            return resultado;
        }
    }

    class Interface
    {
        public static void Executar()
        {
            var calc = new Calculadora();
            var resultado = calc.ExecutarOperacoes(20, 5);

            Console.WriteLine(resultado);

            var teste = new Soma();
            Console.WriteLine(teste.Bla("TESTE"));
        }
    }
}
