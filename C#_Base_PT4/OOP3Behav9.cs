// File: "OOP3Behav9"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public class OperationA
        {
            public static void ActionA()
            {
                Put("+A");
            }
            public static void UndoActionA()
            {
                Put("-A");
            }
        }

        public static class OperationB
        {
            public static void ActionB()
            {
                Put("+B");
            }
            public static void UndoActionB()
            {
                Put("-B");
            }
        }

        public static class OperationC
        {
            public static void ActionC()
            {
                Put("+C");
            }
            public static void UndoActionC()
            {
                Put("-C");
            }
        }

        public abstract class Command
        {
            public abstract void Execute();
            public abstract void Unexecute();
        }

        // Implement the CommandA, CommandB, CommandC
        //   and MacroCommand descendant classes

        public class CommandA : Command
        {
            public CommandA(){}

            public override void Execute()
            {
                OperationA.ActionA();
            }

            public override void Unexecute()
            {
                //throw new NotImplementedException();
                OperationA.UndoActionA();
            }
        }

        public class CommandB : Command
        {
            public CommandB(){}

            public override void Execute()
            {
                OperationB.ActionB();
            }

            public override void Unexecute()
            {
                //throw new NotImplementedException();
                OperationB.UndoActionB();
            }
        }

        public class CommandC : Command
        {
            public CommandC(){}

            public override void Execute()
            {
                OperationC.ActionC();
            }

            public override void Unexecute()
            {
                //throw new NotImplementedException();
                OperationC.UndoActionC();
            }
        }

        public class MacroCommand : Command
        {
            List<Command> V = new List<Command>();
            public MacroCommand(List<Command> v)
            {
                this.V = v;
            }

            public override void Execute()
            {
                //throw new NotImplementedException();
                foreach(Command e in V)
                {
                    e.Execute();
                }
            }

            public override void Unexecute()
            {
                //throw new NotImplementedException();
                for(int i = V.Count - 1; i >= 0; i--)
                    V[i].Unexecute();
            }
        }
        public class Menu
        {
            // Add required fields
            List<Command> availCmds = new List<Command>();
            List<Command> lastCmds = new List<Command>();
            int undoIndex = -1;
            public Menu(Command cmd1, Command cmd2)
            {
                // Implement the constructor
                availCmds.Add(cmd1);
                availCmds.Add(cmd2);

                List<Command> V = new List<Command>();
                V.Add(cmd1);
                V.Add(cmd2);

                Command cmd3 = new MacroCommand(V);
                availCmds.Add(cmd3);
            }
            public void Invoke(int cmdIndex)
            {
                // Implement the method
                Command cmd = availCmds[cmdIndex];
                cmd.Execute();

                int n = lastCmds.Count;
                undoIndex++;

                if(n > undoIndex)
                {
                    lastCmds.RemoveRange(undoIndex, n - undoIndex);
                }
                 lastCmds.Add(cmd);   
            }
            public void Undo(int count)
            {
                // Implement the method
                for (int i = 0; (i < count) && (undoIndex >= 0); i++) 
                {
                    lastCmds[undoIndex].Unexecute();
                    undoIndex--;
                }
            }
            public void Redo(int count)
            {
                // Implement the method
                for (int i = 0; (i < count) && (undoIndex + 1 < lastCmds.Count); i++) 
                {
                    undoIndex++;
                    lastCmds[undoIndex].Execute();
                }
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav9");
            char c1 = GetChar(), 
                 c2 = GetChar();

            Command C1 = null;
            Command C2 = null;

            if (c1 == 'A') C1 = new CommandA();
            if (c1 == 'B') C1 = new CommandB();
            if (c1 == 'C') C1 = new CommandC();

            if (c2 == 'A') C2 = new CommandA();
            if (c2 == 'B') C2 = new CommandB();
            if (c2 == 'C') C2 = new CommandC();

            Menu M = new Menu(C1, C2);

                int N = GetInt();
                
            for (int i = 0; i < N; i++) 
            {
                string str = GetString();
                if (str[0] == 'I') M.Invoke(str[1] - '0');
                if (str[0] == 'U') M.Undo(str[1] - '0');
                if (str[0] == 'R') M.Redo(str[1] - '0');
            }
        }
    }
}
