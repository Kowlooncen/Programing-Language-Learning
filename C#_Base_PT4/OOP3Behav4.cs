// File: "OOP3Behav4"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public class Validator
        {
            public virtual string Validate(string s)
            {
                return "";
            }
        }

        // Implement the EmptyValidator, NumberValidator
        //   and RangeValidator descendant classes
        /////
        ///

        public class EmptyValidator : Validator
        {
            public EmptyValidator(){}
            public override string Validate(string s)
            {
                if(string.IsNullOrEmpty(s)) return "!Empty text";
                return "";
            }
        }

        public class NumberValidator : Validator
        {
            public NumberValidator(){}
            public override string Validate(string s)
            {
                string str = "";
                if(s != "")
                {
                    int k = 0;
                    for(int i = 0; i < s.Length; i++)
                    {
                        if(s[i] != '-' && (s[i] < '0' || s[i] > '9'))
                        {
                            k = 1;
                            break;
                        }
                    }
                    if(k == 0) str = "";
                    else str = "!'" + s + "': not a number";
                }
                else str = "!'" + s + "': not a number";
                return str;
            }
        }

        public class RangeValidator : Validator
        {
            int my_min, my_max;
            public RangeValidator(){}
            public RangeValidator(int a, int b)
            {
                this.my_min = Math.Min(a,b);
                this.my_max = Math.Max(a,b);
            }
            public override string Validate(string s)
            {
                string str = "";
                if(s != "")
                {
                    int k = 0;
                    for(int i = 0; i < s.Length; i++)
                    {
                        if(s[i] != '-' && (s[i] < '0' || s[i] > '9'))
                        {
                            k = 1;
                            break;
                        }
                    }
                    if(k == 0)
                    {
                        int x = int.Parse(s);
                        if ((x >= my_min) && (x <= my_max)) 
                            str = "";
                        else 
                            str = "!'" + s + "': not in range " + Convert.ToString(my_min) + ".." + Convert.ToString(my_max);
                    }
                    else{
                        str = "!'" + s + "': not in range " + Convert.ToString(my_min) + ".." + Convert.ToString(my_max);
                    }
                }
                else{
                    str = "!'" + s + "': not in range " + Convert.ToString(my_min) + ".." + Convert.ToString(my_max);
                }         
                return str;
            }
        }

        // Implement the TextBox and TextForm classes

        public class TextBox
        {
            string text = "";
            Validator v = new Validator();
            public TextBox(){}
            public void SetText(string text)
            {
                this.text = text;
            }
            public void SetValidator(Validator v)
            {
                this.v = v;
            }
            public string Validate()
            {
                return v.Validate(text);
            }
        }

        public class TextForm 
        {
            List<TextBox> V = new List<TextBox>();
            string info = "";
            public TextForm(int m)
            {
                for(int i = 0; i < m; i++)
                {
                    TextBox tb = new TextBox();
                    V.Add(tb);
                }
            }
            public void SetText(int ind, string text)
            {
                V[ind].SetText(text);
            }

            public void SetValidator (int ind, Validator v)
            {
                V[ind].SetValidator(v);
            }

            public string Validate()
            {
                foreach(TextBox i in V)
                {
                    info = info + i.Validate();
                }
                return info;
            }
        }
        public static void Solve()
        {
            Task("OOP3Behav4");
            int N = GetInt(),
                A = GetInt(),
                B = GetInt(),
                K = GetInt();

            int[] v1 = new int [K];
            char[] v2 = new char [K]; 

            for (int i = 0; i < K; i++) {
                int ind = GetInt();
                char val = GetChar();
                v1[i] = ind;
                v2[i] = val;
            }

            for(int i = 0; i < 5; i++)
            {
                TextForm tf = new TextForm (N);
                for(int j = 0; j < N; j++)
                {
                    string s = GetString();
                    tf.SetText(j, s);
                }
                Validator v = new Validator();
                for(int k = 0; k < K; k++)
                {
                    if(v2[k] == 'E') 
                    {
                        Show("empty");
                        v = new EmptyValidator();
                    }
                    if(v2[k] == 'N') 
                    {
                        v = new NumberValidator();
                        Show("number");
                    }
                    if(v2[k] == 'R') 
                    {
                        v = new RangeValidator(A, B);
                        Show("range");
                    }
                    
                    tf.SetValidator(v1[k], v);
                }
                 
                ShowLine(tf.Validate());
                string str = tf.Validate();
                string info = "";
                for(int n = 0; n < str.Length/2; n++)
                {
                    info = info + str[n];
                }
                Put(info);
                // ShowLine(info.Length);
            }
        }
    }
}
