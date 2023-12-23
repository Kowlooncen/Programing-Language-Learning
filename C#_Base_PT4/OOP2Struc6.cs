// File: "OOP2Struc6"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Device
        {
            public virtual void Add(Device d) {}
            public abstract string GetName();
            public abstract int GetTotalPrice();
        }

        // Implement the SimpleDevice
        //   and CompoundDevice descendant classes
        public class SimpleDevice : Device
        {
            string str = null;
            int price;
            public SimpleDevice(string s, int x)
            {
                str = s;
                price = x;
            }
            public override  void Add(Device d) {

            }
            public override string GetName(){
                return str;
            }
            public override int GetTotalPrice(){
                return price;
            }
        } 

        public class CompoundDevice : Device
        {
            string str = null;
            int price;
            List<Device> ls = new List<Device>();
            public CompoundDevice(string s, int x)
            {
                str = s;
                price = x;
            }
            public override  void Add(Device d) {
                ls.Add(d);
            }
            public override string GetName(){
                return str;
            }
            public override int GetTotalPrice(){
                int sum = price;
                for(int i = 0; i < ls.Count; i++)
                {
                    sum = sum + ls[i].GetTotalPrice();
                }
                return sum;
            }
        } 
        public static void Solve()
        {
            Task("OOP2Struc6");
            int N = GetInt();
            Device[] d = new Device [15];
            for(int i = 0; i < N; i++)
            {
                string name = GetString();
                int price = GetInt();

                if(name[0]>='A'&&name[0]<='Z')
                {
                    d[i] = new CompoundDevice(name, price);
                }
                else{
                    d[i] = new SimpleDevice(name, price);
                }
            }

            int[] x = new int [15];
            for(int i = 0; i < N; i++)
            {
                x[i] = GetInt();			
                if(x[i] != -1 )
                    d[x[i]].Add(d[i]);
            }

            for(int i = 0; i < N; i++)
            {
                Show(d[i].GetName()) ;
                Show(d[i].GetTotalPrice()) ;
                Put(d[i].GetName(), d[i].GetTotalPrice());
            }
        }
    }
}
