package calculator;
import java.util.Scanner;
public class Calculator {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		System.out.print("Enter two numbers ");
		double first = reader.nextDouble();
		double second = reader.nextDouble();
		System.out.print("Enter an operator: +,- ");
		char operator = reader.next().charAt(0);
		double result;
		switch(operator)
		{
		case '+':
			result = first+second;
		break;
		case '-':
			result = first-second;
		break;
		
		default:
			System.out.println("No matching operators found");
			return;
		}
		
		System.out.printf("%f", result);
		
		
	}

}
