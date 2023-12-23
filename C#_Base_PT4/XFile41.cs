// File: "XFile41"
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
        public static async void Solve()
        {
            Task("XFile41");

            string s1 = GetString();
            string s2 = "XFile41.tmp";

            FileStream f1 = new FileStream(s1, FileMode.Open);
            FileStream f2 = new FileStream(s2, FileMode.Create);

            BinaryReader r = new BinaryReader(f1);
            BinaryWriter w = new BinaryWriter(f2);

            while(f1.Position < f1.Length)
            {
                int x = r.ReadInt32();
                if(x > 0)
                {
                    for(int i = 0; i < 3; i++)
                    {
                        w.Write(0);
                    }
                }
                else{
                    w.Write(x);
                }
            }
	
	        f2.Close();
            f1.Close();
            
            File.Delete(s1);
	        File.Move(s2, s1);
        }
    }
}
