// File: "XString14"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static async void Solve()
        {
            Task("XString14");

            string s = GetString();

            int n = s.Length;

            int cnt = 0;

            for(int i = 0; i < n; i++)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    cnt++;
            }
                
            Put(cnt);
        }
    }
}
