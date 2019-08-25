import java.util.ArrayList;
import java.util.Scanner;
import java.lang.Math;
//https://open.kattis.com/submissions/3492117

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String namn = sc.next();
        ArrayList<Character> lista = new ArrayList();
        char oldChar = namn.toCharArray()[0];
        lista.add(oldChar);
        for(char c: namn.toCharArray())
        {
            if(c == oldChar)
            {
              continue;
            }
            lista.add(c);
            oldChar = c;
        }

        char[] nylista = new char[lista.size()];
        for(int i = 0; i < lista.size(); i++)
        {
          nylista[i] = lista.get(i);
        }
        System.out.println(String.valueOf(nylista));
    }
}
