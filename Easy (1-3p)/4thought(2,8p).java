import javax.script.*;
import java.util.Scanner;
import java.util.HashMap;

//https://open.kattis.com/problems/4thought

public class statue
{
  static char[] operator = new char[] {'+', '-', '*', '/'};

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);


    HashMap<Integer, String> värden = new HashMap<>();
    värden.put(4, "4 + 4 / 4 / 4 = 4");
    värden.put(-4, "4 / 4 / 4 - 4 = -4");

    ScriptEngineManager scm = new ScriptEngineManager();
    ScriptEngine jsEngine = scm.getEngineByName("JavaScript");
    for(int oper1 = 0; oper1 < 4; oper1++)
    {
      for(int oper2 = 0; oper2 < 4; oper2++)
      {
        for(int oper3 = 0; oper3 < 4; oper3++)
        {
          try
          {
            Object obj = jsEngine.eval("4"+operator[oper1]+"4"+operator[oper2]+"4"+operator[oper3]+"4");
            if((oper1 == 3 && oper2 == 3) || (oper3 == 3 && oper2 == 3))
            {
              continue;
            }
            värden.put((int)obj, "4 " + operator[oper1] + " 4 " + operator[oper2] + " 4 " + operator[oper3] + " 4 " + "= " + obj);
          }
          catch(Exception e)
          {
              System.out.println(e.toString());
          }
        }
      }
    }
    int antal = sc.nextInt();
    for(int i = 0; i < antal; i++)
    {
      String lösning =värden.get(sc.nextInt());
      if(lösning != null)
      {
        System.out.println(lösning);
      }
      else
      {
        System.out.println("no solution");
      }
    }

    sc.close();

  }
}
