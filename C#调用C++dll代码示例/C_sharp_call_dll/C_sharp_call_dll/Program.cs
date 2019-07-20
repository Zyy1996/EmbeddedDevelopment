using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace C_sharp_call_dll
{
    class Program
    {
        [DllImport("Dll1.dll", CallingConvention = CallingConvention.Winapi)]
        public static extern int add(int a, int b);

        [DllImport("Dll1.dll", CallingConvention = CallingConvention.Winapi)]
        public static extern int sub(int a, int b);

        static void Main(string[] args)
        {
            // The code provided will print ‘Hello World’ to the console.
            // Press Ctrl+F5 (or go to Debug > Start Without Debugging) to run your app.
            int b = add(10, 10);
            Console.WriteLine(b);
            int c = sub(10, 10);
            Console.WriteLine(c);
            Console.WriteLine("Hello World!");
            Console.ReadKey();

            // Go to http://aka.ms/dotnet-get-started-console to continue learning how to build a console app! 
        }
    }
}
