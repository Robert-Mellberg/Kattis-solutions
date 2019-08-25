import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.Math;

//https://open.kattis.com/submissions/3497479

public class classy implements Comparable<classy>{
    public classy(int värde, String namn)
    {
        värdePerson = värde;
        this.namn = namn;
    }
    public int värdePerson;
    public String namn;

    @Override
    public int compareTo(classy jämförelse) {
        if(värdePerson == jämförelse.värdePerson)
            return namn.compareTo(jämförelse.namn);
        else
            return jämförelse.värdePerson - värdePerson;

    }
    static FastReader sc;
    static HashMap<String, Integer>  värde;
    static List<classy> personer = new ArrayList<>();
    public static void main(String[] args)
    {
            värde = new HashMap<>();
            värde.put("lower", 1);
            värde.put("middle", 2);
            värde.put("upper", 3);
            sc = new FastReader();
            int testCases = sc.nextInt();
            for(int i = 0; i < testCases; i++)
                helper();
    }
    private static void helper()
    {
        int people = sc.nextInt();
        int value = 0;
        String namn = "";
        for(int i = 0; i <people; i++) {


            namn = sc.next();
            String klass = sc.next();
            sc.next();
            value = evaluate(klass);
            personer.add(new classy(value, namn));

        }
        Collections.sort(personer);
        for(classy pers : personer)
        {
            System.out.println(pers.namn.substring(0, pers.namn.length()-1));
        }
        System.out.println("==============================");
        personer.clear();

    }

    private static int evaluate(String klass)
    {
        String[] klasser = klass.split("-");
        int value = 0;
        for(int k = 0; k < 10-klasser.length; k++)
        {
            value += Math.pow(5, k)*2;
        }
        for(int l = 0; l < klasser.length; l++)
        {
            value += Math.pow(5, 10-klasser.length+l)*värde.get(klasser[l]);
        }
        return value;
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
