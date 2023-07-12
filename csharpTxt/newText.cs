// See https://aka.ms/new-console-template for more information
using System;
using System.Diagnostics.CodeAnalysis;
using System.Security.Cryptography.X509Certificates;
/*namespace hello
{
class program
{
static void Main(string[] args)
{
Console.WriteLine("hello dude");
}
}
}*/
/*class Animal
{
    public string Name { get; set; }
    public string Sex { get; set; }
    public Animal(string name)
    {
        Name = name;
    }
  
    public virtual void MakeSound()
    {
        Console.WriteLine("the animal makes a sound");
    }
    public virtual void show()
    {
        Console.WriteLine("Animal: " + this.Name);
    }
   *//* public string Gioitinh()
    {
        return Sex ? "male" : "female";
    }*//*
}
class Dog : Animal
{
    public Dog(string name)
        :base(name)
    { }
    public override void MakeSound()
    {
        Console.WriteLine("Gau gau");
    }
    public override void show()
    {
        base.show();
    }
}
class Cat : Animal
{
    public Cat(string name)
        :base(name)
    { }
    public override void MakeSound()
    {
        Console.WriteLine("Meo Meo");
    }
    public override void show()
    {
        base.show();
    }
}*/
class Program
{
    static void Main()
    {
        // stringtext();

        // mathtext();
        //madlibs();
        // arraytext();
        //IfelseCondition();
        //caculator();
        /*int daynum = int.Parse(Console.ReadLine());
        Console.WriteLine(getday(daynum));*/
        // looptext();
        //guessingGame();
        int baseNum, powNum;
        Console.Write("enter base number: ");
        baseNum = int.Parse(Console.ReadLine());
        Console.Write("enter pow number: ");
        powNum = int.Parse(Console.ReadLine());
        Console.WriteLine(getPow(baseNum, powNum));
    }
    static void stringtext()
    {
        /* Animal animal = new Animal("animal");
      Dog dog = new Dog("Buggy");
      Cat cat = new Cat("Whiskers");
      dog.MakeSound();
      cat.MakeSound();
      Console.WriteLine(dog.Name);
      dog.Name = "Pull";
      Console.WriteLine(dog.Name);
      dog.show();
      cat.show();*/
        string characterName = Console.ReadLine();
        Console.WriteLine(characterName);
        Console.WriteLine(characterName.Length);
        Console.WriteLine(characterName.ToUpper());
        Console.WriteLine(characterName.ToLower());
        Console.WriteLine(characterName.Contains("tai"));
        Console.WriteLine(characterName[3]);
        Console.WriteLine(characterName.IndexOf("tai"));
        int index = characterName.IndexOf("tai");
        Console.WriteLine(characterName.Substring(index, 3));
    }
    static void mathtext()
    {
        int numone = int.Parse(Console.ReadLine());
        int numtwo = int.Parse(Console.ReadLine());
        double power = Math.Pow(numone, numtwo);
        double sqrtresult = Math.Sqrt(numone * numtwo);
        Console.WriteLine("Power result: " + power);
        Console.WriteLine("Square root result: " + sqrtresult);
        int numthree = int.Parse(Console.ReadLine());
        int max = Math.Max(Math.Max(numone,numtwo), numthree);
        Console.WriteLine("Max : " + max);
        int min = Math.Min(Math.Min(numone, numtwo), numthree);
        Console.WriteLine("Min : " + min);
        Console.WriteLine(Math.Round(sqrtresult));
    }
    static void madlibs()
    {
        string color, pluralNoun, celebrity;
        Console.Write("enter a color: ");
        color = Console.ReadLine();
        Console.Write("enter a plural noun: ");
        pluralNoun = Console.ReadLine();
        Console.Write("enter a celebrity: ");
        celebrity = Console.ReadLine();
        Console.WriteLine("rose are "+ color);
        Console.WriteLine(pluralNoun+" are blue");
        Console.WriteLine("i love "+ celebrity);
    }
    static void arraytext()
    {
        /* int[] number = new int[5];
         for(int i = 0; i < 5; i++)
         {
             number[i] = int.Parse(Console.ReadLine());
         }
         for(int i = 4; i >= 0; i--)
         {
             Console.Write(number[i]+" ");
         }*/
        List<int> number = new List<int>();
        int numb = int.Parse(Console.ReadLine());
        for(int i = 0; i < numb; i++)
        {
            int value = int.Parse(Console.ReadLine());
            number.Add(value);

        }
        Console.WriteLine("list <number> have " + number.Count + " item");
        foreach (var item in number)
        {
            Console.Write(item+" ");
        }
    }
    static void IfelseCondition()
    {
        bool isMale;
        Console.WriteLine("Are you male?" + " \nenter True or False");
        string input = Console.ReadLine();
        if (bool.TryParse(input, out isMale))
        {
            if (isMale)
            {
                Console.WriteLine("Congratulation!, you are male...");
            }
            else
            {
                Console.WriteLine("Oops! get out,Bitch !");
            }
        }
    }
   static int findMax(int[] key)
    {
        int max = key[0];
        for(int i = 0; i< key.Length; i++)
        {
            if (max < key[i])
            {
                max = key[i];
            }
        }
        return max;
    }
    static void maxArray()
    {
        List<int> keyValue = new List<int>();
        int numb = int.Parse(Console.ReadLine());
        for (int i = 0; i < numb; i++)
        {
            int value = int.Parse(Console.ReadLine());
            keyValue.Add(value);
        }
        Console.WriteLine("Max of List is " + findMax(keyValue.ToArray()));
    }
    static void caculator()
    {
        Console.Write("\n\tenter a number 1s: ");
        double numone = Convert.ToDouble(Console.ReadLine());
        
        Console.Write("\n\tenter a operator: ");
        string op = Console.ReadLine();
        
        Console.Write("\n\tenter a number 2s: ");
        double numtwo = Convert.ToDouble(Console.ReadLine());

        if (op == "+")
        {
            Console.WriteLine(numone + " + " + numtwo + " " + " = " + (numone + numtwo));
        }
        else if (op == "-")
        {
            Console.WriteLine(numone + " - " + numtwo + " " + " = " + (numone - numtwo));
        }
        else if (op == "*")
        {
            Console.WriteLine(numone + " * " + numtwo + " " + " = " + (numone * numtwo));
        }
        else if (op == "/")
        {
            Console.WriteLine(numone + " / " + numtwo + " " + " = " + (numone / numtwo));
        }
    }
    static string getday(int daynum)
    {
        string dayname;
        switch(daynum)
        {
            case 2:
                dayname = "Monday";
                break;
            case 3:
                dayname = "Tuesday";
                break;
            case 4:
                dayname = "Wednesday";
                break;
            case 5:
                dayname = "Thursday";
                break;
            case 6:
                dayname = "Friday";
                break;
            case 7:
                dayname = "Saturday";
                break;
            case 8:
                dayname = "Sunday";
                break;
            default:
                dayname = "Invalid day";
                break;
        }
        return dayname;
    }
    static void looptext()
    {
        //while loop
        int i = 1;
        while (i <= 5)
        {
            Console.Write(i+" ");
            i++;
        }
        // do while loop
        List<string> textnew = new List<string>();
        do
        {
            string txt = Console.ReadLine();
            textnew.Add(txt);
        } while (textnew.Count <= 5);
        foreach(var item in textnew)
        {
            Console.Write(item + " ");
        }
    }
    static void guessingGame()
    {
        string secretWord = "taideptrai";
        string guess = " ";
        int guessCount = 0;
        int guessLimit = 5;
        while (guess != secretWord)
        {
            Console.Write("\n enter Guessing Word: ");
            guess = Console.ReadLine();
            guessCount++;
            if (guessCount == guessLimit)
            {
                Console.WriteLine("You Lose !");
                return;
            }
        }
        Console.WriteLine("you win!");
    }
    static int getPow(int baseNum,int powNum)
    {
        int result = 1;
        for(int i = 0; i < powNum; i++)
        {
            result *= baseNum;
        }
        return result;
    }
}