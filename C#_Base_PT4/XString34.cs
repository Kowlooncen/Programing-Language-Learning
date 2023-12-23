// File: "XString34"
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
            Task("XString34");
            string s = GetString();
            string s0 = GetString();

            // bool b = s.Contains(s0);
            // Show(b);

            int l = s.Length;
            int l0 =  s0.Length;
            int index = s.LastIndexOf(s0);
            ShowLine("index", index);

            if (index != -1)
            {
                ShowLine("l = ", l);
                ShowLine("l0 = ", l0);
                s = s.Remove(index, l0);
            }

            Put(s);
        }
    }
}
