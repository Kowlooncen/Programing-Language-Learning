// File: "OOP3Behav12"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Colleague
        {
            Mediator m;
            public void SetMediator(Mediator m)
            {
                this.m = m;
            }
            public void Notify()
            {
                m.NotifyFrom(this);
            }
        }

        // Implement the ConcreteColleague1
        //   and ConcreteColleague2 descendant classes
        public class ConcreteColleague1 : Colleague
        {
            int data;
            public ConcreteColleague1(){
                data = 1;
            }

            public int GetData(){
                return data;
            }
            public void SetData(int d)
            {
                data = d;
            }
        } 

        public class ConcreteColleague2 : Colleague
        {
            string data;
            public ConcreteColleague2(){
                data = "ab";
            }
            public string GetData(){
                return data;
            }
            public void SetData(string d)
            {
		        data = d;
	        }
        } 

        public abstract class Mediator
        {
            public abstract void NotifyFrom(Colleague coll);
        }

        // Implement the ConcreteMediatorA
        //   and ConcreteMediatorB descendant classes

        public class ConcreteMediatorA : Mediator
        {
            ConcreteColleague1 c1 = null;
            ConcreteColleague2 c2 = null;

            public ConcreteMediatorA()
            {
                c1 = new ConcreteColleague1 ();
                c2 = new ConcreteColleague2 ();
                c1.SetMediator(this);
                c2.SetMediator(this);
            }

            public Colleague GetC1(){
                return c1;
            }
            public Colleague GetC2(){
                return c2;
            }

            public override void NotifyFrom(Colleague coll){
                if(coll == c1)
                {
                    string str = " " + Convert.ToString(c1.GetData());
                    c2.SetData(c2.GetData()+str);
                }
                if(coll == c2)
                {
                    c1.SetData(c1.GetData() + c2.GetData().Length);
                }
                Show(c1.GetData());
		        Show(c2.GetData());
                Put(c1.GetData(), c2.GetData());
            }
        }

        public class ConcreteMediatorB : Mediator
        {
            ConcreteColleague1 c1a = null;
            ConcreteColleague1 c1b = null;
            ConcreteColleague2 c2 = null;
            int count(char c, string s) 
            {
                int cnt = 0;
                foreach (Char e in s) 
                {
                    if (e == c)
                        cnt++;
                }
                return cnt;
            }
            public ConcreteMediatorB(){
                c1a = new ConcreteColleague1();
                c1b = new ConcreteColleague1();
                c2 = new ConcreteColleague2();
                c1a.SetMediator(this);
                c1b.SetMediator(this);
                c2.SetMediator(this);
            }
            public Colleague GetC1a(){
                return c1a;
            }

            public Colleague GetC1b(){
                return c1b;
            }
            public Colleague GetC2(){
                return c2;
            }

            public override void NotifyFrom(Colleague coll)
            {
                if(coll == c1a){
                    c1b.SetData(c1b.GetData() + c1a.GetData());
                    c2.SetData(c2.GetData() + "a");
                }
                if(coll == c1b){
                    c1a.SetData(c1b.GetData() + c1a.GetData());
                    c2.SetData(c2.GetData() + "b");
                }
                if(coll == c2){
                    c1a.SetData(count('a', c2.GetData()));
                    c1b.SetData(count('b', c2.GetData()));
                }
                Show(c1a.GetData());
                Show(c1b.GetData());
		        Show(c2.GetData());
                Put(c1a.GetData(), c1b.GetData(), c2.GetData());
            }
        }


        public static void Solve()
        {
            Task("OOP3Behav12");
            ConcreteMediatorA ma = new ConcreteMediatorA();
            ConcreteMediatorB mb = new ConcreteMediatorB();

            List<Colleague> coll = new List<Colleague>();

            coll.Add(ma.GetC1());
            coll.Add(ma.GetC2());
            coll.Add(mb.GetC1a());
            coll.Add(mb.GetC1b());
            coll.Add(mb.GetC2());
            
            int N = GetInt();

            for(int i = 0; i < N; i ++)
            {
                int n = GetInt();
                coll[n].Notify();
            }
        }
    }
}
