import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;
import java.util.Calendar;
import java.util.Scanner;

class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t, cur = 1;
		t = sc.nextInt();
		int [] days = {21,20,21,21,22,22,23,22,24,24,23,23};
		String [] signs = { "capricorn", "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};
		while (cur <= t){
			int n = sc.nextInt();
			Calendar date = new GregorianCalendar(n%10000 ,n/1000000-1, n/10000%100);
			date.add(Calendar.WEEK_OF_YEAR, 40);
			Calendar dateTest = (Calendar) date.clone();
			int m = 0;
			for (int i = 0; i < 12; i++){
				dateTest.set(Calendar.MONTH, m);
				dateTest.set(Calendar.DAY_OF_MONTH, days[i]);
				if (dateTest.after(date))
					break;
				m++;
			}
			SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy");
			System.out.println(cur + " " + sdf.format(date.getTime()) + " "  + signs[m]);

			cur++;
		}

	}
}