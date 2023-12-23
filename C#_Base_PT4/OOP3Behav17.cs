// File: "OOP3Behav17"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public class Context
        {
            // Add the constructor, required fields and methods
            string[] name = new string [10];
            int[] values = new int [10];
            public Context(){
                for(int i = 0; i < 10; i++)
                {
                    name[i] = Convert.ToString((Char)('a'+i));
                    values[i] = 0;
                }
            }
            public void SetVar(int ind, string name, int value)
            {
                this.name[ind] = name;
                this.values[ind] = value;
            }
            public string GetName(int ind){
                
                return this.name[ind];
            }

            public int GetValue(int ind)
            {
                return this.values[ind];
            }
        }

        public abstract class AbstractExpression
        {
            public abstract string InterpretA(Context cont);
            public abstract string InterpretB(Context cont);
        }

        // Implement the TermStr, NontermConcat, NontermIf
        //   and NontermLoop descendant classes

        public class NontermConcat : AbstractExpression
        {
            AbstractExpression[] expr; 
            public NontermConcat(AbstractExpression[] expr){
               this.expr = expr;
            }
            public override string InterpretA(Context cont)
            {
                //throw new NotImplementedException();
                string info = "";
                for(int i = 0; i < expr.Count(); i ++)
                {
                    info = info + expr[i].InterpretA(cont);
                }
                return info;
            }

            public override string InterpretB(Context cont)
            {
                //throw new NotImplementedException();
                string info = "";
                for(int i = 0; i < expr.Count(); i++){
                    info = info + expr[i].InterpretB(cont);
                }
                return info;
            }
        }

        public class NontermIf : AbstractExpression
        {
             AbstractExpression expr1 ,expr2;
             int ind;

             public NontermIf(AbstractExpression expr1, AbstractExpression expr2, int ind)
             {
                 this.ind = ind;
                 this.expr1 = expr1;
                 this.expr2 = expr2;
             }

            public override string InterpretA(Context cont)
            {
                //throw new NotImplementedException();
                string info = "(" + cont.GetName(ind) + "?" + expr1.InterpretA(cont) + ":" + expr2.InterpretA(cont) + ")";
                return info;
            }

            public override string InterpretB(Context cont)
            {
                //throw new NotImplementedException();
                if(cont.GetValue(ind) != 0)
                    return expr1.InterpretB(cont);
                else return expr2.InterpretB(cont);
            }
        }

        public class NontermLoop : AbstractExpression
        {
            AbstractExpression expr1;
            int ind;
            public NontermLoop(AbstractExpression expr1, int ind){
                this.expr1 = expr1;
                this.ind = ind;
            }
            public override string InterpretA(Context cont)
            {
                string info="("+cont.GetName(ind)+":"+expr1.InterpretA(cont)+")";
                return info;
               // throw new NotImplementedException();
            }

            public override string InterpretB(Context cont)
            {
                string info="";
                for(int i=0; i < cont.GetValue(ind); i++){
	                info = info + expr1.InterpretB(cont);
	            }
                return info;
            }
        }

        public class TermStr : AbstractExpression
        {
            string info;
            public TermStr(string s)
            {
                info = s;
            }
            public override string InterpretA(Context cont)
            {
               return info;
            }

            public override string InterpretB(Context cont)
            {
                return info;
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav17");
           
           int N = GetInt();
           AbstractExpression[] arr = new AbstractExpression[N];
           for(int i = 0; i < N; i++)
           {
               Char c = GetChar();
               AbstractExpression ex = null;
               switch(c)
               {
                   case 'C':{
                       int K = GetInt();
                       AbstractExpression[] ex0=new AbstractExpression[K];
                       for(int j = 0; j < K; j++)
                       {
                           int ind = GetInt();
                           ex0[j] = arr[ind];
                       }
                       ex = new NontermConcat(ex0);
                       break;
                   }
                   case 'I':{
                       int V = GetInt();
                        int ind1 = GetInt();
                        int ind2 = GetInt();
                        ex = new NontermIf(arr[ind1], arr[ind2], V);
                       break;
                   }
                   case 'L':{
                       int V = GetInt();
                       int ind = GetInt();
                       ex = new NontermLoop(arr[ind], V);
                       break;
                   }
                   case 'S':{
                       string str = GetString();
                       ex = new TermStr(str);
                       break;
                   }
               }
               arr[i] = ex;
           }

            Context[] C = new Context [3] ;

            for(int i = 0; i < 3; i++)
            {
                C[i] = new Context();
                int M = GetInt();
                for(int j = 0; j < M; j++)
                {
                    int ind = GetInt();
                    string name = GetString();
                    int val = GetInt();
                    C[i].SetVar(ind, name, val);
                    Show(C[i].GetValue(1));
                }
                Put(arr[N-1].InterpretA(C[i]), arr[N-1].InterpretB(C[i]));
            }
        }
    }
}
