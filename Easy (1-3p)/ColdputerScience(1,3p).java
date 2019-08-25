import java.util.Scanner;

//https://open.kattis.com/problems/cold

public class Main
{
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int antal = sc.nextInt();
        int count = 0;
        for(int i = 0; i < antal; i++)
        {
            if(sc.nextInt() < 0)
            {
                count++;
            }
        }
        System.out.println(count);
    }
}
