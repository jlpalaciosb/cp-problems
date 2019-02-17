import java.util.Scanner;
import java.util.GregorianCalendar;
import java.util.Calendar;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = Integer.parseInt(sc.nextLine());

		for(int i = 1; i <= n; ++i) {
			String dateStr = sc.nextLine();
			int month = Integer.parseInt(dateStr.substring(0, 2));
			int day = Integer.parseInt(dateStr.substring(2, 4));
			int year = Integer.parseInt(dateStr.substring(4));

			GregorianCalendar gc = new GregorianCalendar(year, month - 1, day);

			gc.add(Calendar.WEEK_OF_MONTH, 40);

			month = gc.get(Calendar.MONTH) + 1;
			day = gc.get(Calendar.DAY_OF_MONTH);
			year = gc.get(Calendar.YEAR);
			System.out.println(
				"" + i + " " + 
				(month < 10 ? "0" : "") + month + "/" +
				(day < 10 ? "0" : "") + day + "/" +
				year + " " +
				getSign(month, day)
			);
		}
	}

	public static String getSign(int month, int day) {
		if(month == 1) {
			if(day < 21)
				return "capricorn";
			else
				return "aquarius";
		} else if(month == 2) {
			if(day < 20)
				return "aquarius";
			else
				return "pisces";
		} else if(month == 3) {
			if(day < 21)
				return "pisces";
			else
				return "aries";
		} else if(month == 4) {
			if(day < 21)
				return "aries";
			else
				return "taurus";
		} else if(month == 5) {
			if(day < 22)
				return "taurus";
			else
				return "gemini";
		} else if(month == 6) {
			if(day < 22)
				return "gemini";
			else
				return "cancer";
		} else if(month == 7) {
			if(day < 23)
				return "cancer";
			else
				return "leo";
		} else if(month == 8) {
			if(day < 22)
				return "leo";
			else
				return "virgo";
		} else if(month == 9) {
			if(day < 24)
				return "virgo";
			else
				return "libra";
		} else if(month == 10) {
			if(day < 24)
				return "libra";
			else
				return "scorpio";
		} else if(month == 11) {
			if(day < 23)
				return "scorpio";
			else
				return "sagittarius";
		} else if(month == 12) {
			if(day < 23)
				return "sagittarius";
			else
				return "capricorn";
		}
		return "undefined";
	}
}
