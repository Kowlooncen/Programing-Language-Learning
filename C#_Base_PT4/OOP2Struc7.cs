// File: "OOP2Struc7"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Component
        {
            public abstract string Show();
        }

        // Implement the ConcreteComponent descendant class
        public class ConcreteComponent : Component
        {
            string s = null;

            public ConcreteComponent(string s)
            {
                this.s = s;
            }
            public override string Show()
            {
                return s;
            }
        }

        public abstract class Decorator : Component
        {
            protected Component comp;
        }

        // Implement the ConcreteDecoratorA
        //   and ConcreteDecoratorB descendant classes
        public class ConcreteDecoratorA : Decorator
        {
            public ConcreteDecoratorA(Component comp)
            {
                this.comp = comp;
            }
            public override string Show()
            {
                //throw new NotImplementedException();
                return "==" + comp.Show() + "==";
            }
        } 

        public class ConcreteDecoratorB : Decorator
        {
            public ConcreteDecoratorB(Component comp)
            {
                this.comp = comp;
            }
            public override string Show()
            {
                //throw new NotImplementedException();
                return "(" + comp.Show() + ")";
            }
        } 
        public static void Solve()
        {
            Task("OOP2Struc7");
            int N = GetInt();
            Component[] arr = new Component[N];
            for(int i = 0; i < N; i++)
            {
                string S = GetString();
                string D = GetString();
                arr[i] = new ConcreteComponent(S);
                for(int j = 0; j < D.Length; j++)
                {
                    if(D[j] == 'A')
                    {
                        ConcreteDecoratorA a = new ConcreteDecoratorA(arr[i]);
                        arr[i] = new ConcreteComponent(a.Show());
                    }else{
                        ConcreteDecoratorB b = new ConcreteDecoratorB(arr[i]);
                        arr[i] = new ConcreteComponent(b.Show());
                    }
                }
            }

            for(int i = N-1; i >= 0; i--)
            {
                Put(arr[i].Show());
            }

        }
    }
}
