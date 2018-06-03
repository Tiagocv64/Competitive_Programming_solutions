import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;


class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int pred,d,m,y;
		pred = sc.nextInt(); d = sc.nextInt(); m = sc.nextInt(); y = sc.nextInt();
		while (pred != 0 || d != 0 || m != 0 || y != 0){
	
			Calendar c = new GregorianCalendar(y,m-1,d);
			c.add(Calendar.DAY_OF_MONTH, pred);
			System.out.println(c.get(Calendar.DAY_OF_MONTH) + " " + (c.get(Calendar.MONTH)+1) + " " + c.get(Calendar.YEAR));
	
			pred = sc.nextInt(); d = sc.nextInt(); m = sc.nextInt(); y = sc.nextInt();
		}
		sc.close();
	}
}
