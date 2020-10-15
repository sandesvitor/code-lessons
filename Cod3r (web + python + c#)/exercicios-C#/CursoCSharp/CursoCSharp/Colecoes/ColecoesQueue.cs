using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CursoCSharp.Colecoes
{
    class ColecoesQueue
    {
        public static void Executar()
        {
            //Queue dentro de Collections.Generics
            var fila = new Queue<string>();

            fila.Enqueue("Fulano");
            fila.Enqueue("Sicrano");
            fila.Enqueue("Beltrano");

            Console.WriteLine(fila.Peek());
            Console.WriteLine(fila.Count);

            Console.WriteLine(fila.Dequeue());
            Console.WriteLine(fila.Count);

            foreach(var pessoa in fila)
            {
                Console.WriteLine(pessoa);
            }

            //QUeue dentro apenas de Collections
            var salada = new Queue();
            salada.Enqueue(3);
            salada.Enqueue("Itens");
            salada.Enqueue(true);
            salada.Enqueue(3.14);

            Console.WriteLine(salada.Contains("itens"));
            Console.WriteLine(salada.Contains("Itens"));
        }
    }
}
