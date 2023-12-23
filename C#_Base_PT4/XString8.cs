// File: "XString8"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("XString8");
            // Thread.CurrentThread.CurrentCulture = 
            //     new CultureInfo("en-US");
            // HideTask();
            // int a = int.MaxValue;
            // Show(a);
            // int b = int.Parse("123");
            // Show(b + 1);
            // double y = Math.Log(1);
            // Show(y);
            // var v =Math.PI.ToString();
            // Show(v);
            // Show(DateTime.Now);
            // Console.WriteLine("Enter your name");
            // string name = Console.ReadLine();
            // Show(name);
            int N = GetInt();
            
            char c = GetChar();

            string s = new string (c, N);
            
            Put(s);

        }
    }
}
