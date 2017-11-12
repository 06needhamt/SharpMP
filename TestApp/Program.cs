using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpMP;
using System.Threading;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Test();
            Console.ReadKey();
        }

        static void Test()
        {
            int defaultDevice = OpenMP.GetDefaultDevice();
            Console.WriteLine("Default Defice ID: {0}", defaultDevice);

            for (int i = 0; i < 10; i++)
            {
                double wTime = OpenMP.GetWTime();
                Console.WriteLine("WTime: {0}", wTime);
                Thread.Sleep(1000);
            }

            double wTick = OpenMP.GetWTick() * Math.Pow(10,7);
            Console.WriteLine("WTick: {0}", wTick);
        }
    }
}
