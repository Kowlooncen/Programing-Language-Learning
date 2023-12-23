// File: "XText11"
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
            Task("XText11");
            
            string s1 = GetString();
            string s2 = "XText11.tst";

            StreamReader f1 = new StreamReader(s1, Encoding.Default);
            StreamWriter f2 = new StreamWriter(s2, false, Encoding.Default);

            while(!f1.EndOfStream)
            {
                string line = f1.ReadLine();
                f2.WriteLine(line);
                if(String.IsNullOrEmpty(line))
                {
                    f2.Write('\n');
                }
            }
            
            f1.Close();
            f2.Close();

            File.Delete(s1);
	        File.Move(s2, s1);
            
        }
    }
}
