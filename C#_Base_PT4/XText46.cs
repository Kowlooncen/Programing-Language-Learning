// File: "XText46"
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
            Task("XText46");

            string s1 = GetString();
            string s2 = GetString();
            
            StreamReader f1 = new StreamReader(s1, Encoding.Default);
            FileStream f2 = new FileStream(s2, FileMode.Create);

            BinaryWriter w = new BinaryWriter(f2);

            while(!f1.EndOfStream)
            {
                string s = f1.ReadLine();
                char[] chs = { ' ' };
                string[] res = s.Split(chs, options: StringSplitOptions.RemoveEmptyEntries);
                foreach (var item in res)
                {
                    Show(item);
                    if(item.IndexOf(".")!=-1 && item.IndexOf(".00")==-1)
                    {
                        double x = Convert.ToDouble(item);
                        w.Write(x);
                    }
                }
                
            }

            w.Close();
        }
    }
}
