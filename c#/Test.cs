using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace CoreTest
{
    class Program
    {
        static IEnumerable<Tuple<string, double>> GetValues(int amount = 10)
        {
            var a = from it in Range(amount)
                    let t = new Tuple<string, double>(it.ToString(), it)
                    select t;
            return a;
        }
        static void Main(string[] args)
        {
            const int tests_amount = 10;
            Stopwatch stopwatch = new Stopwatch();
            long time_total = 0;
            for (int i = 0; i < tests_amount; ++i)
            {
                stopwatch.Start();
                double sum = 0;
                foreach(var item in GetValues(10_000_000))
                {
                    sum += item.Item2;
                }
                stopwatch.Stop();
                Console.WriteLine(sum);
                time_total += stopwatch.ElapsedMilliseconds;
                Console.WriteLine($"Elapsed {stopwatch.ElapsedMilliseconds} ms.");
                stopwatch.Reset();
            }
            Console.WriteLine("Mean: {0} ms.", (double)time_total / tests_amount);
            Console.ReadLine();
        }

        static IEnumerable<double> Range(double begin, double end = 0, double step = 1)
        {
            if(end == 0)
            {
                end = begin;
                begin = 0;
            }

            for(double i = begin; i < end; i += step)
            {
                yield return i;
            }
        }
    }
}
