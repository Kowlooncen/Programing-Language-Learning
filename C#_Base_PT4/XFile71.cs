// File: "XFile71"
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
            Task("XFile71");

            string s = GetString();

            FileStream f = new FileStream(s, FileMode.Open);
            BinaryReader r = new BinaryReader(f);

            int N = 100;

            int[] d = new int[N];
            int[] m = new int[N];
            int[] y = new int[N];

            string str;

            int n = 0;
            while(f.Position < f.Length)
            {
                char x = r.ReadChar();

                if(x == 'P' )
                {
                    str = new string(r.ReadChars(2));
                    d[n] = Convert.ToInt16(str);
                    r.ReadChar();
                    str = new string(r.ReadChars(2));
                    m[n] = Convert.ToInt16(str);
                    r.ReadChar();
                    str = new string(r.ReadChars(4));
                    y[n] = Convert.ToInt32(str);
                    n++;
                }
                
            }
            
            ShowLine("n=", n);
            r.Close();

            Int32 y_min = 2022;
            int m_min = 3;
            int d_min = 28;

            int dis = 1;

            for(int j = 0; j < n; j++)
            {
                if(m[j] >= 3 && m[j] <= 5)
                {
                    if(y_min > y[j])
                    {
                        y_min = y[j];  
                        m_min = m[j]; 
                        d_min = d[j];   
                    }
                    else if(y_min == y[j])
                    {
                        if(m_min > m[j])
                        {
                            m_min = m[j]; 
                            d_min = d[j]; 
                        } 
                        else if(m_min == m[j])
                        {
                            if(d_min > d[j])
                                d_min = d[j];                               
                        }
                    }
                    dis = 0; 
                }
            }
            if(dis == 0)
                Put(d_min.ToString("D2")+"/"+m_min.ToString("X2")+"/"+y_min.ToString());
            else
                Put("");

        }
    }
}
