// File: "OOP1Creat6"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class BaseClass
        {
            int data = 0;
            public void IncData(int increment)
            {
                data += increment;
            }
            public int GetData()
            {
                return data;
            }
        }

/*Он включает статическое поле uniqueInstance — ссылку на тип Singleton (инициализируется нулевой ссылкой), 
закрытый конструктор без параметров, не выполняющий дополнительных действий, и статический метод Instance (без параметров, возвращает ссылку на тип Singleton). 
Метод Instance выполняет следующие действия: если поле uniqueInstance является нулевой ссылкой, то метод создает объект Singleton, помещает ссылку на него в поле uniqueInstance и возвращает эту ссылку как результат своей работы; если поле uniqueInstance уже содержит ссылку на объект Singleton, то метод Instance просто возвращает эту ссылку. 
Дополнительно реализовать статический метод InstanceCount (без параметров), 
который возвращает 0, если поле uniqueInstance содержит нулевую ссылку, и 1 в противном случае.*/
        public class Singleton : BaseClass
        {
            static Singleton uniqueInstance ;//为什么要加static, 是因为可以在整个class里使用这个对象
            Singleton() {}
            public static void Reset()
            {
                uniqueInstance = null;
            }
            // Complete the implementation of the class
            public static Singleton Instance(){
                if (uniqueInstance == null)
                    uniqueInstance = new Singleton();
                return uniqueInstance;
            }
            public static int InstanceCount(){
                if(uniqueInstance == null) 
                    return 0;
                else return 1;
            }
        }
        
        public class Doubleton : BaseClass
        {
            static Doubleton[] instances = new Doubleton[2];
            Doubleton() {}
            public static void Reset()
            {
                instances[0] = instances[1] = null;
            }
            // Complete the implementation of the class
            public static Doubleton Instance1(){
                if(instances[0]==null)
                    instances[0] = new Doubleton();
                return instances[0];
            }

            public static Doubleton Instance2(){
                if(instances[1]==null)
                    instances[1] = new Doubleton();
                return instances[1];
            }

            public static int InstanceCount(){
                int count = 0;
                for(int i = 0; i < 2; i++)
                {
                    if (instances[i] != null)
                        count++;
                }
                return count;
            }
        }

        public class Tenton : BaseClass
        {
            static Tenton[] instances = new Tenton[10];
            Tenton() {}
            public static void Reset()
            {
                for (int i = 0; i < instances.Length; i++)
                    instances[i] = null;
            }
            // Complete the implementation of the class
            public static Tenton Instance(int x)
            {
                if(x < 0 || x > 9)
                    return null;
                else{
                    if(instances[x] == null)
                        instances[x] = new Tenton();
                    return instances[x];
                }
            }

            public static int InstanceCount()
            {
                int count = 0;
                for(int  j = 0; j < 10; j++)
                {
                    if(instances[j] != null)
                    {
                        ShowLine(j, count);
                        count ++;
                    }
                }
                return count;
            }
        }

        public static void Solve()
        {
            Task("OOP1Creat6");
            Singleton.Reset();
            Doubleton.Reset();
            Tenton.Reset();

            int N = GetInt();
            string[] array1 = new string [N]; 
            for(int i = 0; i < N; i++)
            {
                array1[i] = GetString();
            }

            BaseClass[] b = new BaseClass [N];

             for (int i = 0; i < N; i++)
            {
                switch (array1[i][0])
                {
                case 'S':
                {
                    b[i] = Singleton.Instance();
                    Show("S ");
                    break;
                }
                case 'D':
                {
                    if (array1[i][1] == '1')
                        b[i] = Doubleton.Instance1();
                    else b[i] = Doubleton.Instance2();
                    Show("D ");
                    break;
                }
                case 'T':
                {
                    b[i] = Tenton.Instance(array1[i][1] - '0');
                    Show("T ", array1[i][1] - '0');

                    break;
                }
                default:
                    break;
                }
            }
            //Show(Tenton.InstanceCount());
            Put(Singleton.InstanceCount() , Doubleton.InstanceCount() , Tenton.InstanceCount());
            Show('\n');
            int K = GetInt();

            int[] array2 = new int [K];
            int[] array3 = new int [K];

            for (int i = 0; i < K; i++)
            {
                array2[i] = GetInt();
                array3[i] = GetInt();
            }

             for (int i = 0; i < K; i++)
            {
                (b[array2[i]]).IncData(array3[i]);
            }
            for (int i = 0; i < N; i++)
            {
                Put((b[i]).GetData());
            }

        }
    }
}
