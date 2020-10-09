using System;
using System.Collections.Concurrent;
using System.Linq;
using System.Text;

namespace LinkedLists
{
    public class Node
    {
        public int data;
        public Node next;


        // CONSTRUCTOR:
        public Node(int i)
        {
            data = i;
            next = null;
        }

        public void Print()
        {
            Console.Write("|" + data + "| -> ");
            if (next != null)
            {
                next.Print();
            }
        }

        public void AddSorted(int data)
        {
            if (next == null)
            {
                next = new Node(data);
            }
            else if (data < next.data)
            {
                Node temp = new Node(data);
                temp.next = this.next;
                this.next = temp;  
            }
            else
            {
                next.AddSorted(data); // pass responsability to the next node in the list until adding sucessfuly!
            }
        }

        public void AddToEnd(int data)
        {
            // In this case we know that this is the end of the list, so we just add a new Node!
            if (next == null)
            {
                next = new Node(data);
            }
            else
            {
                // recursive call (passa the responsibility down to the chain, until "next" == null)!
                next.AddToEnd(data);
            }
        }
    }

    public class MyList
    {
        public Node headNode;

        // CONSTRUCTOR:
        public MyList()
        {
            headNode = null;
        }

        public void AddSorted(int data)
        {
            if (headNode == null)
            {
                headNode = new Node(data);
            }
            else if (data < headNode.data)
            {
                AddToBeginning(data);
            }
            else
            {
                headNode.AddSorted(data);
            }
        }

        public void AddToEnd(int data)
        {
            if (headNode == null)
            {
                headNode = new Node(data);
            }
            else
            {
                headNode.AddToEnd(data);
            }
        }

        public void AddToBeginning(int data)
        {
            if (headNode == null)
            {
                headNode = new Node(data);
            }
            else
            {
                // Creating a temporary Node!
                Node temp = new Node(data);


                // BE WARY OF THE ORDER OF THIS OPERATIONS!
                //
                //

                // 1) Adjust tempNode "next pointer" points to headNode;
                temp.next = headNode;

                // 2) Adjust headNode (head pointer) points to headNode to the node temp
                // is pointing to:
                headNode = temp;
            }
        }

        public void Print()
        {
            if (headNode != null)
            {
                headNode.Print();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Node myNode = new Node(7);

            // NOT SCALABLE:
            //myNode.next = new Node(5);
            //myNode.next.next = new Node(11);
            //myNode.next.next.next = new Node(12);
            //myNode.Print();

            //SCALABLE:
            //myNode.AddToEnd(5);
            //myNode.AddToEnd(11);
            //myNode.AddToEnd(12);
            //myNode.Print();


            //MyList list = new MyList();
            //list.AddToEnd(9);
            //list.AddToEnd(5);
            //list.AddToEnd(7);
            //list.AddToEnd(11);

            //list.AddToBeginning(1);
            //list.AddToBeginning(3);
            //list.AddToBeginning(10);

            MyList list = new MyList();
            list.AddSorted(9);
            list.AddSorted(5);
            list.AddSorted(7);
            list.AddSorted(11);
            list.AddSorted(1);

            list.Print();
        }
    }
}
