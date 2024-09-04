// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.StringTokenizer;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner stdin = new Scanner(System.in);
		int t = stdin.nextInt();
		for(int test_case = 0; test_case<t;test_case++){
			int n = stdin.nextInt();
			int[] a = new int[n];
			for(int i =0;i<n;i++){
				a[i] = stdin.nextInt();
			}
			boolean ans = true;
			for(int i = 0; i<n-2;i++){
				if (a[i]<0){
					ans = false;
					break;
				}
				a[i+1]-=2*a[i];
				a[i+2]-=a[i];
				a[i] = 0;
			}
			ans = ans&&  (a[n-2] == 0&& a[n-1] == 0);


			System.out.println(ans?"YES":"NO");

		}
	}
}
