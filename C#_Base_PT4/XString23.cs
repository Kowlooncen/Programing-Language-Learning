// File: "XString23"
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
            Task("XString23");
            string s = GetString();
            int n = s.Length;
            int cnt = 0;
            int k = 1;
            for(int i = 0; i < n; i++)
            {
                if(s[i]=='+'){
                    k = 1;
                }
                else if(s[i]=='-'){
                    k = 0;                   
                }
                else {
                    if (k == 1)
                        cnt = cnt + (s[i] - '0');
                    else
                        cnt = cnt - (s[i] - '0');
                }
            }
            Put(cnt);
        }
    }
}
