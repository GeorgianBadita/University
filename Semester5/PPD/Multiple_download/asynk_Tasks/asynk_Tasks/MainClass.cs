using System;
using System.Collections.Generic;

namespace asynk_Tasks
{
    public class MainClass
    {
        private static List<String> hts = new List<String>();

        public static void Main(string[] args)
        {
            hts.Add("www.cs.ubbcluj.ro/~rlupsa/edu/pdp");
            hts.Add("facebook.com");
            hts.Add("google.com");

            TaskMechanism.run(hts);
        }
    }
}