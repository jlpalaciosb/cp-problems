import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		int[] arr = new int[100];
		Scanner sc = new Scanner(System.in);

		while (sc.hasNextInt()) {
			BigInteger ans = new BigInteger("-100000");

			boolean hayCero = false; // parche! no funcionaba para -1 0 -1 (ignoraba el cero)

			while (true) {
				int len = 0;
				boolean last = false;
				int nc = 0, fni = -1, lni = -1; boolean fnf = false;
				while (true) {
					int a = sc.nextInt();

					if (a == 0) hayCero = true; // !

					if (a < 0 && a != -999999) {
						nc++;
						if (!fnf) { fnf = true; fni = len; }
						lni = len;
					}
					if (a == -999999) last = true;
					if (a == 0 || a == -999999) break;
					arr[len++] = a;
				}

				BigInteger subAns;
				if (nc % 2 == 0) {
					if (len == 0) {
						subAns = BigInteger.valueOf(0);
					} else {
						subAns = BigInteger.valueOf(1);
						for (int i = 0; i < len; i++) {
							subAns = subAns.multiply(BigInteger.valueOf(arr[i]));
						}
					}
				} else {
					if (len == 1) {
						subAns = BigInteger.valueOf(arr[0]);
					} else {
						BigInteger lp = BigInteger.valueOf(lni == 0 ? 0 : 1);
						for (int i = 0; i < lni; i++) {
							lp = lp.multiply(BigInteger.valueOf(arr[i]));
						}

						BigInteger rp = BigInteger.valueOf(fni == len - 1 ? 0 : 1);
						for (int i = len - 1; i > fni; i--) {
							rp = rp.multiply(BigInteger.valueOf(arr[i]));
						}

						if (lp.compareTo(rp) > 0) subAns = lp;
						else subAns = rp;
					}
				}

				if (ans.compareTo(subAns) < 0) ans = subAns;

				if (last) break;
			}

			if (hayCero && ans.compareTo(BigInteger.valueOf(0)) < 0) // !
				System.out.println(0);
			else
				System.out.println(ans);
		}
	}
}

// creo que hay una solución mas elegante, parecido al algoritmo de Kadane
