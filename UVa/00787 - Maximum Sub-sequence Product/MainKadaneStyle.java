import java.util.Scanner;
import java.math.BigInteger;

class Main {
	static BigInteger max(BigInteger bi1, BigInteger bi2) {
		return bi1.compareTo(bi2) > 0 ? bi1 : bi2;
	}

	static BigInteger max(BigInteger bi1, BigInteger bi2, BigInteger bi3) {
		BigInteger maximum = bi1;
		if (bi2.compareTo(maximum) > 0) maximum = bi2;
		if (bi3.compareTo(maximum) > 0) maximum = bi3;
		return maximum;
	}

	static BigInteger min(BigInteger bi1, BigInteger bi2, BigInteger bi3) {
		BigInteger minimum = bi1;
		if (bi2.compareTo(minimum) < 0) minimum = bi2;
		if (bi3.compareTo(minimum) < 0) minimum = bi3;
		return minimum;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a;
		BigInteger ans, prev_min, prev_max, curr_min, curr_max, abig, prod1, prod2;

		while (sc.hasNextInt()) {
			ans = prev_min = prev_max = curr_min = curr_max = BigInteger.valueOf(sc.nextInt());

			while (true) {
				a = sc.nextInt();
				if (a == -999999) break;
				abig = BigInteger.valueOf(a);
				prod1 = abig.multiply(prev_min);
				prod2 = abig.multiply(prev_max);
				curr_min = min(abig, prod1, prod2);
				curr_max = max(abig, prod1, prod2);
				ans = max(ans, curr_max);
				prev_min = curr_min;
				prev_max = curr_max;
			}

			System.out.println(ans);
		}
	}
}
