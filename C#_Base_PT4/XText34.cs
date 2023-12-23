// File: "XText34"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("XText34");

            string s1 = GetString();
            string s2 = "XText34.txt";

            StreamReader f1 = new StreamReader(s1, Encoding.Default);
            StreamWriter f2 = new StreamWriter(s2, false, Encoding.Default);
            int n = 0;
            while(!f1.EndOfStream)
            {
                string s = f1.ReadLine();
                if(String.IsNullOrEmpty(s))
                {
                    f2.WriteLine(s);
                    continue;
                }
                f2.WriteLine(s.PadLeft(50));
            }

            f1.Close();
            f2.Close();

            File.Delete(s1);
	        File.Move(s2, s1);
        }
    }
}
