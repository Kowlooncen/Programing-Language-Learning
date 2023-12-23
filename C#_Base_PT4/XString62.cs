// File: "XString62"
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
            Task("XString62");

            string s = GetString();

            char[] str = s.ToCharArray();

            int l = s.Length;

            for(int i = 0; i < l; i++)
            {
                if(str[i]>='a'&&str[i]<='z')
                {
                    if(str[i] == 'z')
                        str[i] = 'a';
                    else
                        str[i] = (char)(str[i] + 1);
                }
                if(str[i]>='A'&&str[i]<='Z')
                {
                    if(str[i] == 'Z')
                        str[i] = 'A';
                    else
                        str[i] = (char)(str[i] + 1);
                }
            }
            s = new string(str);
            Put(s); 
        }
    }
}
