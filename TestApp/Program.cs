﻿using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Test();
            Console.ReadKey();
        }

        [DllImport("SharpMP-Natives.dll")]
        private static extern int dllFunc();


        private static void Test()
        {
            dllFunc();
        }
    }
}