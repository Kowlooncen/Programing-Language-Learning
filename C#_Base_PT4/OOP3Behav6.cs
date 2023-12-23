// File: "OOP3Behav6"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class AbstractComparable
        {
            public abstract int CompareTo(AbstractComparable other);

            // Implement the IndexMax, LastIndexMax, IndexMin
            //   and LastIndexMin static methods
            public static int IndexMax(AbstractComparable[] comp, int N)
            {
                int max = 0;

                for(int i = 0; i < N; i++)
                {
                    if((comp[max].CompareTo(comp[i])) < 0) 
                        max = i;
                }

                return max;
            }

            public static int LastIndexMax(AbstractComparable[] comp, int N)
            {
                int max = 0;

                for(int i = 0; i < N; i++)
                {
                    if((comp[max].CompareTo(comp[i])) < 0)
                        max = i;
                    if((comp[max].CompareTo(comp[i])) == 0)
                        max = i;
                }

                return max;
            }

            public static int IndexMin(AbstractComparable[] comp, int N)
            {
                int min = 0;
	
                for(int i = 0; i < N; i++)
                {
                    if((comp[min].CompareTo(comp[i])) > 0) 
                        min = i;
                }
                return min;
            }

            public static int LastIndexMin(AbstractComparable[] comp, int N)
            {
                int min = 0;
	
                for(int i = 0; i < N; i++)
                {
                    if((comp[min].CompareTo(comp[i])) > 0) min = i;
                    if((comp[min].CompareTo(comp[i])) == 0) min = i;
                }
                return min;
            }
        }

        // Implement the NumberComparable, LengthComparable
        //   and TextComparable descendant classes

        public class NumberComparable : AbstractComparable
        {
            int key;

            bool isDegital(string str)
            {
                if(str == "") return false;
                else {
                    for(int i = 0; i < str.Length; i++)
                    {
                        if(str[i] == '-'&& str.Length > 1)
                            continue;
                        if(str[i] > '9' || str[i] < '0')
                            return false;
                    }
                    return true;
                }
                
            }

            public NumberComparable(string data){
                if(isDegital(data))
                    key = Convert.ToInt32(data);
                else key = 0;
            }
            
            public override int CompareTo(AbstractComparable other)
            {
                NumberComparable pother = other as NumberComparable;
                if(this.key < pother.key) 
                    return -1;
                else if(this.key == pother.key) 
                    return 0;
                else return 1; 
            }
        }

        public class LengthComparable : AbstractComparable
        {
            int key;
            public LengthComparable(string data){
                key = data.Length;
            }
            public override int CompareTo(AbstractComparable other)
            {
                LengthComparable pother = other as LengthComparable;
                if(this.key < pother.key) 
                    return -1;
                else if(this.key == pother.key) 
                    return 0;
                else return 1;
            }
        }

        public class TextComparable  : AbstractComparable
        {
            string key = null;
            public TextComparable (string data){
                key = data;
            }
            public override int CompareTo(AbstractComparable other)
            {
                TextComparable  pother = other as TextComparable;
                return String.CompareOrdinal(this.key, pother.key);

            }
        }


        public static void Solve()
        {
            Task("OOP3Behav6");
            int N = GetInt(),
                K = GetInt();

            string str1, str2;

            for(int i = 0; i < K; i++)
            {
                AbstractComparable[] comp = new AbstractComparable[9];
                str1 = GetString();
                for(int j = 0; j < N; j++)
                {
                    str2 = GetString();
                    Show("OK");
                    if(str1 == "N")
                    {
                        comp[j] = new NumberComparable(str2);
                    }
                     if (str1 == "L")
                    {
                        comp[j] = new LengthComparable(str2);
                    }
                    if (str1 == "T")
                    {
                        comp[j] = new TextComparable(str2);
                    }
                }
                int x = AbstractComparable.IndexMax(comp, N);
                int y = AbstractComparable.LastIndexMax(comp, N);
                int m = AbstractComparable.IndexMin(comp, N);
                int n = AbstractComparable.LastIndexMin(comp, N);
                
                Put(x, y, m, n);
            }
        }
    }
}
