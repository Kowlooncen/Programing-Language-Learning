// File: "OOP1Creat7"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Prototype
        {
            public abstract Prototype Clone();
            public abstract void ChangeId(int id);
            public abstract string GetInfo();
        }

        // Implement the ConcretePrototype1
        public class ConcretePrototype1 : Prototype
        {
            int id;
            string s;       
            public ConcretePrototype1(int id, string s) {
                this.id = id;
                this.s = s;
            }

            public override Prototype Clone() 
            {
                return new ConcretePrototype1(id, s);
            }

            public override void ChangeId(int id) 
            {
                this.id = id;
            }

            public override string GetInfo() {
                return  "CP1=" + s + "=" + Convert.ToString(id); 
            }
        };
        //   and ConcretePrototype2 descendant classes
        public class ConcretePrototype2 : Prototype
        {
            int id;
            string s;       
            public ConcretePrototype2(int id, string s) {
                this.id = id;
                this.s = s;
            }

            public override Prototype Clone() 
            {
                return new ConcretePrototype2(id, s);
            }

            public override void ChangeId(int id) 
            {
                this.id = id;
            }

            public override string GetInfo() {
                return  "CP2=" + s + "=" + Convert.ToString(id); 
            }
        };


        public class Client
        {
            // Add required fields
            List<Prototype> P = new List<Prototype>();
            public Client(Prototype p)
            {
                // Implement the constructor
                P.Add(p);
            }
            public void AddObject(int id)
            {
                // Implement the method
                Prototype p = P[0].Clone();
                p.ChangeId(id);
                P.Add(p);
            }
            public string GetObjects()
            {
                string s = null;
                int i = 0;
                for(; i < P.Count-1; i++)
                {
                    s = s + P[i].GetInfo ()+" ";
                }
                s = s + P[i].GetInfo();
                return s;
                // Remove the pr
            }
        }

        public static void Solve()
        {
            Task("OOP1Creat7");
            string s = GetString();
            int N = GetInt();
            int[] id = new int [N];
            for(int i =0 ; i < N; i++){
                id[i] = GetInt();
            }

            ConcretePrototype1 cp1 = new ConcretePrototype1(id[0], s);
            ConcretePrototype2 cp2=new ConcretePrototype2(id[0], s);

            Client c1 = new Client(cp1);
            Client c2 = new Client(cp2);
            for(int i = 1; i < N; i++)
            {
                c1.AddObject (id[i]);
                c2.AddObject(id[i]);
            }
            Put(c1.GetObjects());
            Put(c2.GetObjects ());
        }
    }
}
