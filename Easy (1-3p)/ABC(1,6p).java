import java.util.Scanner;
import java.util.HashMap;
import java.util.*;

//https://open.kattis.com/problems/abc

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> hash = new HashMap<>();
        List<Integer> lista = new ArrayList<>();
        
        for(int i = 0; i < 3; i++)
        {
        lista.add(sc.nextInt());
        }
        Collections.sort(lista);
        hash.put("A", lista.get(0));
        hash.put("B", lista.get(1));
        hash.put("C", lista.get(2));
        String input = sc.next();
        
        System.out.println(hash.get(input.substring(0,1)) + " " + hash.get(input.substring(1,2)) + " " + hash.get(input.substring(2,3)));
        
    }
}
