// File: "XString58"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("XString58");

            string s = GetString();

            int n2 = s.LastIndexOf('.');

            int n1 = s.LastIndexOf('\\');
            string sstr;
            if(n2 != -1) 
                sstr = s.Substring(n1+1, n2-n1-1);
            else 
                sstr = s.Substring(n1+1);
            Put(sstr);
        }
    }
}
