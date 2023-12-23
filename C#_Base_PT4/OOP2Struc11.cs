// File: "OOP2Struc11"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Flyweight
        {
            public abstract char Show(bool state);
        }

        // Implement the ConcreteFlyweight
        //   and UnsharedConcreteFlyweight descendant classes

        public class ConcreteFlyweight : Flyweight
        {
            public override char Show(bool state)
            {
                //throw new NotImplementedException();
                if(state == true) return 'A';
                else return 'a';
            }
        }

        public class UnsharedConcreteFlyweight : Flyweight
        {
            char inf;
            public UnsharedConcreteFlyweight(char c)
            {
                inf = c;
            }
            public override char Show(bool state)
            {
                //throw new NotImplementedException();
                if(state == true) {
                    return Char.ToUpper(inf);
                }
                else{
                    return Char.ToLower(inf);
                }
            }
        } 
        // Implement the FlyweightFactory and Client classes

        public class FlyweightFactory
        {
            ConcreteFlyweight cf;
            int count;
            public FlyweightFactory()
            {
                cf = null;
                count = 0;
            }

            public Flyweight CreatFlyeight(char inf)
            {
                if(inf != 'A' && inf != 'a')
                {
                    count ++;
                    return new UnsharedConcreteFlyweight(inf);
                }
                else{
                    if(cf == null)
                    {
                        cf = new ConcreteFlyweight();
                        count ++;
                        return cf;
                    }
                    else return cf;
                }
            }
            public int GetCount(){
                return count;
            }
        }

        public class Client
        {
            FlyweightFactory f;
            Flyweight[] fw;
            int x; 
            public Client(){
                f = new FlyweightFactory();
                fw = new Flyweight[30];
                x = 0;
            }

            public void MakeFlywights(string str)
            {
                for(int i = 0; i < str.Length; i++)
                {
                    fw[i] = f.CreatFlyeight(str[i]);
                }
                x = str.Length;
            }

            public string ShowFlyweights(bool state)
            {
                string s = null;
                for(int i = 0; i < x; i++)
                {
                    s = s + fw[i].Show(state);
                }
                return s;
            }
            public int GetFlyweightCount(){
		        return f.GetCount();
	        }
        }
        public static void Solve()
        {
            Task("OOP2Struc11");
            string s;
            Client cl = new Client();
            for(int i = 0; i < 5; i++)
            {
                s = GetString();
                cl.MakeFlywights(s);
                Put(cl.ShowFlyweights(true));
                Put(cl.ShowFlyweights(false));
                Put(cl.GetFlyweightCount());
            }
        }
    }
}
