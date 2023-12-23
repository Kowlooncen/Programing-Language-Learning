// File: "XString28"
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
            Task("XString28");
            char c = GetChar();
            string s = GetString();
            s = s.Replace(new string(c,1), new string (c,2) );
            Put(s);
        }
    }
}
