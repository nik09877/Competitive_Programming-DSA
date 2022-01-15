import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Lokesh Khandelwal
 */
public
class Main
{
public
    static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD
{
public
    /*
Firstly lets create a position array for each sequence and call it pos[k][n]. In this array we store the positions of each of the n numbers (from 1 to n) to know where they occur in each of the sub sequences.

Now the dp solutions starts. dp[i] marks the maximum length common sequence we can generate by using the first i elements of the first sequence. For this we iterate over all possible previous numbers (j) and see if we can extend dp[j] to dp[i]. This can be done only when positions of number a[j] is less than positions of a[i] for each of the sequence. Then we can extend j to i. Finally we take the maximum of values in dp array. Refer to my solution in the contest
    */
    void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n = in.nextInt(), k = in.nextInt(), i, j, p;
        int a[][] = new int[k][n];
        int pos[][] = new int[k][n];
        for (i = 0; i < k; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = in.nextInt();
                pos[i][a[i][j] - 1] = j;
            }
        }
        int dp[] = new int[n], ans = 1;
        for (i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (j = 0; j < i; j++)
            {
                boolean status = true;
                for (p = 0; p < k; p++)
                {
                    if (pos[p][a[0][j] - 1] <= pos[p][a[0][i] - 1])
                    {
                    }
                    else
                    {
                        status = false;
                    }
                }
                if (status)
                {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    ans = Math.max(ans, dp[i]);
                }
            }
        }
        out.printLine(ans);
    }
}

class InputReader
{
    BufferedReader in;
    StringTokenizer tokenizer = null;

public
    InputReader(InputStream inputStream)
    {
        in = new BufferedReader(new InputStreamReader(inputStream));
    }
public
    String next()
    {
        try
        {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                tokenizer = new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
public
    int nextInt()
    {
        return Integer.parseInt(next());
    }
}

class OutputWriter
{
private
    final PrintWriter writer;

public
    OutputWriter(OutputStream outputStream)
    {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

public
    OutputWriter(Writer writer)
    {
        this.writer = new PrintWriter(writer);
    }

public
    void print(Object... objects)
    {
        for (int i = 0; i < objects.length; i++)
        {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

public
    void printLine(Object... objects)
    {
        print(objects);
        writer.println();
    }

public
    void close()
    {
        writer.close();
    }
}