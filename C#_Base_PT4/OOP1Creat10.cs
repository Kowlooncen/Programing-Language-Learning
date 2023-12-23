// File: "OOP1Creat10"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Builder
        {
            public virtual void BuildStart(char c) {}
            public virtual void BuildFirstChar(char c) {}
            public virtual void BuildNextChar(char c) {}
            public virtual void BuildFirstSpace() {}
            public abstract string GetResult();
        }

        // Implement the BuilderPascal, BuilderPyhton
        //   and BuilderC descendant classes
        public class BuilderPascal : Builder
        {
            string product = null;
            public override void BuildStart(char c)
            {
                base.BuildStart(c);
                product = product + Convert.ToString(c).ToLower();
            }
            public override void BuildFirstChar(char c) {
	        	product = product + Convert.ToString(c).ToUpper();
	        }
            public override void BuildNextChar(char c) {
                product = product + Convert.ToString(c).ToLower();
            }
            public override void BuildFirstSpace() {}
            public override string GetResult(){
                return product;
            }
        }

        public class BuilderPyhton : Builder
        {
            string product = null;
            public override void BuildStart(char c)
            {
                base.BuildStart(c);
                product = product + Convert.ToString(c).ToLower();
            }
            public override void BuildFirstChar(char c) {
	        	product = product + Convert.ToString(c).ToLower();
	        }
            public override void BuildNextChar(char c) {
                product = product + Convert.ToString(c).ToLower();
            }
            public override void BuildFirstSpace() {
                product = product + "_";
            }
            public override string GetResult(){
                return product;
            }
        }

        public class BuilderC : Builder
        {
            string product = null;
            public override void BuildStart(char c)
            {
                base.BuildStart(c);
                product = product + Convert.ToString(c).ToLower();
            }
            public override void BuildFirstChar(char c) {
	        	product = product + Convert.ToString(c).ToLower();
	        }
            public override void BuildNextChar(char c) {
                product = product + Convert.ToString(c).ToLower();
            }
            public override void BuildFirstSpace() {}
            public override string GetResult(){
                return product;
            }
        }

        public class Director
        {
            Builder b;
            public Director(Builder b)
            {
                this.b = b;
            }
            public string GetResult()
            {
                return b.GetResult();
            }
            public void Construct(string templat)
            {
                b.BuildStart(templat[0]);
                // Complete the implementation of the method
                for(int i = 1; i < templat.Length; i ++)
                {
                    if(templat[i]==' '&&templat[i-1]==' ')
                    {
                        continue;
                    }
                    else if(templat[i]==' '&&templat[i-1]!=' ')
                    {
                        b.BuildFirstSpace();
                    }
                    else if(templat[i]!=' '&&templat[i-1]==' ')
                    {
                        b.BuildFirstChar(templat[i]);
                    }
                    else{
                        b.BuildNextChar(templat[i]);
                    }
                }
            }
        }

        public static void Solve()
        {
            Task("OOP1Creat10");
            string[] str = new string[5];
            for(int i = 0; i < 5; i++){
                str[i] = GetString();
            }

             for (int i = 0; i < 5; i++)
            {
                Builder a = new  BuilderPascal();
                Builder b = new  BuilderPyhton();
                Builder c = new  BuilderC();
                Director d1 = new Director(a);
                Director d2 = new Director(b);
                Director d3 = new Director(c);
                
                d1.Construct(str[i]);
                d2.Construct(str[i]);
                d3.Construct(str[i]);
                Put(d1.GetResult(), d2.GetResult(), d3.GetResult());
                ShowLine(d1.GetResult());
                ShowLine(d2.GetResult());
                ShowLine(d3.GetResult());
            }
        }
    }
}
