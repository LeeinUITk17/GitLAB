﻿using System;
using System.Collections.Generic;
using System.Text;

namespace HRAdministrationAPI
{
    public abstract class EmployeeBase : IEmployee
    {
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public virtual decimal Salary { get; set; }

        /*public void show()
        {
            Console.WriteLine("ID: " + Id);
            Console.WriteLine("Fullname: " + FirstName + " " + LastName);
            Console.WriteLine("Salary: " + Salary);
        }*/
    }
}