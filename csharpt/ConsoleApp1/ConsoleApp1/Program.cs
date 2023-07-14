using System;

namespace test1s
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Your name is: ");
            string name = Console.ReadLine();

            Console.WriteLine("Your age is: ");
            int age = int.Parse(Console.ReadLine());

            Console.WriteLine("Hi! You are " + name + ", " + age + " years old...");
        }
    }
}
