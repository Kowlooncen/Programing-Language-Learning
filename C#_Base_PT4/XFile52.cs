// File: "XFile52"
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
            Task("XFile52");

            string s0 = GetString();

            FileStream g = new FileStream(s0, FileMode.Create);

            int N = GetInt();

            FileStream[] f = new FileStream[N];
            for(int k= 0; k < N; k ++){
                f[k] = new FileStream(GetString(), FileMode.Open);
            }

            BinaryReader[] r = new BinaryReader[N];
            for (int i = 0; i < N; i++)
                r[i] = new BinaryReader(f[i]);

            BinaryWriter w = new BinaryWriter(g);


            w.Write(N);
            for(int k = 0; k < N; k ++){
                int x = (int)f[k].Length/sizeof(int);
                w.Write(x);
            }

            for(int k = 0; k < N; k ++)
                while (f[k].Position < f[k].Length)
                    w.Write(r[k].ReadInt32());

            for (int i = 0; i < N; i++)
                r[i].Close();
            w.Close();
        }
    }
}
