// File: "OOP3Behav2"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Subject
        {
            public abstract void Attach(Observer observ);
            public abstract void Detach(Observer observ);
            public abstract void SetInfo(string info);
        }

        // Implement the ConcreteSubject descendant class

        public class ConcreteSubject : Subject
        {
            List<Observer> m_ListObserver = new List<Observer>();

            public override void Attach(Observer pObserver)
            {
                m_ListObserver.Add(pObserver);
            }

            public override void Detach(Observer observ)
            {
                m_ListObserver.Remove(observ);
            }

            public override void SetInfo(string info)
            {
                for(int i = m_ListObserver.Count - 1; i >= 0; i--)
                {
                    m_ListObserver[i].OnInfo(this, info);
                }
            }
        }
        
        public abstract class Observer
        {
            public abstract void OnInfo(Subject sender, string info);
        }

        // Implement the ConcreteObserver descendant class
        public class ConcreteObserver : Observer
        {
            string log;
            char detachInfo;
            public ConcreteObserver(char datachInfo){
                this.detachInfo = datachInfo;
                this.log = null;
            }

            public override void OnInfo(Subject sender, string info)
            {
                this.log = this.log + info;

                int n = log.Length - 1;
                if(log[n] == detachInfo)
                {
                    sender.Detach(this);
                }
            }

            public void Attach(Subject pSubject)
            {
                pSubject.Attach(this);
            }
            public void Detach(Subject pSubject)
            {
                pSubject.Detach(this);
            }
            public string GetLog(){
                return log;
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav2");
            int N = GetInt();
            int K = GetInt();
            string str;
            
            ConcreteSubject subj1 = new ConcreteSubject();
            ConcreteSubject subj2 = new ConcreteSubject();

            ConcreteObserver[] obser = new ConcreteObserver[10];
            for(int i = 0; i < N; i++)
            {
                obser[i] = new ConcreteObserver(Convert.ToChar('a' + i));
                obser[i].Attach(subj1);
                obser[i].Attach(subj2);
            }

            for(int i = 0; i < K; i++)
            {
                str = GetString();
                if(str[0] == '1')
                    subj1.SetInfo(str);
                if(str[0] == '2')
                    subj2.SetInfo(str);
            }

            for(int i = 0; i < N; i++)
            {
                Put(obser[i].GetLog());
            }
        }
    }
}
