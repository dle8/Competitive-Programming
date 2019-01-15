/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
/* Name of the class has to be "Main" only if the class is public. */
class test
{

	public static long max(long a, long b) {
		return (a >= b) ? a : b;
	}

	public static void main (String[] args) throws java.lang.Exception
	{
		// InputStream istream = System.in;
		OutputStream ostream = System.out;
		// Scanner in = new Scanner(istream);
		PrintWriter out = new PrintWriter(ostream);
		// solve(in, out);
		solve(out);
		out.close();
	}

	// public static void solve(Scanner in, PrintWriter out) { }
	public static void solve(PrintWriter out) {
		long res = 0;
		for (int a = 1; a <= 100; a++)
		for (int b = 1; b <= 100; b++) {
			BigInteger A = new BigInteger(String.valueOf(a));
			BigInteger P = A.pow(b);
			String p = String.valueOf(P);
			long len = p.length(), tmp = 0;
			for (int i = 0; i < len; i++) tmp += (p.charAt(i) - 48);
			res = max(res, tmp);
		}
		out.println(res);
	}
}
