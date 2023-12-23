// File: "XText41"
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
            Task("XText41");
            FileStream[] f = new FileStream [3];

            for(int i = 0; i < 3; i ++)
                f[i] = new FileStream(GetString(), FileMode.Open);
            StreamWriter f3 = new StreamWriter(GetString(),false, Encoding.Default);

            BinaryReader[] r = new BinaryReader[3];

            for (int i = 0; i < 3; i++)
                r[i] = new BinaryReader(f[i]);

 //           BinaryWriter w = new BinaryWriter(f[3]);

            while(f[0].Position!=f[0].Length)
            {
                f3.Write('|');
                for(int j = 0; j < 3; j++)
                {
                    int x = r[j].ReadInt32();
                    string str = x.ToString();
                    Show(str);
                    f3.Write(str.PadRight(20));                    
                }
                f3.Write('|');
                f3.Write("\n");
            }

            for (int i = 0; i < 3; i++)
                r[i].Close();
            f3.Close();

        }
    }
}
