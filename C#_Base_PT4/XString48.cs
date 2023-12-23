// File: "XString48"
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
            Task("XString48");
            string s = GetString();
            char []str = s.ToCharArray();
            char c = str[0];

            int l = s.Length;

            for(int i = 1; i < l; i++)
	        {
		        if(str[i] == c)
		        {
			        str[i] = '.';
		        }
		
		        if(str[i] == ' ' && str[i+1] != ' ')
		        {
			        c = str[i+1];
			        i++;
		        } 
	        }
            s = new string (str);
            Show(str);
            Put(s);
        }
    }
}
