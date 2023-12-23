// File: "XFile8"
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
            Task("XFile8");
            string s1 = GetString();
            string s2 = GetString();
            
            FileStream f1 = new FileStream(s1, FileMode.Open);
            FileStream f2 = new FileStream(s2, FileMode.Create);

            BinaryReader r = new BinaryReader(f1);
            BinaryWriter w = new BinaryWriter(f2);

            f1.Seek(0, SeekOrigin.Begin);

            w.Write(r.ReadDouble());

            f1.Seek(-sizeof(double), SeekOrigin.End);

            w.Write(r.ReadDouble());

            f1.Close();
            f2.Close();
        }
    }
}
