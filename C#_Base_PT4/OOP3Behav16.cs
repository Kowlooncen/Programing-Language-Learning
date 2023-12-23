// File: "OOP3Behav16"
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
            public string[] n=new string[10];
            public double[] v=new double[10];
            public Context()
            {
                for(int i=0;i<10;i++){
                    n[i]=Convert.ToString((char)('a'+i));
                    v[i]=1.0;
                }
            }
            public void SetVar(int ind,string name,double value)
            {
                n[ind]=name;
                v[ind]=value;
            }
            public string GetName(int ind)
            {
                return n[ind];
            }
            public double GetValue(int ind)
            {
                return v[ind];
            }
        }

        public abstract class AbstractExpression
        {
            public abstract string InterpretA(Context cont);
            public abstract string InterpretB(Context cont);
            public abstract double InterpretC(Context cont);
        }

        // Implement the TermConst, TermVar
        //   and NontermMath descendant classes
        class TermConst:AbstractExpression
        {
            double x;
            public TermConst(double x)
            {
                this.x=x;
            }
            public override string InterpretA(Context cont)
            {
                return x.ToString("f2");
            }
            public override string InterpretB(Context cont)
            {
                return x.ToString("f2");
            }
            public override double InterpretC(Context cont)
            {
                return x;
            }
        }
        class TermVar:AbstractExpression
        {
            int ind;
            public TermVar(int ind)
            {
                this.ind=ind;
            }
            public override string InterpretA(Context cont)
            {
                return cont.n[ind];
            }
            public override string InterpretB(Context cont)
            {
                return cont.n[ind];
            }
            public override double InterpretC(Context cont)
            {
                return cont.v[ind];
            }
        }
        class NontermMath:AbstractExpression
        {
            AbstractExpression expr1 ,expr2;
            char op;
            public NontermMath(AbstractExpression expr1,AbstractExpression expr2,char c)
            {
                op=c;
                this.expr1=expr1;
                this.expr2=expr2;
            }
            public override string InterpretA(Context cont)
            {
                string info="("+expr1.InterpretA(cont)+Convert.ToString(op)+expr2.InterpretA(cont)+")";
                return info;
            }
            public override string InterpretB(Context cont)
            {
                string info=expr1.InterpretB(cont)+" "+expr2.InterpretB(cont)+" "+Convert.ToString(op);
                return info;
            }
            public override double InterpretC(Context cont)
            {
                double x=0;
                switch(op)
                {
                    case '+':
                        x=expr1.InterpretC(cont)+expr2.InterpretC(cont);
                        break;
                    case '-':
                        x=expr1.InterpretC(cont)-expr2.InterpretC(cont);
                        break;
                    case '*':
                        x=expr1.InterpretC(cont)*expr2.InterpretC(cont);
                        break;
                    case '/':
                        x=expr1.InterpretC(cont)/expr2.InterpretC(cont);
                        break;
                }
                return x;
            }
        }

        public class Client
        {
            AbstractExpression expr;
            Context cont;
            public Client(AbstractExpression expr, Context cont)
            {
                this.expr = expr;
                this.cont = cont;
            }
            public string InterpretA()
            {
                return expr.InterpretA(cont);
            }
            public string InterpretB()
            {
                return expr.InterpretB(cont);
            }
            public double InterpretC()
            {
                return expr.InterpretC(cont);
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav16");
            int N=GetInt();
            AbstractExpression[] ab=new AbstractExpression [N];
            for(int i=0;i<N;i++){
                char c=GetChar();
                AbstractExpression ex=null;
                switch(c)
                {
                    case 'V':
                        int ind=GetInt();
                        ex=new TermVar(ind);
                        break;
                    case 'C':
                        double x=GetDouble();
                        ex=new TermConst(x);
                        break;
                    case 'M':
                        int ind1=GetInt(),ind2=GetInt();
                        char op=GetChar();
                        ex=new NontermMath(ab[ind1],ab[ind2],op);
                        break;
                }
                ab[i]=ex;
            }
            Context cont=new Context();
            int M=GetInt();
            for(int i=0;i<M;i++){
                int ind=GetInt();
                string name=GetString();
                double val=GetDouble();
                cont.SetVar(ind,name,val);
            }
            Client cli=new Client (ab[N-1],cont);
            Put(cli.InterpretA(),cli.InterpretB(),cli.InterpretC());

        }
    }
}
