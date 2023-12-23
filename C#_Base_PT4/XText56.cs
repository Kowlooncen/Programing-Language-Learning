// File: "XText56"
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
            Task("XText56");

            string s1 = GetString();
            string s2 = GetString();

            FileStream f1 = new FileStream(s1, FileMode.Open);
            FileStream f2 = new FileStream(s2, FileMode.Create);

            BinaryWriter w = new BinaryWriter (f2);
            BinaryReader r = new BinaryReader (f1);

            int i = 0;
            char[] ch = new char [100];
            while(f1.Position!=f1.Length)
            {
                char x = (char)r.Read();
                Show(x);
                int k = 0;
                for(int j = 0; j< i; j++)
                {
                    if(x == ch[j])
                    {
                        k = 1;
                        break;
                    }
                }
                if(k == 0)
                {
                    ch[i] = x;
                    i++;
                }
            }
            char q;
            for(int m = 0; m < i; m++)
            {
                for(int n = m + 1; n < i; n++)
                {
                    if(ch[m] < ch[n])
                    {
                        q = ch[m];
                        ch[m] = ch[n];
                        ch[n] = q;
                    }
                }
            }

            for(int k = 0; k < i-3; k++)
            {
                char c = ch[k];
                Show(c);
                w.Write(c); 
            }

            char p = ' ';
	        Show(p);
	        w.Write(p); 

            r.Close();
            w.Close();
        }
    }
}
