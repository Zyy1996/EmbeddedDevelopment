using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace call_c_cpp
{
    class Program
    {
        [DllImport("circle.dll", CallingConvention = CallingConvention.Winapi)] //c++
        public static extern int add(int a, int b);

        [DllImport("cgrid.dll", CallingConvention = CallingConvention.Winapi)] //c
        public static extern double calcnt(double area, double boxarea);

        static void Main(string[] args)
        {
            //int sum = add(1, 3);
            double cnt = calcnt(100, 2);
            Console.Write(cnt);
            Console.Read();
        }
    }
}
