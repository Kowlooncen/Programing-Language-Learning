// File: "XText50"
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
            Task("XText50");
            string s1 = GetString();
            string s2 = GetString();
            string s3 = GetString();

            StreamReader f0 = new StreamReader(s1, Encoding.Default);
            FileStream f1 = new FileStream(s2, FileMode.Create);
            FileStream f2 = new FileStream(s3, FileMode.Create);

            BinaryWriter w1 = new BinaryWriter (f1);
            BinaryWriter w2 = new BinaryWriter (f2);
            while(!f0.EndOfStream)
            {
                string s = f0.ReadLine();
                ShowLine(s);

                String sb1 = s.Substring(0,30);
                ShowLine(sb1);
                
                w1.Write(sb1.PadRight(80));

                string sb2 = s.Substring(30);
                ShowLine(sb2);
                double x = Convert.ToDouble(sb2);
                ShowLine(x);
                w2.Write(x);
            }

            f0.Close();
            w1.Close();
            w2.Close();
        }
    }
}
